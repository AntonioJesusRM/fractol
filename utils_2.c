/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:37:16 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/08/24 13:35:34 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse(int button, int x, int y, void *param)
{
	t_vars	*vars;
	t_pixel	p;

	vars = (t_vars *)param;
	p = (t_pixel){x, y};
	if (button == 4)
	{
		vars->midpoint = pixel_to_complex(vars, p);
		vars->range *= 0.5;
		vars->max_iter *= 1.05;
	}
	else if (button == 5)
	{
		vars->midpoint = pixel_to_complex(vars, p);
		vars->range *= 1.5;
		vars->max_iter *= 0.95;
		if (vars->max_iter < 100)
			vars->max_iter = 100;
	}
	plot_fractal(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
	return (0);
}
