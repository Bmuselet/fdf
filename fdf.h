/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:17:41 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/08 17:23:09 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define WIN_WIDTH	800
# define WIN_HEIGHT	800

# define BLUE 0x0041FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500

typedef struct		s_point
{
	int				**tab;
	int				length;
	double			x;
	double			y;
	double			z;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				zoom;
	int				x_move;
	int				y_move;
}					t_point;

typedef struct		s_tools
{
	int				nb_line;
	int				nb_int;
	char			*str;
	char			**content;

}					t_tools;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_tools			*tools;
	t_point			*point;

}					t_mlx;

int					ft_key_events(int keycode, t_mlx *mlx);
int					ft_reader(int argc, char *argv, t_tools *tools);
int					ft_atoi_fdf(const char *str, int *c);
void				ft_init_struct(t_tools tools, t_mlx *mlx, t_point *point);
void				ft_draw(t_point *point, t_tools tools, t_mlx mlx);
int					ft_check_error(char *str);
int					ft_expose_hook(t_mlx *mlx);

#endif
