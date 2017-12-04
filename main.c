/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:05:17 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/04 16:42:04 by bmuselet         ###   ########.fr       */
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

void ft_ligne(void *win, void *mlx, int x1,int y1, int x2,int y2) 
{
	int x;
	int y;

	if(x1 < x2 || (x2 - x1) <= abs(y2-y1))
	{
		x = x1;
		while (x < x2)
		{            mlx_pixel_put(mlx, win, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), 0x00FFFFFF);
			x++;
		}
	}
	if(x2 < x1 || (x1 - x2) <= abs(y1-y2))
	{
		x = x2;
		while (x < x1)
		{
			mlx_pixel_put(mlx, win, x, y2 + ((y1 - y2) * (x - x2)) / (x1 - x2), 0x00FFFFFF);
			x++;
		}
	}
	else if(y1 < y2 || (y2 - y1) <= abs(x2-x1))
	{
		y = y1;
		while (y < y2)
		{            
			mlx_pixel_put(mlx, win, y, x1 + ((x2 - x1) * (y - y1)) / (y2 - y1), 0x00FFFFFF);
			y++;
		}
	}
	else if(y2 < y1 || (y1 - y2) <= abs(x1-x2))
	{
		y = y2;
		while (y < y1)
		{
			mlx_pixel_put(mlx, win, y, x2 + ((x1 - x2) * (y - y2)) / (y1 - y2), 0x00FFFFFF);
			y++;
		}
	}
}
/*
 * void ft_ligne(void *win, void *mlx, int x1,int y1, int x2,int y2)  // Bresenham
 * {
 *     int x,y;
 *         int Dx,Dy;
 *             int xincr,yincr;
 *                 int erreur;
 *                     int i;
 *                         Dx = abs(x2-x1);
 *                             Dy = abs(y2-y1);
 *                                 if(x1<x2)
 *                                         xincr = 1;
 *                                             else
 *                                                     xincr = -1;
 *                                                         if(y1<y2)
 *                                                                 yincr = 1;
 *                                                                     else
 *                                                                             yincr = -1;
 *                                                                                 x = x1;
 *                                                                                     y = y1;
 *                                                                                         if(Dx>Dy)
 *                                                                                             {
 *                                                                                                     erreur = Dx/2;
 *                                                                                                             for(i=0;i<Dx;i++)
 *                                                                                                                     {
 *                                                                                                                                 x += xincr;
 *                                                                                                                                             erreur += Dy;
 *                                                                                                                                                         if(erreur>Dx)
 *                                                                                                                                                                     {
 *                                                                                                                                                                                     erreur -= Dx;
 *                                                                                                                                                                                                     y += yincr;
 *                                                                                                                                                                                                                 }
 *                                                                                                                                                                                                                             mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
 *                                                                                                                                                                                                                                     }
 *                                                                                                                                                                                                                                         }
 *                                                                                                                                                                                                                                             else
 *                                                                                                                                                                                                                                                 {
 *                                                                                                                                                                                                                                                         erreur = Dy/2;
 *                                                                                                                                                                                                                                                                 for(i=0;i<Dy;i++)
 *                                                                                                                                                                                                                                                                         {
 *                                                                                                                                                                                                                                                                                     y += yincr;
 *                                                                                                                                                                                                                                                                                                 erreur += Dx;
 *                                                                                                                                                                                                                                                                                                             if(erreur>Dy)
 *                                                                                                                                                                                                                                                                                                                         {
 *                                                                                                                                                                                                                                                                                                                                         erreur -= Dy;
 *                                                                                                                                                                                                                                                                                                                                                         x += xincr;
 *                                                                                                                                                                                                                                                                                                                                                                     }
 *                                                                                                                                                                                                                                                                                                                                                                                 mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
 *                                                                                                                                                                                                                                                                                                                                                                                         }
 *                                                                                                                                                                                                                                                                                                                                                                                             }
 *                                                                                                                                                                                                                                                                                                                                                                                                 mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
 *                                                                                                                                                                                                                                                                                                                                                                                                     mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
 *                                                                                                                                                                                                                                                                                                                                                                                                     }
 *                                                                                                                                                                                                                                                                                                                                                                                                     */
