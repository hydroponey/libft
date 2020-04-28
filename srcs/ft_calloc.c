/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:18:15 by asimoes           #+#    #+#             */
/*   Updated: 2020/04/28 22:31:34 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*data;
	size_t	i;

	if (nmemb == 0)
		return (0);
	if (size == 0)
	{
		if (!(data = malloc(1)))
			return (0);
		return (data);
	}
	if (!(data = malloc(nmemb * size)))
		return (0);
	i = 0;
	while (i < size)
		data[i] = 0;
	return (data);
}