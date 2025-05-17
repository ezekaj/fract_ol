/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 15:35:30 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	print_usage(void)
{
	if (write(1, "Usage: ./fractol [fractal_type] [params]\n\n", 42) < 0)
		exit(1);
	if (write(1, "Fractal types:\n", 15) < 0)
		exit(1);
	if (write(1, "  mandelbrot\n", 13) < 0)
		exit(1);
	if (write(1, "  julia [c_real] [c_imag]\n\n", 27) < 0)
		exit(1);
	if (write(1, "Examples:\n", 10) < 0)
		exit(1);
	if (write(1, "  ./fractol mandelbrot\n", 23) < 0)
		exit(1);
	if (write(1, "  ./fractol julia -0.7 0.27015\n", 31) < 0)
		exit(1);
	exit(0);
}

static int	parse_args(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (strncmp(av[1], "mandelbrot", 10) == 0)
		return (MANDELBROT);
	else if (strncmp(av[1], "julia", 5) == 0)
		return (JULIA);
	return (0);
}

int	main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractol	fractol;
	int			type;

	type = parse_args(ac, av);
	if (!type)
		print_usage();
	mlx = mlx_init(WIDTH, HEIGHT, TITLE, 1);
	if (!mlx)
		return (1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		mlx_terminate(mlx);
		return (1);
	}
	fractol.mlx = mlx;
	fractol.img = img;
	init_fractol(&fractol, type, av);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, &handle_keys, &fractol);
	mlx_scroll_hook(mlx, &handle_scroll, &fractol);
	fractal_render(&fractol);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
