/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:11:17 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/12 19:35:46 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	s;
	
	i = 0;
	j = 0;
	while (i < dstsize && dst[j])
		j++;
	s = j;
	while (j + 1 < dstsize && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	if (s < dstsize)
		dst[j] = '\0';
	return (s + ft_strlen(src));
}
