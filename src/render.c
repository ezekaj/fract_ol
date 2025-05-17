#include "../inc/fractol.h"

void	map(int x, int y, double *real, double *imag, t_fractol *fractol)
{
	*real = (x - WIDTH / 2.0) * 3.0 / WIDTH - 0.5;
	*imag = (y - HEIGHT / 2.0) * 3.0 / HEIGHT;
}

int	colors(int i, int max_i)
{
	int	brightness;

	if (i == max_i)
		return (0x000000FF);
	brightness = (i * 255) / max_i;
	return ((brightness << 24) | (brightness << 16) | (0xFF << 8) | 0xFF);
}
