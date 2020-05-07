/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:11:17 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/07 21:29:38 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0 || dest_len >= dstsize)
		return (src_len + dstsize);
	i = 0;
	j = dest_len;
	while (src[i] && i < (dstsize - dest_len - 1))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (src_len > dstsize ? src_len : src_len + dstsize);
}
