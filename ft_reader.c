/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:03:24 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/01 11:59:27 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <stdio.h>

static t_point	*ft_new_list(char c, int k, int j)
{
	t_point	*new_elem;

	new_elem = NULL;
	new_elem = (t_point*)malloc(sizeof(t_point));
	if ((new_elem) == NULL)
		return (NULL);
	if (new_elem)
	{
		new_elem->x = k;
		new_elem->y = j;
		new_elem->z = c;
		new_elem->next = NULL;
	}
	return (new_elem);
}



t_point			*ft_reader(char *av)
{
	t_point	*first;
	t_point	*ptr;
	char	*line;
	int		i;
	int		j;
	int		k;
	int		fd;

	ptr = NULL;
	first = NULL;
	i = 0;
	j = 0;
	k = 0;
	fd = open(av, O_RDONLY);
	if (first == NULL)
	{
		if (get_next_line(fd, &line) == 1)
		{
			first = ft_new_list(line[0], k, j);
			ptr = first;
			i++;
			k++;
			while (line[i])
			{
				while (ft_isdigit(line[i]) == 0)
					i++;
				ptr->next = ft_new_list(line[i], k, j);
				ptr = ptr->next;
				i++;
				k++;
			}
		}
	}
	i = 0;
	j = 0;
	k = 0;
	while (get_next_line(fd, &line) != 0)
	{
		j++;
		while (line[i])
		{
			while (ft_isdigit(line[i]) == 0)
				i++;
			ptr->next = ft_new_list(line[i], k, j);
			ptr = ptr->next;
			i++;
			k++;
		}
		i = 0;
		k = 0;
	}
	while (ft_isdigit(line[i]) == 0)
		i++;
	ptr->next = ft_new_list(line[i], k, j);
	ptr = ptr->next;
	i++;
	k++;
	ptr->next = NULL;
	close(fd);
	return (first);
}
