/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 22:50:06 by gasoline-ea      ###   ########.fr       */
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

	// Normalize iteration count to [0, 1]
	t = (double)i / max_i;

	// Create a phase value for wave-like patterns
	// Using integer-based calculations for non-smooth version
	phase = t * 15.0;

	// Use sinusoidal patterns with different phases for each channel
	r = (int)(127.5 + 127.5 * sin(phase));
	g = (int)(127.5 + 127.5 * sin(phase + 2.094)); // 120 degrees phase shift
	b = (int)(127.5 + 127.5 * sin(phase + 4.188)); // 240 degrees phase shift

	// Ensure values are within valid range
	r = (r < 0) ? 0 : (r > 255) ? 255 : r;
	g = (g < 0) ? 0 : (g > 255) ? 255 : g;
	b = (b < 0) ? 0 : (b > 255) ? 255 : b;

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
