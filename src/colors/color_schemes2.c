/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 22:55:25 by gasoline-ea      ###   ########.fr       */
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

int	color_grayscale(int i, int max_i)
{
	int	brightness;

	if (i == max_i)
		return (0x000000FF);
	brightness = 255 - ((i * 255) / max_i);
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
