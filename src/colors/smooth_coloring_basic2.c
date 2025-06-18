/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_coloring_basic2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:00:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"



void	init_psychedelic_color(t_color *color, double smooth_iter, int max_i)
{
	if (smooth_iter >= max_i)
		return ;
	color->t = smooth_iter / max_i;
	color->phase = color->t * 15.0;
	color->r = (int)(127.5 + 127.5 * sin(color->phase));
	color->g = (int)(127.5 + 127.5 * sin(color->phase + 2.094));
	color->b = (int)(127.5 + 127.5 * sin(color->phase + 4.188));
}

void	apply_psychedelic_effects(t_color *color)
{
	color->r = (int)(color->r * (0.8 + 0.2 * sin(color->t * 5.0)));
	color->g = (int)(color->g * (0.8 + 0.2 * cos(color->t * 7.0)));
	color->b = (int)(color->b * (0.8 + 0.2 * sin(color->t * 11.0)));
}

int	smooth_color_psychedelic(double smooth_iter, int max_i)
{
	t_color	color;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	init_psychedelic_color(&color, smooth_iter, max_i);
	apply_psychedelic_effects(&color);
	clamp_color_values(&color);
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 0xFF);
}

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
