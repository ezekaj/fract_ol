/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_dispatcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:00:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

static int	colors_animated_classic_blue(int i, int max_i, int color_scheme,
		double time)
{
	if (color_scheme == COLOR_SCHEME_CLASSIC)
		return (color_classic_animated(i, max_i, time));
	else if (color_scheme == COLOR_SCHEME_BLUE)
		return (color_blue_animated(i, max_i, time));
	return (0);
}

static int	colors_animated_fire_psychedelic(int i, int max_i,
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
