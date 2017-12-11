/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:21:34 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/11 15:45:30 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line(t_mlx mlx, t_point point, int z)
{
	double	tx;
	float	dx;
	float	dy;
	double	x;
	double	y;

	tx = 0.0;
	dx = (float)point.x2 - point.x1;
	dy = (float)point.y2 - point.y1;
	while (tx <= 1)
	{
		x = point.x1 + (dx * tx);
		y = point.y1 + (dy * tx);
		if (z > 5)
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, WHITE);
		else if (z > 2)
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, ORANGE);
		else if (z >= 0)
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, GREEN);
		else
			mlx_pixel_put(mlx.mlx, mlx.win, x, y, BLUE);
		tx += 1. / sqrt((dx * dx) + (dy * dy));
	}
}

static void	ft_segment_horiz(t_mlx mlx, t_point point, int x, int y)
{
	int startx;
	int	starty;
	int zoom;

	zoom = point.zoom;
	startx = point.x_move;
	starty = point.y_move;
	point.x1 = startx + (x - y) * zoom;
	point.y1 = starty + (x + y) * zoom / point.z - (point.tab[y][x] * 20);
	point.x2 = startx + ((x + 1) - y) * zoom;
	point.y2 = starty + ((x + 1) + y) * zoom / point.z - \
			(point.tab[y][x + 1] * 20);
	ft_draw_line(mlx, point, point.tab[y][x]);
}

static void	ft_segment_vert(t_mlx mlx, t_point point, int x, int y)
{
	int startx;
	int	starty;
	int zoom;

	zoom = point.zoom;
	startx = point.x_move;
	starty = point.y_move;
	point.x1 = startx + (x - y) * zoom;
	point.y1 = starty + (x + y) * zoom / point.z - (point.tab[y][x] * 20);
	point.x2 = startx + (x - (y + 1)) * zoom;
	point.y2 = starty + (x + (y + 1)) * zoom / \
			point.z - (point.tab[y + 1][x] * 20);
	ft_draw_line(mlx, point, point.tab[y][x]);
}

void		ft_draw(t_point *point, t_tools tools, t_mlx mlx)
{
	int y;
	int x;

	y = 0;
	while (y < tools.nb_line)
	{
		x = 0;
		while (x < tools.nb_int - 1)
		{
			ft_segment_horiz(mlx, *point, x, y);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < tools.nb_line - 1)
	{
		x = 0;
		while (x < tools.nb_int)
		{
			ft_segment_vert(mlx, *point, x, y);
			x++;
		}
		y++;
	}
}
