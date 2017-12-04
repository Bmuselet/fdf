/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:17:41 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/04 19:37:52 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define WIN_WIDTH	1200
# define WIN_HEIGHT	1200

# define BLUE 0x0041FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500

typedef struct		s_point
{
	int				x;
	int				y;
	char			z;
	struct s_point	*next;
}					t_point;

typedef struct		s_img
{
	void			*pointeur_image;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*pointeur_mlx;
	void			*pointeur_window;
	t_point			*point;
	t_img			img;
}					t_mlx;

char				**ft_reader(char *av);
t_point				*ft_reader2(char *av);
int					ft_reader3(char *av, t_mlx mlx);
void				ft_draw(t_mlx mlx, t_point *point);

#endif
