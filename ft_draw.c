/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:40:43 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/01 12:14:21 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>

void	ft_draw_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int		x;
	int		y;
	double	a;
	double	b;

	a = (double) (y2 - y1) / (x2- x1);
	b = y1 - a * x1;
	x = x1;
	while (x < x2)
	{
	//	y = (int) (a * x + b);
	//	mlx.img.data[x + WIN_WIDTH * y] = WHITE;
		mlx.img.data[x + (y1 + (y2-y1)*(x - x1))/(x2 - x1)] = WHITE;
		x++;
	}
}

void	ft_draw(t_mlx mlx, t_point *point)
{
	int		count_width;
	int		count_height;
	int		i;
	int		j;

	j = 1;
	count_height = -1;
	while (++count_height < WIN_HEIGHT)
	{
		count_width = -1;
		while (++count_width < WIN_WIDTH)	
		{
			if (point->next != NULL)
			{
				mlx.img.data[(point->y * (WIN_HEIGHT / 20)) * WIN_WIDTH + (point->x * WIN_WIDTH / 20)] = GREEN;
				ft_draw_line(mlx, (point->x * WIN_HEIGHT / 20), (point->y * WIN_WIDTH / 20), (point->next->x * WIN_HEIGHT / 20), (point->next->y * WIN_WIDTH / 20));
/*				if (point->next->x > point->x)
				{
					i = (point->x * (WIN_WIDTH / 10));
					while (i < (point->next->x * (WIN_WIDTH / 10)))
					{
					//	mlx.img.data[(point->y * (WIN_HEIGHT / 10) + (j * WIN_WIDTH))] = 0xFF00FF;
						i++;
					//	j++;
					}
				}
//				if (point->next->y)
//				{
//					while (j < (WIN_WIDTH * (WIN_HEIGHT / 10)))
//					{
//						printf("A");
//						mlx.img.data[(point->y * (WIN_WIDTH * (WIN_HEIGHT / 10)) + j)] = 0xFF00FF;
//						j = j + WIN_WIDTH;
//					}
				}*/
				point = point->next;
			}
			else
				mlx.img.data[(point->y * (WIN_HEIGHT / 20)) * WIN_WIDTH + (point->x * WIN_WIDTH / 20)] = 0x000000;
		}
	}
}
