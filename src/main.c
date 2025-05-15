#include "../inc/fractol.h"

// #define WIDTH 800
// #define HEIGHT 500

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Fractol", 1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}
