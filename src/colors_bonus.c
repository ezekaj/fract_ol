/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

int	color_classic(double t, double tp)
{
	t_color	c;

	c.r = (int)(200 + 55 * sin(t * 5.0 + tp));
	c.g = c.r;
	c.b = 255;
	clamp_color(&c);
	return (pack_color(&c));
}

int	color_blue(double t, double tp)
{
	t_color	c;

	c.r = (int)(80 + 60 * sin(t * 4.0 + tp * 0.5));
	c.g = (int)(120 + 80 * sin(t * 6.0 + 1.0 + tp * 0.7));
	c.b = (int)(220 + 35 * sin(t * 8.0 + 2.0 + tp));
	clamp_color(&c);
	return (pack_color(&c));
}

int	color_fire(double t, double tp)
{
	t_color	c;

	c.r = 255;
	c.g = (int)(150 * t * (1.0 + 0.5 * sin(t * 12.0 + tp)));
	c.b = (int)(100 * t * t * (1.0 + 0.5 * sin(t * 16.0 + tp * 1.3)));
	clamp_color(&c);
	return (pack_color(&c));
}

int	color_psychedelic(double t, double tp)
{
	t_color	c;

	c.phase = t * 6.283185 + tp;
	c.r = (int)(127.5 + 127.5 * sin(c.phase));
	c.g = (int)(127.5 + 127.5 * sin(c.phase + 2.094));
	c.b = (int)(127.5 + 127.5 * sin(c.phase + 4.188));
	clamp_color(&c);
	return (pack_color(&c));
}

int	color_grayscale(double t, double tp)
{
	int	brightness;

	brightness = (int)(255 * (0.5 + 0.5 * cos(t * 3.14159 + tp)));
	if (brightness < 0)
		brightness = 0;
	if (brightness > 255)
		brightness = 255;
	return ((brightness << 16) | (brightness << 8) | brightness);
}
