/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_coloring3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	smooth_color_grayscale(double smooth_iter, int max_i)
{
	double	t;
	int		brightness;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	brightness = (int)(255 * (0.5 + 0.5 * cos(t * 10.0)));
	if (brightness < 0)
		brightness = 0;
	else if (brightness > 255)
		brightness = 255;
	return ((brightness << 24) | (brightness << 16) | (brightness << 8) | 0xFF);
}

int	smooth_color_grayscale_animated(double smooth_iter, int max_i, double time)
{
	double	t;
	double	time_phase;
	int		brightness;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	time_phase = time * 0.3;
	brightness = (int)(255 * (0.5 + 0.5 * cos(t * 10.0 + time_phase)));
	if (brightness < 0)
		brightness = 0;
	else if (brightness > 255)
		brightness = 255;
	return ((brightness << 24) | (brightness << 16) | (brightness << 8) | 0xFF);
}

void	init_psychedelic_animated(t_color *color, double smooth_iter,
		int max_i, double time)
{
	if (smooth_iter >= max_i)
		return ;
	color->t = smooth_iter / max_i;
	color->time_phase = time * 0.5;
	color->phase = color->t * 15.0 + color->time_phase;
	color->r = (int)(127.5 + 127.5 * sin(color->phase));
	color->g = (int)(127.5 + 127.5 * sin(color->phase + 2.094
				+ sin(color->time_phase * 0.3) * 0.5));
	color->b = (int)(127.5 + 127.5 * sin(color->phase + 4.188
				+ cos(color->time_phase * 0.2) * 0.5));
}

void	apply_animated_effects(t_color *color)
{
	color->r = (int)(color->r * (0.8 + 0.2 * sin(color->t * 5.0
					+ color->time_phase)));
	color->g = (int)(color->g * (0.8 + 0.2 * cos(color->t * 7.0
					+ color->time_phase * 0.7)));
	color->b = (int)(color->b * (0.8 + 0.2 * sin(color->t * 11.0
					+ color->time_phase * 0.5)));
}

int	psychedelic_animated(double smooth_iter, int max_i, double time)
{
	t_color	color;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	init_psychedelic_animated(&color, smooth_iter, max_i, time);
	apply_animated_effects(&color);
	clamp_color_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}