void ft_pos(int i,int j,int alt,int* outx,int* outy)
{
	int startx,starty;
	int pas = WIN_WIDTH / 25;
	startx = WIN_WIDTH / 3;
	starty = WIN_HEIGHT / 5;
	*outx = startx + (i - j ) * pas;
	*outy = starty + ((i + j) * pas) / 2 - alt * 5;
}

void	ft_segment(void *win, void *mlx, int xmin,int ymin,int xmax,int ymax, int z)
{
	int imin,jmin,imax,jmax;
	int alt = 0;
	ft_pos(xmin,ymin, z,&imin,&jmin);
	ft_pos(xmax,ymax, z,&imax,&jmax);
	mlx_pixel_put(mlx, win, imin, jmin, 0x00FFFFFF);
	ft_ligne(win, mlx, imin,jmin,imax,jmax);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		count_width;
	int		count_height;
	//t_point	*point;
	//t_point	*tmp;
	char    **str;
	int i;
	int y;
	int x;
	int z;
	y = 0;
	str = ft_reader(argv[1]);
	if (argc)
	/*
	   tmp = point;
	   while (tmp->next != NULL)
	   {
	//printf("%d ",tmp->x);
	//printf("%d ", tmp->y);
	tmp->z = ft_char_getnbr(tmp->z);
	//printf("%d\n", tmp->z);
	tmp = tmp->next;
	}
	*/
	mlx.pointeur_mlx = mlx_init();
	mlx.pointeur_window = mlx_new_window(mlx.pointeur_mlx, WIN_WIDTH, WIN_HEIGHT, "win fdf");
	while (str[y] != 0)
	{
		i = 0;
		x = -1;
		while (str[y][i] != '\0')
		{  
			if (str[y][i] != ' ')
			{
				x++;
				z = ft_atoi(&str[y][i]);
				if (str[y][i + 1] != '\0')
					ft_segment(mlx.pointeur_window, mlx.pointeur_mlx, x,y,x+1,y,z);
				if (str[y + 1] != 0)
					ft_segment(mlx.pointeur_window, mlx.pointeur_mlx, x,y,x,y+1,z);
			}
			i++;
		}
		y++;
	}	
	//mlx.img.pointeur_image = mlx_new_image(mlx.pointeur_mlx, WIN_WIDTH, WIN_HEIGHT);
	/*
	   for(i=0;i<70;i++)
	   {
	   for(j=0;j<70;j++)
	   {
	   if (i!=69)
	   {
	   ft_segment(mlx.pointeur_window, mlx.pointeur_mlx, i,j,i+1,j);
	   }
	   if (j!=69)
	   {
	   ft_segment(mlx.pointeur_window, mlx.pointeur_mlx,i,j,i,j+1);
	   }
	   }
	   }

	   while (point->next != NULL)
	   {
	   ft_segment(mlx.pointeur_window, mlx.pointeur_mlx, point->x,point->y,point->next->x,point->y,point->z);
	   ft_segment(mlx.pointeur_window, mlx.pointeur_mlx,point->x,point->y,point->x,point->next->y,point->z);
	   point = point->next;
	   }
	//mlx.img.data = (int *)mlx_get_data_addr(mlx.img.pointeur_image, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	//ft_draw(mlx, point);
	//mlx_put_image_to_window(mlx.pointeur_mlx, mlx.pointeur_window, mlx.img.pointeur_image, 0, 0);
	*/
	mlx_key_hook(mlx.pointeur_window, ft_escape, 0);
	mlx_loop(mlx.pointeur_mlx);
	return (0);
}
