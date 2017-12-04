/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:03:24 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/04 16:39:59 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

char		**ft_reader(char *av)
{
	char		**str;
	int			fd;
	int			len;
	char		buff[BUFF_SIZE + 1];

	len = 0;
	fd = open(av, O_RDONLY);
	len = read(fd, buff, BUFF_SIZE);
	buff[len] = '\0';
	str = ft_strsplit(buff, '\n');
	close(fd);
	return (str);
}
