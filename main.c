/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:05:17 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/11 16:55:21 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

static int		**ft_new_tab(char *str, int nb_line, int nb_int)
{
	int		i;
	int		j;
	int		k;
	int		**tab;

	j = 0;
	k = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * nb_line)))
		return (NULL);
	while (str[k] != '\0' && j < nb_line)
	{
		i = 0;
		if (!(tab[j] = (int *)malloc(sizeof(int) * nb_int)))
			return (NULL);
		while (str[k] != '\n' && str[k] != '\0' && j < nb_line)
		{
			tab[j][i++] = ft_atoi_fdf(str, &k);
			while (str[k] == ' ')
				k++;
		}
		k++;
		j++;
	}
	return (tab);
}

static t_point	ft_init(char **content, char *str, int nb_line, int nb_int)
{
	t_point point;

	point.z = 8;
	point.tab = ft_new_tab(str, nb_line, nb_int);
	point.x_move = WIN_WIDTH / 2;
	point.y_move = WIN_HEIGHT / 2;
	if (nb_line >= nb_int)
		point.zoom = WIN_HEIGHT / (nb_line * 2);
	else
		point.zoom = WIN_WIDTH / (nb_int * 2);
	return (point);
}

int				main(int argc, char **argv)
{
	t_mlx	mlx;
	t_tools	tools;
	t_point	point;

	tools.nb_line = 0;
	if (ft_reader(argc, argv[1], &tools) != 1)
		return (0);
	mlx.point = &point;
	mlx.tools = &tools;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "win fdf");
	point = ft_init(tools.content, tools.str, tools.nb_line, tools.nb_int);
	ft_expose_hook(&mlx);
	mlx_key_hook(mlx.win, ft_key_events, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
