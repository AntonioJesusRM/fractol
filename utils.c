/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:15:46 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/09/01 16:39:23 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_space(const char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		if (str[cont] == '\t' || str[cont] == '\n' || str[cont] == '\v'
			|| str[cont] == '\f' || str[cont] == '\r' || str[cont] == ' ')
			cont++;
		else
			return (cont);
	}
	return (cont);
}

int	ft_atoi(const char *str)
{
	int	cont;
	int	num;
	int	sig;

	cont = ft_space(str);
	num = 0;
	sig = 1;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			sig = sig * (-1);
		cont++;
	}
	while (str[cont] != '\0')
	{
		if (str[cont] >= '0' && str[cont] <= '9')
			num = (num * 10) + (str[cont] - '0');
		else
			return (num * sig);
		cont++;
	}
	return (num * sig);
}

double	ft_atof(char *str)
{
	int		i;
	double	ret;
	double	n_deci;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
	{
		ret = (double)ft_atoi(str);
		return (ret);
	}
	ret = (double)ft_atoi(str);
	n_deci = (double)ft_atoi(&str[i + 1]);
	while (n_deci >= 1)
		n_deci /= 10;
	while (str[++i] == '0')
		n_deci /= 10;
	if (str[0] == '-')
		return (ret - n_deci);
	return (ret + n_deci);
}

int	keys(int key, void *param)
{
	(void)param;
	if (key == ESC)
		exit(0);
	return (0);
}

int	destroy(void *param)
{
	(void)param;
	exit(0);
}
