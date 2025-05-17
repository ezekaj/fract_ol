/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 23:32:08 by gasoline-ea      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/fractol.h"

int	color_psychedelic(int i, int max_i)
{
	int		r;
	int		g;
	int		b;
	double	t;
	double	phase;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
	phase = t * 15.0;
	r = (int)(127.5 + 127.5 * sin(phase));
	g = (int)(127.5 + 127.5 * sin(phase + 2.094));
	b = (int)(127.5 + 127.5 * sin(phase + 4.188));
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int	color_psychedelic_animated(int i, int max_i, double time)
{
	int		r;
	int		g;
	int		b;
	double	t;
	double	phase;
	double	time_phase;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
	time_phase = time * 0.5;
	phase = t * 15.0 + time_phase;
	r = (int)(127.5 + 127.5 * sin(phase));
	g = (int)(127.5 + 127.5 * sin(phase + 2.094 + sin(time_phase * 0.3) * 0.5));
	b = (int)(127.5 + 127.5 * sin(phase + 4.188 + cos(time_phase * 0.2) * 0.5));
	r = (int)(r * (0.8 + 0.2 * sin(t * 5.0 + time_phase)));
	g = (int)(g * (0.8 + 0.2 * cos(t * 7.0 + time_phase * 0.7)));
	b = (int)(b * (0.8 + 0.2 * sin(t * 11.0 + time_phase * 0.5)));
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int	color_grayscale(int i, int max_i)
{
	double	t;
	int		brightness;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
	brightness = (int)(255 * (0.5 + 0.5 * cos(t * 10.0)));
	if (brightness < 0)
		brightness = 0;
	else if (brightness > 255)
		brightness = 255;
	return ((brightness << 24) | (brightness << 16) | (brightness << 8) | 0xFF);
}

int	color_grayscale_animated(int i, int max_i, double time)
{
	double	t;
	double	time_phase;
	int		brightness;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
	time_phase = time * 0.3;
	brightness = (int)(255 * (0.5 + 0.5 * cos(t * 10.0 + time_phase)));
	if (brightness < 0)
		brightness = 0;
	else if (brightness > 255)
		brightness = 255;
	return ((brightness << 24) | (brightness << 16) | (brightness << 8) | 0xFF);
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
