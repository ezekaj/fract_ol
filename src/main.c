/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:00 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 21:52:04 by ezekaj           ###   ########.fr       */
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
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		return (MANDELBROT);
	else if (ft_strncmp(av[1], "julia", 5) == 0)
		return (JULIA);
	else if (ft_strncmp(av[1], "tricorn", 7) == 0)
		return (TRICORN);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.type = parse_args(ac, av);
	if (!fractol.type)
		print_usage();
	fractol.mlx = mlx_init(WIDTH, HEIGHT, TITLE, 1);
	if (!fractol.mlx)
		return (1);
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	if (!fractol.img)
		return (mlx_terminate(fractol.mlx), 1);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	init_fractol(&fractol, fractol.type, av);
	mlx_image_to_window(fractol.mlx, fractol.img, 0, 0);
	mlx_key_hook(fractol.mlx, &handle_keys, &fractol);
	mlx_scroll_hook(fractol.mlx, &handle_scroll, &fractol);
	mlx_mouse_hook(fractol.mlx, &handle_mouse_click, &fractol);
	if (fractol.use_threads)
		threaded_fractal_render(&fractol);
	else
		fractal_render(&fractol);
	mlx_loop_hook(fractol.mlx, &animation_loop, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (0);
}
