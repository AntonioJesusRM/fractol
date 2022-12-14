/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:28:13 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/08/22 12:32:48 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, int max_iter, void *args)
{
	t_complex	z;
	t_complex	z2;
	int			i;

	(void)args;
	z.x = 0;
	z.y = 0;
	z2.x = 0;
	z2.y = 0;
	i = 0;
	while (i < max_iter && z2.x + z2.y < 4)
	{
		z.y = 2 * z.x * z.y + c.y;
		z.x = z2.x - z2.y + c.x;
		z2.x = z.x * z.x;
		z2.y = z.y * z.y;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}

int	julia(t_complex z, int max_iter, void *args)
{
	t_complex	z2;
	int			i;
	t_complex	c;

	z2.x = z.x * z.x;
	z2.y = z.y * z.y;
	c = *(t_complex *)args;
	i = 0;
	while (i < max_iter && z2.x + z2.y < 4)
	{
		z.y = 2 * z.x * z.y + c.y;
		z.x = z2.x - z2.y + c.x;
		z2.x = z.x * z.x;
		z2.y = z.y * z.y;
		i++;
	}
	if (i == max_iter)
		return (0);
	return (i);
}
