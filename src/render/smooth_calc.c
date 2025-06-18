/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	calculate_mandelbrot_smooth(t_smooth_calc *calc)
{
	while (calc->j < calc->i)
	{
		calc->temp = calc->z_real * calc->z_real - calc->z_imag * calc->z_imag
			+ calc->real;
		calc->z_imag = 2 * calc->z_real * calc->z_imag + calc->imag;
		calc->z_real = calc->temp;
		calc->j++;
	}
}

void	calculate_julia_smooth(t_smooth_calc *calc)
{
	while (calc->j < calc->i)
	{
		calc->temp = calc->z_real * calc->z_real - calc->z_imag * calc->z_imag
			+ calc->fractol->c_real;
		calc->z_imag = 2 * calc->z_real * calc->z_imag + calc->fractol->c_imag;
		calc->z_real = calc->temp;
		calc->j++;
	}
}

void	calculate_tricorn_smooth(t_smooth_calc *calc)
{
	while (calc->j < calc->i)
	{
		calc->temp = calc->z_real * calc->z_real - calc->z_imag * calc->z_imag
			+ calc->real;
		calc->z_imag = -2 * calc->z_real * calc->z_imag + calc->imag;
		calc->z_real = calc->temp;
		calc->j++;
	}
}

void	calculate_smooth_values(t_smooth_calc *calc)
{
	calc->z_real = 0;
	calc->z_imag = 0;
	calc->j = 0;
	if (calc->fractol->type == MANDELBROT)
		calculate_mandelbrot_smooth(calc);
	else if (calc->fractol->type == JULIA)
		calculate_julia_smooth(calc);
	else if (calc->fractol->type == TRICORN)
		calculate_tricorn_smooth(calc);
	*(calc->smooth_i) = calc_smooth_value(calc->z_real, calc->z_imag,
			calc->i, calc->fractol->max_iter);
}
