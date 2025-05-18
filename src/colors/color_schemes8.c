/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
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
