/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:39:42 by ezekaj            #+#    #+#             */
/*   Updated: 2025/04/14 14:51:13 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char **buffer, char *list)
{
	size_t	i;
	size_t	j;
	char	*news;

	i = -1;
	j = -1;
	if (!*buffer)
	{
		*buffer = malloc(1);
		(*buffer)[0] = 0;
	}
	news = malloc(ft_strlen(list) + ft_strlen(*buffer) + 1);
	if (news == NULL)
		return (NULL);
	while ((*buffer)[++i])
		news[i] = (*buffer)[i];
	while (list[++j])
		news[i + j] = list[j];
	news[i + j] = 0;
	free(*buffer);
	*buffer = news;
	return (*buffer);
}
