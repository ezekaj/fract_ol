/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	color_grayscale_animated(int i, int max_i, double time)
{
	t_color	color;

	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.time_phase = time * 0.3;
	color.brightness = (int)(255 * (0.5 + 0.5 * cos(color.t * 10.0
					+ color.time_phase)));
	if (color.brightness < 0)
		color.brightness = 0;
	else if (color.brightness > 255)
		color.brightness = 255;
	return ((color.brightness << 24) | (color.brightness << 16)
		| (color.brightness << 8) | 0xFF);
}

int	colors_animated_classic_blue(int i, int max_i, int color_scheme,
		double time)
{
	if (color_scheme == COLOR_SCHEME_CLASSIC)
		return (color_classic_animated(i, max_i, time));
	else if (color_scheme == COLOR_SCHEME_BLUE)
		return (color_blue_animated(i, max_i, time));
	return (0);
}

int	colors_animated_fire_psychedelic(int i, int max_i,
		int color_scheme, double time)
{
	if (color_scheme == COLOR_SCHEME_FIRE)
		return (color_fire_animated(i, max_i, time));
	else if (color_scheme == COLOR_SCHEME_PSYCHEDELIC)
		return (color_psychedelic_animated(i, max_i, time));
	return (0);
}

int	colors_animated(int i, int max_i, int color_scheme, double time)
{
	int	result;

	result = colors_animated_classic_blue(i, max_i, color_scheme, time);
	if (result != 0)
		return (result);
	result = colors_animated_fire_psychedelic(i, max_i, color_scheme, time);
	if (result != 0)
		return (result);
	if (color_scheme == COLOR_SCHEME_GRAYSCALE)
		return (color_grayscale_animated(i, max_i, time));
	else
		return (colors(i, max_i, color_scheme));
}
