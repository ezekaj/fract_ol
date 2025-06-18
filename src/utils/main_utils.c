/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 00:00:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/06/18 00:00:00 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	print_usage_header(void)
{
	if (write(1, "Usage: ./fractol [fractal_type] [params]\n\n", 42) < 0)
		exit(1);
	if (write(1, "Fractal types:\n", 15) < 0)
		exit(1);
	if (write(1, "  mandelbrot\n", 13) < 0)
		exit(1);
	if (write(1, "  julia [c_real] [c_imag]\n", 26) < 0)
		exit(1);
	if (write(1, "  tricorn\n\n", 11) < 0)
		exit(1);
}

void	print_usage_examples(void)
{
	if (write(1, "Examples:\n", 10) < 0)
		exit(1);
	if (write(1, "  ./fractol mandelbrot\n", 23) < 0)
		exit(1);
	if (write(1, "  ./fractol julia -0.7 0.27015\n", 31) < 0)
		exit(1);
	if (write(1, "  ./fractol tricorn\n", 20) < 0)
		exit(1);
}

void	print_usage(void)
{
	print_usage_header();
	print_usage_examples();
	exit(0);
}

int	parse_args(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		return (MANDELBROT);
	else if (ft_strncmp(av[1], "julia", 5) == 0)
		return (JULIA);
	else if (ft_strncmp(av[1], "tricorn", 7) == 0)
		return (TRICORN);
	return (0);
}
