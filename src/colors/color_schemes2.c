/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 21:50:34 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	color_psychedelic(int i, int max_i)
{
	t_color color;
	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.phase = color.t * 15.0;
	color.r = (int)(127.5 + 127.5 * sin(color.phase));
	color.g = (int)(127.5 + 127.5 * sin(color.phase + 2.094));
	color.b = (int)(127.5 + 127.5 * sin(color.phase + 4.188));
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

int	color_psychedelic_animated(int i, int max_i, double time)
{
	t_color color;
	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
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

int	color_grayscale(int i, int max_i)
{
	t_color color;
	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.brightness = (int)(255 * (0.5 + 0.5 * cos(color.t * 10.0)));
	if (color.brightness < 0)
		color.brightness = 0;
	else if (color.brightness > 255)
		color.brightness = 255;
	return ((color.brightness << 24) | (color.brightness << 16) | (color.brightness << 8) | 0xFF);
}

int	color_grayscale_animated(int i, int max_i, double time)
{
	t_color color;
	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.time_phase = time * 0.3;
	color.brightness = (int)(255 * (0.5 + 0.5 * cos(color.t * 10.0 + color.time_phase)));
	if (color.brightness < 0)
		color.brightness = 0;
	else if (color.brightness > 255)
		color.brightness = 255;
	return ((color.brightness << 24) | (color.brightness << 16) | (color.brightness << 8) | 0xFF);
}

int	colors(int i, int max_i, int color_scheme)
{
	if (color_scheme == COLOR_SCHEME_BLUE)
		return (color_blue(i, max_i));
	else if (color_scheme == COLOR_SCHEME_FIRE)
		return (color_fire(i, max_i));
	else if (color_scheme == COLOR_SCHEME_PSYCHEDELIC)
		return (color_psychedelic(i, max_i));
	else if (color_scheme == COLOR_SCHEME_GRAYSCALE)
		return (color_grayscale(i, max_i));
	else
		return (color_classic(i, max_i));
}

int	colors_animated(int i, int max_i, int color_scheme, double time)
{
	if (color_scheme == COLOR_SCHEME_CLASSIC)
		return (color_classic_animated(i, max_i, time));
	else if (color_scheme == COLOR_SCHEME_BLUE)
		return (color_blue_animated(i, max_i, time));
	else if (color_scheme == COLOR_SCHEME_FIRE)
		return (color_fire_animated(i, max_i, time));
	else if (color_scheme == COLOR_SCHEME_PSYCHEDELIC)
		return (color_psychedelic_animated(i, max_i, time));
	else if (color_scheme == COLOR_SCHEME_GRAYSCALE)
		return (color_grayscale_animated(i, max_i, time));
	else
		return (colors(i, max_i, color_scheme));
}
