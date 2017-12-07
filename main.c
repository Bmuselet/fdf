/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:05:17 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/07 12:32:28 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

int		**ft_new_tab(char *str, int nb_line, int nb_int)
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

t_point	ft_init(char **content, char *str, int nb_line, int nb_int)
{
	t_point point;

	point.z = 2.0;
	point.tab = ft_new_tab(str, nb_line, nb_int);
	if (nb_line >= nb_int)
		point.def_zoom = 400 / nb_line;
	else
		point.def_zoom = 400 / nb_int;
	return (point);
}

int		ft_escape(int keycode, void *param)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	t_tools	tools;
	t_point	point;

	tools.nb_line = 0;
	ft_reader(argc, argv[1], &tools);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "win fdf");
	point = ft_init(tools.content, tools.str, tools.nb_line, tools.nb_int);
	ft_draw(&point, tools, mlx);
	mlx_key_hook(mlx.win, ft_escape, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
