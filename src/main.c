#include "../inc/fractol.h"

int	main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractol	fractol;

	if (ac >= 2)
	{
		mlx = mlx_init(WIDTH, HEIGHT, "Fractol", 1);
		img = mlx_new_image(mlx, WIDTH, HEIGHT);
		fractol.mlx = mlx;
		fractol.img = img;
		mlx_image_to_window(mlx, img, 0, 0);
		mlx_loop(mlx);
	}
}
