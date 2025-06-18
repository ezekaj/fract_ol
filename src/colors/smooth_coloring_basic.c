/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_coloring_basic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:00:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

double	calc_smooth_value(double z_real, double z_imag, int iter, int max_i)
{
	double	log_zn;
	double	nu;

	if (iter == max_i)
		return ((double)iter);
	log_zn = log(z_real * z_real + z_imag * z_imag) / 2.0;
	nu = log(log_zn / log(2.0)) / log(2.0);
	return (iter + 1 - nu);
}

static void	clamp_rgb_values(t_color *color)
{
	if (color->r < 0)
		color->r = 0;
	else if (color->r > 255)
		color->r = 255;
	if (color->g < 0)
		color->g = 0;
	else if (color->g > 255)
		color->g = 255;
	if (color->b < 0)
		color->b = 0;
	else if (color->b > 255)
		color->b = 255;
}

void	clamp_color_values(t_color *color)
{
	clamp_rgb_values(color);
}

int	smooth_color_classic(double smooth_iter, int max_i)
{
	t_color	color;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.r = (int)(200 + 55 * sin(color.t * 5.0));
	color.g = (int)(200 + 55 * sin(color.t * 5.0));
	color.b = (int)(255);
	clamp_rgb_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	smooth_color_blue(double smooth_iter, int max_i)
{
	t_color	color;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.r = (int)(80 + 60 * sin(color.t * 4.0));
	color.g = (int)(120 + 80 * sin(color.t * 6.0 + 1.0));
	color.b = (int)(220 + 35 * sin(color.t * 8.0 + 2.0));
	clamp_rgb_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	smooth_color_fire(double smooth_iter, int max_i)
{
	t_color	color;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.r = (int)(255);
	color.g = (int)(150 * color.t * (1.0 + 0.5 * sin(color.t * 12.0)));
	color.b = (int)(100 * color.t * color.t
			* (1.0 + 0.5 * sin(color.t * 16.0)));
	clamp_rgb_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}


