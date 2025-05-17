/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_coloring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 23:33:08 by gasoline-ea      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/fractol.h"

double	calculate_smooth_value(double z_real, double z_imag, int iter, int max_i)
{
	double	log_zn;
	double	nu;

	if (iter == max_i)
		return ((double)iter);
	log_zn = log(z_real * z_real + z_imag * z_imag) / 2.0;
	nu = log(log_zn / log(2.0)) / log(2.0);
	return (iter + 1 - nu);
}

int	smooth_color_classic(double smooth_iter, int max_i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	r = (int)(200 + 55 * sin(t * 5.0));
	g = (int)(200 + 55 * sin(t * 5.0));
	b = (int)(255);
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int	smooth_color_classic_animated(double smooth_iter, int max_i, double time)
{
	double	t;
	double	time_phase;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	time_phase = time * 0.3;
	r = (int)(200 + 55 * sin(t * 5.0 + time_phase));
	g = (int)(200 + 55 * sin(t * 5.0 + time_phase));
	b = (int)(255);
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

int	smooth_color_blue(double smooth_iter, int max_i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	r = (int)(80 + 60 * sin(t * 4.0));
	g = (int)(120 + 80 * sin(t * 6.0 + 1.0));
	b = (int)(220 + 35 * sin(t * 8.0 + 2.0));
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

int	smooth_color_blue_animated(double smooth_iter, int max_i, double time)
{
	double	t;
	double	time_phase;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	time_phase = time * 0.4;
	r = (int)(80 + 60 * sin(t * 4.0 + time_phase * 0.5));
	g = (int)(120 + 80 * sin(t * 6.0 + 1.0 + time_phase * 0.7));
	b = (int)(220 + 35 * sin(t * 8.0 + 2.0 + time_phase));
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

int	smooth_color_fire(double smooth_iter, int max_i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	r = (int)(255);
	g = (int)(150 * t * (1.0 + 0.5 * sin(t * 12.0)));
	b = (int)(100 * t * t * (1.0 + 0.5 * sin(t * 16.0)));
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

int	smooth_color_fire_animated(double smooth_iter, int max_i, double time)
{
	double	t;
	double	time_phase;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	time_phase = time * 0.6;
	r = (int)(255);
	g = (int)(150 * t * (1.0 + 0.5 * sin(t * 12.0 + time_phase)));
	b = (int)(100 * t * t * (1.0 + 0.5 * sin(t * 16.0 + time_phase * 1.3)));
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

int	smooth_color_psychedelic(double smooth_iter, int max_i)
{
	double	t;
	double	phase;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
	phase = t * 15.0;
	r = (int)(127.5 + 127.5 * sin(phase));
	g = (int)(127.5 + 127.5 * sin(phase + 2.094));
	b = (int)(127.5 + 127.5 * sin(phase + 4.188));
	r = (int)(r * (0.8 + 0.2 * sin(t * 5.0)));
	g = (int)(g * (0.8 + 0.2 * cos(t * 7.0)));
	b = (int)(b * (0.8 + 0.2 * sin(t * 11.0)));
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

int	smooth_color_psychedelic_animated(double smooth_iter, int max_i, double time)
{
	double	t;
	double	phase;
	double	time_phase;
	int		r;
	int		g;
	int		b;

	if (smooth_iter >= max_i)
		return (0x000000FF);
	t = smooth_iter / max_i;
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
