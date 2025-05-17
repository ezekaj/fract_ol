#include "../inc/fractol.h"

static void	print_usage(void)
{
	printf("Usage: ./fractol [fractal_type] [params]\n\n");
	printf("Fractal types:\n");
	printf("  mandelbrot\n");
	printf("  julia [c_real] [c_imag]\n");
	printf("  burning\n\n");
	printf("Examples:\n");
	printf("  ./fractol mandelbrot\n");
	printf("  ./fractol julia -0.7 0.27015\n");
	printf("  ./fractol burning\n");
	exit(0);
}

static int	get_fractal_type(char *arg)
{
	if (!arg)
		return (0);
	
	if (strcmp(arg, "mandelbrot") == 0)
		return (MANDELBROT);
	if (strcmp(arg, "julia") == 0)
		return (JULIA);
	if (strcmp(arg, "burning") == 0)
		return (BURNING);
	
	return (0);
}

int	main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractol	fractol;
	int			type;

	if (ac < 2)
		print_usage();

	type = get_fractal_type(av[1]);
	if (type == 0)
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
