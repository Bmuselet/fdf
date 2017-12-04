/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:32:29 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/04 16:40:53 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>

t_point	*new_point2(int x, int y, int z, t_mlx mlx)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	p->z = z;
	p->next = NULL;
	return (p);
}

void	new_point(int x, int y, int z, t_mlx mlx)
{
	t_point	*p;
	t_point	*tmp;

	p = new_point2(x, y, z, mlx);
	tmp = mlx.point;
	if (tmp == NULL)
	{
		mlx.point = p;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = p;
}

void read_point(char **line, int *x, int y, t_mlx mlx)
{
	int		z;

	z = ft_atoi(*line);
	if (z < 0)
	{
		(*line)++;
		z = -z;
	}
	while (z > 9)
	{
		z = z / 10;
		(*line)++;
	}
	(*line)++;
	new_point(*x, y, z, mlx);
}

int		read_file(int fd, t_mlx mlx)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		while (*line != '\0')
		{
			if (*line == ' ')
				line++;
			else
			{
			//	if (*line != '-' && (*line < '0' || *line > '9'))
			//		return (0);
				read_point(&line, &x, y, mlx);
			}
		}
	}
	return (1);
}

int		ft_reader3(char *av, t_mlx mlx)
{
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	return (read_file(fd, mlx));
}

