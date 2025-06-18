/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes_animated.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:00:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"



int	color_classic_animated(int i, int max_i, double time)
{
	t_color	color;

	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.time_phase = time * 0.3;
	color.r = (int)(200 + 55 * sin(color.t * 5.0 + color.time_phase));
	color.g = (int)(200 + 55 * sin(color.t * 5.0 + color.time_phase));
	color.b = (int)(255);
	clamp_color_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	color_blue_animated(int i, int max_i, double time)
{
	t_color	color;

	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.time_phase = time * 0.4;
	color.r = (int)(80 + 60 * sin(color.t * 4.0 + color.time_phase * 0.5));
	color.g = (int)(120 + 80 * sin(color.t * 6.0 + 1.0
				+ color.time_phase * 0.7));
	color.b = (int)(220 + 35 * sin(color.t * 8.0 + 2.0 + color.time_phase));
	clamp_color_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

int	color_fire_animated(int i, int max_i, double time)
{
	t_color	color;

	if (i == max_i)
		return (0x000000FF);
	color.t = (double)i / max_i;
	color.time_phase = time * 0.6;
	color.r = (int)(255);
	color.g = (int)(150 * color.t * (1.0 + 0.5 * sin(color.t * 12.0
					+ color.time_phase)));
	color.b = (int)(100 * color.t * color.t * (1.0 + 0.5 * sin(color.t * 16.0
					+ color.time_phase * 1.3)));
	clamp_color_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}


