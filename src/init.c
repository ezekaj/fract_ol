/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/19 01:30:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	set_default_values(t_fractol *f, int type)
{
	f->type = type;
	f->zoom = 1.0;
	f->max_iter = MAX_ITER;
	f->color_scheme = 0;
	f->julia_locked = 1;
	if (type == MANDELBROT)
		f->offset_x = -0.5;
	else
		f->offset_x = 0.0;
	f->offset_y = 0.0;
}

void	set_julia_params(t_fractol *f, char **av)
{
	if (av[2] && av[3])
	{
		f->c_real = ft_atof(av[2]);
		f->c_imag = ft_atof(av[3]);
	}
	else
	{
		f->c_real = -0.7;
		f->c_imag = 0.27015;
	}
}

void	init_fractol(t_fractol *f, int type, char **av)
{
	set_default_values(f, type);
	if (type == JULIA)
		set_julia_params(f, av);
}
