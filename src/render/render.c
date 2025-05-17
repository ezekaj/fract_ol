/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 15:31:40 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	calculate_pixel(double real, double imag, t_fractol *fractol)
{
	int	i;

	i = 0;
	if (fractol->type == MANDELBROT)
		i = mandelbrot(real, imag, fractol->max_iter);
	else if (fractol->type == JULIA)
		i = julia(real, imag, fractol->c_real, fractol->c_imag,
				fractol->max_iter);
	return (i);
}

void	render_row(int y, t_fractol *fractol)
{
	int		x;
	double	real;
	double	imag;
	int		i;

	x = 0;
	while (x < WIDTH)
	{
		map(x, y, &real, &imag, fractol);
		i = calculate_pixel(real, imag, fractol);
		mlx_put_pixel(fractol->img, x, y,
			colors(i, fractol->max_iter, fractol->color_scheme));
		x++;
	}
}

void	fractal_render(t_fractol *fractol)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		render_row(y, fractol);
		y++;
	}
}
