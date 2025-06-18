/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 23:41:12 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	calculate_pixel(double real, double imag, t_fractol *fractol)
{
	int				i;
	t_julia_params	params;

	i = 0;
	if (fractol->type == MANDELBROT)
		i = mandelbrot(real, imag, fractol->max_iter);
	else if (fractol->type == JULIA)
	{
		params.real = real;
		params.imag = imag;
		params.c_real = fractol->c_real;
		params.c_imag = fractol->c_imag;
		params.max_i = fractol->max_iter;
		i = julia(&params);
	}
	else if (fractol->type == TRICORN)
		i = tricorn(real, imag, fractol->max_iter);
	return (i);
}

void	render_row(int y, t_fractol *fractol)
{
	t_render_vars	vars;

	vars.x = 0;
	while (vars.x < WIDTH)
	{
		vars.map_params.x = vars.x;
		vars.map_params.y = y;
		vars.map_params.real = &vars.real;
		vars.map_params.imag = &vars.imag;
		map(&vars.map_params, fractol);
		vars.i = calculate_pixel(vars.real, vars.imag, fractol);
		process_pixel_color(&vars, fractol, y);
		vars.x++;
	}
}

void	fractal_render(t_fractol *fractol)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		render_row(y, fractol);
		y++;
	}
	if (fractol->show_ui)
		render_ui_text(fractol);
}
