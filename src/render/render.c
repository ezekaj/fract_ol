/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 23:41:12 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	calculate_pixel(double real, double imag, t_fractol *fractol)
{
	int				i;
	t_julia_params	params;

	i = 0;
	if (fractol->type == MANDELBROT)
		i = mandelbrot(real, imag, fractol->max_iter);
	else if (fractol->type == JULIA)
	{
		params.real = real;
		params.imag = imag;
		params.c_real = fractol->c_real;
		params.c_imag = fractol->c_imag;
		params.max_i = fractol->max_iter;
		i = julia(&params);
	}
	else if (fractol->type == TRICORN)
		i = tricorn(real, imag, fractol->max_iter);
	return (i);
}

void	render_row(int y, t_fractol *fractol)
{
	double			real;
	double			imag;
	double			z_real;
	double			z_imag;
	double			temp;
	double			smooth_i;
	int				x;
	int				i;
	int				color;
	t_map_params	map_params;

	x = 0;
	z_real = 0;
	z_imag = 0;
	while (x < WIDTH)
	{
		{
			map_params.x = x;
			map_params.y = y;
			map_params.real = &real;
			map_params.imag = &imag;
			map(&map_params, fractol);
		}
		i = calculate_pixel(real, imag, fractol);
		if (fractol->smooth_color && i < fractol->max_iter)
		{
			if (fractol->type == MANDELBROT)
			{
				for (int j = 0; j < i; j++)
				{
					temp = z_real * z_real - z_imag * z_imag + real;
					z_imag = 2 * z_real * z_imag + imag;
					z_real = temp;
				}
			}
			else if (fractol->type == JULIA)
			{
				for (int j = 0; j < i; j++)
				{
					temp = z_real * z_real - z_imag * z_imag + fractol->c_real;
					z_imag = 2 * z_real * z_imag + fractol->c_imag;
					z_real = temp;
				}
			}
			else if (fractol->type == TRICORN)
			{
				for (int j = 0; j < i; j++)
				{
					temp = z_real * z_real - z_imag * z_imag + real;
					z_imag = -2 * z_real * z_imag + imag;
					z_real = temp;
				}
			}
			smooth_i = calc_smooth_value(z_real, z_imag, i, fractol->max_iter);
			if (fractol->animate_colors)
			{
				if (fractol->color_scheme == COLOR_SCHEME_CLASSIC)
					color = smooth_color_classic_animated(smooth_i, fractol->max_iter, fractol->animation_time);
				else if (fractol->color_scheme == COLOR_SCHEME_BLUE)
					color = smooth_color_blue_animated(smooth_i, fractol->max_iter, fractol->animation_time);
				else if (fractol->color_scheme == COLOR_SCHEME_FIRE)
					color = smooth_color_fire_animated(smooth_i, fractol->max_iter, fractol->animation_time);
				else if (fractol->color_scheme == COLOR_SCHEME_PSYCHEDELIC)
					color = psychedelic_animated(smooth_i, fractol->max_iter, fractol->animation_time);
				else if (fractol->color_scheme == COLOR_SCHEME_GRAYSCALE)
					color = smooth_color_grayscale_animated(smooth_i, fractol->max_iter, fractol->animation_time);
				else
					color = colors(i, fractol->max_iter, fractol->color_scheme);
			}
			else
			{
				if (fractol->color_scheme == COLOR_SCHEME_CLASSIC)
					color = smooth_color_classic(smooth_i, fractol->max_iter);
				else if (fractol->color_scheme == COLOR_SCHEME_BLUE)
					color = smooth_color_blue(smooth_i, fractol->max_iter);
				else if (fractol->color_scheme == COLOR_SCHEME_FIRE)
					color = smooth_color_fire(smooth_i, fractol->max_iter);
				else if (fractol->color_scheme == COLOR_SCHEME_PSYCHEDELIC)
					color = smooth_color_psychedelic(smooth_i, fractol->max_iter);
				else if (fractol->color_scheme == COLOR_SCHEME_GRAYSCALE)
					color = smooth_color_grayscale(smooth_i, fractol->max_iter);
				else
					color = colors(i, fractol->max_iter, fractol->color_scheme);
			}
		}
		else
		{
			if (fractol->animate_colors)
				color = colors_animated(i, fractol->max_iter, fractol->color_scheme, fractol->animation_time);
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
