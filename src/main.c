#include "../inc/fractol.h"

static void	print_usage(void)
{
	write(1, "Usage: ./fractol [fractal_type] [params]\n\n", 42);
	write(1, "Fractal types:\n", 15);
	write(1, "  mandelbrot\n", 13);
	write(1, "  julia [c_real] [c_imag]\n\n", 27);
	write(1, "Examples:\n", 10);
	write(1, "  ./fractol mandelbrot\n", 23);
	write(1, "  ./fractol julia -0.7 0.27015\n", 31);
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
