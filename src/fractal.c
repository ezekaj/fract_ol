/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mandelbrot(double real, double imag, int max_i)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		i;

	z_real = 0;
	z_imag = 0;
	i = 0;
	while (z_real * z_real + z_imag * z_imag < 4 && i < max_i)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = temp;
		i++;
	}
	return (i);
}

int	julia(double real, double imag, t_fractol *f)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		i;

	z_real = real;
	z_imag = imag;
	i = 0;
	while (z_real * z_real + z_imag * z_imag < 4 && i < f->max_iter)
	{
		temp = z_real * z_real - z_imag * z_imag + f->c_real;
		z_imag = 2 * z_real * z_imag + f->c_imag;
		z_real = temp;
		i++;
	}
	return (i);
}

int	calc_pixel(double real, double imag, t_fractol *f)
{
	if (f->type == MANDELBROT)
		return (mandelbrot(real, imag, f->max_iter));
	return (julia(real, imag, f));
}
