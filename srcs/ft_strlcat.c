/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:11:17 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/04 14:46:39 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0 || dest_len >= size)
		return (src_len + size);
	i = 0;
	j = dest_len;
	while (src[i] && i < (size - dest_len - 1))
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (src_len > size ? src_len : src_len + size);
}
