#include "../inc/fractol.h"

#define WIDTH 800
#define HEIGHT 500

int	main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Fractol", 1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
}
