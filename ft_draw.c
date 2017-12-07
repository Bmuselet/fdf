/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:21:34 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/07 13:35:37 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_mlx mlx, t_point point)
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
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, ORANGE);
		tx += 1. / sqrt((dx * dx) + (dy * dy));
	}
}

void	ft_segment_horiz(t_mlx mlx, t_point point, int x, int y)
{
	int startx;
	int	starty;
	int pas;

	pas = WIN_WIDTH / 205;
	startx = WIN_WIDTH / 3;
	starty = WIN_HEIGHT / 2;
	point.x1 = startx + (x * pas) - (y * pas);
	point.y1 = starty + (x * pas / 4) + (y * pas / 4) - (point.tab[y][x] * 20);
	point.x2 = startx + ((x + 1) * pas) - (y * pas);
	point.y2 = starty + ((x + 1) * pas / 4) + (y * pas / 4) - \
			(point.tab[y][x + 1] * 20);
	ft_draw_line(mlx, point);
}

void	ft_segment_vert(t_mlx mlx, t_point point, int x, int y)
{
	int startx;
	int	starty;
	int pas;

	pas = WIN_WIDTH / 205;
	startx = WIN_WIDTH / 3;
	starty = WIN_HEIGHT / 2;
	point.x1 = startx + (x * pas) - (y * pas);
	point.y1 = starty + (x * pas / 4) + (y * pas / 4) - (point.tab[y][x] * 20);
	point.x2 = startx + (x * pas) - ((y + 1) * pas);
	point.y2 = starty + (x * pas / 4) + ((y + 1) * pas / 4) - \
			(point.tab[y + 1][x] * 20);
	ft_draw_line(mlx, point);
}

void	ft_draw(t_point *point, t_tools tools, t_mlx mlx)
{
	int i;
	int y;
	int x;

	y = 0;
	while (tools.content[y] != 0)
	{
		i = 0;
		x = 0;
		while (tools.content[y][i] != '\0')
		{
			while (tools.content[y][i] == ' ' || tools.content[y][i] == '-')
				i++;
			if (ft_isdigit(tools.content[y][i]) == 1)
			{
				if (tools.content[y][i + 1] != '\0')
					ft_segment_horiz(mlx, *point, x, y);
				if (tools.content[y + 1] != 0)
					ft_segment_vert(mlx, *point, x, y);
				x++;
				i++;
				while (ft_isdigit(tools.content[y][i + 1]) == 1)
					i++;
			}
		}
		y++;
	}
}
