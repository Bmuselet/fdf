/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:03:24 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/07 12:24:24 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

#include "fdf.h"

int			ft_strlen_fdf(char *str)
{
	int		i;
	int 	nb_int;

	i = 0;
	nb_int = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '-')
			i++;
		if (ft_isdigit(str[i]) == 1)
		{
			nb_int++;
			i++;
			while (ft_isdigit(str[i + 1]) == 1)
				i++;
		}
	}
	return (nb_int);
}

int			ft_check_read(int argc, char *argv, int *fd)
{
	if (argc < 1)
	{
		ft_putstr("usage: ./FdF input_file\n");
		return (0);
	}
	if ((*fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr("error : bad_file\n");
		return (0);
	}
	if (BUFF_SIZE <= 0)
	{
		ft_putstr("error : BUFF_SIZE\n");
		return (0);
	}
	return (1);
}

int		ft_reader(int argc, char *argv, t_tools *tools)
{
	int		fd;
	char	*line;

	tools->str = ft_strnew(1);
	if (ft_check_read(argc, argv, &fd) == 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		tools->str = ft_strjoin(ft_strjoin(tools->str, line), "\n");
		tools->nb_line++;
	}
	tools->content = ft_strsplit(tools->str, '\n');
	if (get_next_line(fd, &line) < 0)
	{
		ft_putstr("error : get_next_line\n");
		free(tools->str);
		return (0);
	}
	tools->nb_int = ft_strlen_fdf(tools->content[0]);
	if (close(fd) == -1)
	{
		ft_putstr("error : file\n");
		return (0);
	}
	return (1);
}
