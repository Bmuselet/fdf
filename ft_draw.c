/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:40:43 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/01 17:57:14 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>

static void	ft_2Dto3D(int *x, int *y, int z)
{
	int X;
	int Y;
	int cst;

	cst = z;
	X = *x + 64;
	Y = *y + 32;
//	X = *x - *y;
//	Y = (*x + *y) / 2;
//	X = (cst * *x) - (cst * *y);
//	Y = z + ((cst / 2) * *x) + ((cst / 2) * *y);
	*x = X;
	*y = Y;
}

static void	ft_draw_line2(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int		x;
	int		y;
	int		k;
	int		i;

	y = y1;
	i = 0;
	k = WIN_WIDTH;
	while (y == y2 && i < (WIN_WIDTH / 20))
	{	
			mlx.img.data[x1 + ((y1 + (y2-y1) * (x - x1))/(x2 - x1) * (WIN_WIDTH * (WIN_HEIGHT / 20))) + k] = GREEN;
			k = k + WIN_WIDTH;
			i++;
	}
}

static void	ft_draw_line(t_mlx mlx, int x1, int y1, int x2, int y2)
{
	int		x;
	int		y;

	x = x1;
	while (x <= x2)
	{
		mlx.img.data[x + ((y1 + (y2-y1)*(x - x1))/(x2 - x1) * (WIN_WIDTH * (WIN_HEIGHT / 20)))] = WHITE;
		x++;
	}
}

void		ft_draw(t_mlx mlx, t_point *point)
{
	int		count_width;
	int		count_height;
	int		i;
	int		j;

	j = 1;
	count_height = -1;
	ft_2Dto3D(&point->x, &point->y, point->z);
	while (++count_height < WIN_HEIGHT)
	{
		count_width = -1;
		while (++count_width < WIN_WIDTH)	
		{
			if (point->next != NULL)
			{
			//	ft_2Dto3D(&point->next->x, &point->next->y, point->next->z);
				mlx.img.data[(point->y * (WIN_WIDTH * (WIN_HEIGHT / 20)) + (point->x * WIN_WIDTH / 20))] = WHITE;
	//			ft_draw_line(mlx, (point->x * WIN_HEIGHT / 20), (point->y * WIN_WIDTH / 20), (point->next->x * WIN_HEIGHT / 20), (point->next->y * WIN_WIDTH / 20));
	//			ft_draw_line2(mlx, (point->x * WIN_HEIGHT / 20), (point->y * WIN_WIDTH / 20), (point->next->x * WIN_HEIGHT / 20), (point->next->y * WIN_WIDTH / 20));
				point = point->next;
			}
			else
				mlx.img.data[(point->y * (WIN_HEIGHT / 20)) * WIN_WIDTH + (point->x * WIN_WIDTH / 20)] = 0x000000;
		}
	}
}



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
