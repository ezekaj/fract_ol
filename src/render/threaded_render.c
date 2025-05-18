/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threaded_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:30:38 by ezekaj            #+#    #+#             */
/*   Updated: 2025/05/18 23:43:47 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	*render_thread(void *arg)
{
	t_thread_data	*data;
	int				y;

	data = (t_thread_data *)arg;
	y = data->start_y;
	while (y < data->end_y)
	{
		render_row(y, data->fractol);
		y++;
	}
	return (NULL);
}

void	threaded_fractal_render(t_fractol *fractol)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];
	int				i;
	int				rows_per_thread;

	rows_per_thread = HEIGHT / NUM_THREADS;
	i = 0;
	while (i < NUM_THREADS)
	{
		thread_data[i].fractol = fractol;
		thread_data[i].start_y = i * rows_per_thread;
		thread_data[i].end_y = (i == NUM_THREADS - 1) ?	HEIGHT : (i + 1) * rows_per_thread;
		pthread_create(&threads[i], NULL, render_thread, &thread_data[i]);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	if (fractol->show_ui)
		render_ui_text(fractol);
}
