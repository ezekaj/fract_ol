/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoline-eater <gasoline-eater@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/17 23:05:20 by gasoline-ea      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/fractol.h"

static void	print_usage(void)
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
	if (write(1, "Examples:\n", 10) < 0)
		exit(1);
	if (write(1, "  ./fractol mandelbrot\n", 23) < 0)
		exit(1);
	if (write(1, "  ./fractol julia -0.7 0.27015\n", 31) < 0)
		exit(1);
	if (write(1, "  ./fractol tricorn\n", 20) < 0)
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
	else if (strncmp(av[1], "tricorn", 7) == 0)
		return (TRICORN);
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
	mlx_mouse_hook(mlx, &handle_mouse_click, &fractol);

	if (fractol.use_threads)
		threaded_fractal_render(&fractol);
	else
		fractal_render(&fractol);
	mlx_loop_hook(mlx, &animation_loop, &fractol);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
