/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:11:09 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/08/24 13:34:36 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# define FRACTOL_H
# define HEIGHT 1000
# define WIDTH 1000
# define ESC 53

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_complex{
	double	x;
	double	y;
}				t_complex;

typedef struct s_pixel
{
	int	x;
	int	y;
}				t_pixel;

typedef struct s_vars{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	int				height;
	int				width;
	int				max_iter;
	double			range;
	t_complex		midpoint;
	int				(*fractal)(t_complex, int, void *);
	t_complex		c_julia;
	int				palette;
}					t_vars;

int			mandelbrot(t_complex c, int max_iter, void *args);
int			julia(t_complex z, int max_iter, void *args);
double		ft_atof(char *str);
int			ft_atoi(const char *str);
int			keys(int key, void *param);
int			destroy(void *param);
int			mouse(int button, int x, int y, void *param);
t_complex	pixel_to_complex(t_vars *vars, t_pixel p);
void		plot_fractal(t_vars *vars);

#endif