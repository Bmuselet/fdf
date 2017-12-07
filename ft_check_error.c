/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:16:01 by bmuselet          #+#    #+#             */
/*   Updated: 2017/12/05 17:52:50 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_check_hexadecimal(char *buff, int i, int num, int start)
{
	if (buff[i - 1] < '0' || buff[i - 1] > '9')
		return (-1);
	i++;
	if (buff[i] != '0' || buff[i + 1] != 'x' || buff[num] != ' ')
		return (-1);
	i += 2;
	while (i < num)
	{
		if ((buff[i] < '0' || buff[i] > '9') && (buff[i] < 'A' || buff[i] > 'F'))
			return (-1);
		i++;
	}
	while (start < num)
	{
		buff[start] = ' ';
		start++;
	}
	return (1);
}

static int	ft_check_length(char *buff)
{
	t_mlx a;

	a.nv_char = 0;
	a.length = -1;
	while (buff[a.nb_char] != '\0')
	{
		a.length = 0;
		while (buff[a.nb_char] == ' ')
			a.nb_char++;
		while (buff[a.nb_char] != '\n' && buff[a.nb_char] != '\0')
		{
			while (buff[a.nb_char] == ' ' && buff[a.nb_char] != '\n' && buff[a.nb_char] != '\0')
				a.nb_char++;
			if (buff[a.nb_char] != '\n' && buff[a.nb_char] != '\0')
				a.nb_line++;
			while (buff[a.nb_char] != ' ' && buff[a.nb_char] != '\n' && buff[a.nb_char] != '\0')
				a.nb_char++;
		}
		if (a.length == -1)
			a.length = a.nb_line;
		else if (a.nb_line != a.length)
			return (-1);
		a.nb_char++;
	}
	return (a.length);
}

static int	ft_start_error(char *buff)
{
	int		i;

	i = 0;
	while (buff[i] != '\0')
	{
		if ((buff[i] < '0' || buff[i] > '9') && buff[i] != '-' && buff[i] != ' ')
		{
			ft_putstr_fd("error: lines must start by a digit or space\n", 2);
			return (-1);
		}
		while (buff[i] != '\n' && buff[i] != '\0')
			i++;
		i++;
	}
	return (1);
}

static int	ft_invalid(char *buff, int i)
{
	while (buff[i] != '\0')
	{
		if (buff[i] == '-' && (buff[i + 1] < '0' || buff[i + 1] > '9'))
		{
			ft_putstr_fd(
					"error: '-' must be followed only by a digit\n", 2);
			return (-1);
		}
		if (buff[i] != '-' && buff[i] != ' ' && buff[i] != '\n'\
				&& !(buff[i] >= '0' && buff[i] <= '9'))
		{
			if (buff[i] == ',' && ft_check_hexadecimal(buff, i, i + 9, i) == -1)
			{
				ft_putstr_fd("error: hexadecimal error\n", 2);
				return (-1);
			}
			else
			{
				ft_putstr_fd("error: bad character in file\n", 2);
				return (-1);
			}
		}
		i++;
	}
	return (1);
}

char		*ft_check_error(char *buff, int *length)
{
	int		i;

	i = 0;
	if (buff[0] == '\0')
	{
		ft_putstr_fd("error: file is empty\n", 2);
		return (NULL);
	}
	while (buff[i] != '\0')
		i++;
	buff[i - 1] = '\0';
	if (ft_start_error(buff) == -1 || ft_invalid(buff, 0) == -1)
		return (NULL);
	if ((*length = ft_check_length(buff)) == -1)
	{
		ft_putstr_fd("error: lines of the file are not the same length\n", 2);
		return (NULL);
	}
	return (buff);
}
