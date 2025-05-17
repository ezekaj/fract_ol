#include "../inc/fractol.h"

void	map(int x, int y, double *real, double *imag, t_fractol *fractol)
{
	*real = (x - WIDTH / 2.0) * 3.0 / WIDTH - 0.5;
	*imag = (y - HEIGHT / 2.0) * 3.0 / HEIGHT;
}
