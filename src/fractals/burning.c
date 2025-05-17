#include "../../inc/fractol.h"

int	burning_ship(double real, double imag, int max_i)
{
	double	z_real;
	double	z_imag;
	double	tmp;
	int		i;

	z_real = 0;
	z_imag = 0;
	i = 0;
	while (i < max_i)
	{
		if ((z_real * z_real + z_imag * z_imag) > 4.0)
			break ;
		z_real = fabs(z_real);
		z_imag = fabs(z_imag);
		tmp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = tmp;
		i++;
	}
	return (i);
}
