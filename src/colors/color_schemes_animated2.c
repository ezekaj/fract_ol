/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes_animated2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:00:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"



void	init_psychedelic_animated_color(t_color *color, int i, int max_i,
		double time)
{
	if (i == max_i)
		return ;
	color->t = (double)i / max_i;
	color->time_phase = time * 0.5;
	color->phase = color->t * 15.0 + color->time_phase;
	color->r = (int)(127.5 + 127.5 * sin(color->phase));
	color->g = (int)(127.5 + 127.5 * sin(color->phase + 2.094
				+ sin(color->time_phase * 0.3) * 0.5));
	color->b = (int)(127.5 + 127.5 * sin(color->phase + 4.188
				+ cos(color->time_phase * 0.2) * 0.5));
}

void	apply_psychedelic_animated_effects(t_color *color)
{
	color->r = (int)(color->r * (0.8 + 0.2 * sin(color->t * 5.0
					+ color->time_phase)));
	color->g = (int)(color->g * (0.8 + 0.2 * cos(color->t * 7.0
					+ color->time_phase * 0.7)));
	color->b = (int)(color->b * (0.8 + 0.2 * sin(color->t * 11.0
					+ color->time_phase * 0.5)));
}

int	color_psychedelic_animated(int i, int max_i, double time)
{
	t_color	color;

	if (i == max_i)
		return (0x000000FF);
	init_psychedelic_animated_color(&color, i, max_i, time);
	apply_psychedelic_animated_effects(&color);
	clamp_color_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

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
