/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:18:15 by asimoes           #+#    #+#             */
/*   Updated: 2020/04/29 20:04:32 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*data;
	size_t			i;

	if (!(data = malloc(nmemb * size)))
		return (0);
	i = 0;
	while (i < size)
	{
		data[i] = 0;
		i++;
	}
	return (data);
}
