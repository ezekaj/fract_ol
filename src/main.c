#include "../inc/fractol.h"

static void	print_usage(void)
{
	if (write(1, "Usage: ./fractol [fractal_type]\n", 33) < 0)
		exit(1);
}

int	main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractol	fractol;
	
	if (ac >= 2)
	{
		mlx = mlx_init(WIDTH, HEIGHT, "Fractol", 1);
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
		mlx_image_to_window(mlx, img, 0, 0);
		fractal_render(&fractol);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
	else
		print_usage();
	return (0);
}
