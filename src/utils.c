#include "../inc/fractol.h"

size_t	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	printf("%zu\n", ft_strlen("123"));
// }
