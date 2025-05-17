/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 23:23:08 by gasoline-ea      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	else if (fractol->type == TRICORN)
		i = tricorn(real, imag, fractol->max_iter);
	return (i);
}

void	render_row(int y, t_fractol *fractol)
{
	int		x;
	double	real;
	double	imag;
	int		i;
	int		color;

	x = 0;
	while (x < WIDTH)
	{
		map(x, y, &real, &imag, fractol);
		i = calculate_pixel(real, imag, fractol);

		if (fractol->smooth_color && i < fractol->max_iter)
		{
			double z_real = 0;
			double z_imag = 0;
			if (fractol->type == MANDELBROT)
			{
				z_real = real;
				z_imag = imag;
				for (int j = 0; j < i; j++)
				{
					double temp = z_real * z_real - z_imag * z_imag + real;
					z_imag = 2 * z_real * z_imag + imag;
					z_real = temp;
				}
			}
			else if (fractol->type == JULIA)
			{
				z_real = real;
				z_imag = imag;
				for (int j = 0; j < i; j++)
				{
					double temp = z_real * z_real - z_imag * z_imag + fractol->c_real;
					z_imag = 2 * z_real * z_imag + fractol->c_imag;
					z_real = temp;
				}
			}
			else if (fractol->type == TRICORN)
			{
				z_real = real;
				z_imag = imag;
				for (int j = 0; j < i; j++)
				{
					double temp = z_real * z_real - z_imag * z_imag + real;
					z_imag = -2 * z_real * z_imag + imag;
					z_real = temp;
				}
			}
			double smooth_i = calculate_smooth_value(z_real, z_imag, i, fractol->max_iter);
			if (fractol->color_scheme == COLOR_SCHEME_PSYCHEDELIC && fractol->animate_colors)
				color = smooth_color_psychedelic_animated(smooth_i, fractol->max_iter, fractol->animation_time);
			else if (fractol->color_scheme == COLOR_SCHEME_CLASSIC)
				color = smooth_color_classic(smooth_i, fractol->max_iter);
			else if (fractol->color_scheme == COLOR_SCHEME_FIRE)
				color = smooth_color_fire(smooth_i, fractol->max_iter);
			else if (fractol->color_scheme == COLOR_SCHEME_PSYCHEDELIC)
				color = smooth_color_psychedelic(smooth_i, fractol->max_iter);
			else
				color = colors(i, fractol->max_iter, fractol->color_scheme);
		}
		else
		{
			if (fractol->color_scheme == COLOR_SCHEME_PSYCHEDELIC && fractol->animate_colors)
				color = color_psychedelic_animated(i, fractol->max_iter, fractol->animation_time);
			else
				color = colors(i, fractol->max_iter, fractol->color_scheme);
		}
		mlx_put_pixel(fractol->img, x, y, color);
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
	if (fractol->show_ui)
		render_ui_text(fractol);
}
