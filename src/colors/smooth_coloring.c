/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_coloring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 19:11:57 by ezekaj           ###   ########.fr       */
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

int	smooth_color_classic(double smooth_iter, int max_i)
{
	t_color color;
	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.r = (int)(200 + 55 * sin(color.t * 5.0));
	color.g = (int)(200 + 55 * sin(color.t * 5.0));
	color.b = (int)(255);
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 255)
		color.r = 255;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	smooth_color_classic_animated(double smooth_iter, int max_i, double time)
{
	t_color color;
	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.time_phase = time * 0.3;
	color.r = (int)(200 + 55 * sin(color.t * 5.0 + color.time_phase));
	color.g = (int)(200 + 55 * sin(color.t * 5.0 + color.time_phase));
	color.b = (int)(255);
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 255)
		color.r = 255;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	smooth_color_blue(double smooth_iter, int max_i)
{
	t_color color;
	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.r = (int)(80 + 60 * sin(color.t * 4.0));
	color.g = (int)(120 + 80 * sin(color.t * 6.0 + 1.0));
	color.b = (int)(220 + 35 * sin(color.t * 8.0 + 2.0));
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 255)
		color.r = 255;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 255)
		color.b = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	smooth_color_blue_animated(double smooth_iter, int max_i, double time)
{
	t_color color;
	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.time_phase = time * 0.4;
	color.r = (int)(80 + 60 * sin(color.t * 4.0 + color.time_phase * 0.5));
	color.g = (int)(120 + 80 * sin(color.t * 6.0 + 1.0 + color.time_phase * 0.7));
	color.b = (int)(220 + 35 * sin(color.t * 8.0 + 2.0 + color.time_phase));
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 255)
		color.r = 255;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 255)
		color.b = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	smooth_color_fire(double smooth_iter, int max_i)
{
	t_color color;
	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.r = (int)(255);
	color.g = (int)(150 * color.t * (1.0 + 0.5 * sin(color.t * 12.0)));
	color.b = (int)(100 * color.t * color.t * (1.0 + 0.5 * sin(color.t * 16.0)));
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 255)
		color.b = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	smooth_color_fire_animated(double smooth_iter, int max_i, double time)
{
	t_color color;
	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.time_phase = time * 0.6;
	color.r = (int)(255);
	color.g = (int)(150 * color.t * (1.0 + 0.5 * sin(color.t * 12.0 + color.time_phase)));
	color.b = (int)(100 * color.t * color.t * (1.0 + 0.5 * sin(color.t * 16.0 + color.time_phase * 1.3)));
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 255)
		color.b = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	smooth_color_psychedelic(double smooth_iter, int max_i)
{
	t_color color;
	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.phase = color.t * 15.0;
	color.r = (int)(127.5 + 127.5 * sin(color.phase));
	color.g = (int)(127.5 + 127.5 * sin(color.phase + 2.094));
	color.b = (int)(127.5 + 127.5 * sin(color.phase + 4.188));
	color.r = (int)(color.r * (0.8 + 0.2 * sin(color.t * 5.0)));
	color.g = (int)(color.g * (0.8 + 0.2 * cos(color.t * 7.0)));
	color.b = (int)(color.b * (0.8 + 0.2 * sin(color.t * 11.0)));
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 255)
		color.r = 255;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 255)
		color.b = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	psychedelic_animated(double smooth_iter, int max_i, double time)
{
	t_color color;
	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.time_phase = time * 0.5;
	color.phase = color.t * 15.0 + color.time_phase;
	color.r = (int)(127.5 + 127.5 * sin(color.phase));
	color.g = (int)(127.5 + 127.5 * sin(color.phase + 2.094 + sin(color.time_phase * 0.3) * 0.5));
	color.b = (int)(127.5 + 127.5 * sin(color.phase + 4.188 + cos(color.time_phase * 0.2) * 0.5));
	color.r = (int)(color.r * (0.8 + 0.2 * sin(color.t * 5.0 + color.time_phase)));
	color.g = (int)(color.g * (0.8 + 0.2 * cos(color.t * 7.0 + color.time_phase * 0.7)));
	color.b = (int)(color.b * (0.8 + 0.2 * sin(color.t * 11.0 + color.time_phase * 0.5)));
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 255)
		color.r = 255;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 255)
		color.g = 255;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 255)
		color.b = 255;
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	smooth_color_grayscale(double smooth_iter, int max_i)
{
	t_color color;
	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.brightness = (int)(255 * (0.5 + 0.5 * cos(color.t * 10.0)));
	if (color.brightness < 0)
		color.brightness = 0;
	else if (color.brightness > 255)
		color.brightness = 255;
	return ((color.brightness << 24) | (color.brightness << 16) | (color.brightness << 8) | 0xFF);
}

int	smooth_color_grayscale_animated(double smooth_iter, int max_i, double time)
{
	t_color color;
	if (smooth_iter >= max_i)
		return (0x000000FF);
	color.t = smooth_iter / max_i;
	color.time_phase = time * 0.3;
	color.brightness = (int)(255 * (0.5 + 0.5 * cos(color.t * 10.0 + color.time_phase)));
	if (color.brightness < 0)
		color.brightness = 0;
	else if (color.brightness > 255)
		color.brightness = 255;
	return ((color.brightness << 24) | (color.brightness << 16) | (color.brightness << 8) | 0xFF);
}
