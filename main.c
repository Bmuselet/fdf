/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:05:17 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/01 11:59:17 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <stdio.h>

int ft_escape(int keycode, void *param)
{
	if (keycode == 53)
		exit(1);
	printf("key event %d\n", keycode);
	return (0);
}

int	ft_char_getnbr(char c)
{
	int		result;

	result = 0;
	result = (result * 10) + (c - '0');
	return (result);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		count_width;
	int		count_height;
	t_point	*point;
	t_point	*tmp;

	if (ac != 2)
	{
		write(1, "Usage : ./fdf <filename>\n", 26);
		return (0);
	}
	point = ft_reader(av[1]);
	tmp = point;
	while (tmp->next != NULL)
	{
//		printf("%d ",point->x);
//		printf("%d ", point->y);
		tmp->z = ft_char_getnbr(tmp->z);
//		printf("%d\n", point->z);
		tmp = tmp->next;
	}
	mlx.pointeur_mlx = mlx_init();
	mlx.pointeur_window = mlx_new_window(mlx.pointeur_mlx, WIN_WIDTH, WIN_HEIGHT, "win fdf");
	mlx.img.pointeur_image = mlx_new_image(mlx.pointeur_mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.pointeur_image, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	ft_draw(mlx, point);
	mlx_put_image_to_window(mlx.pointeur_mlx, mlx.pointeur_window, mlx.img.pointeur_image, 0, 0);
	mlx_key_hook(mlx.pointeur_window, ft_escape, 0);
	mlx_loop(mlx.pointeur_mlx);
	return (0);
}
