/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:11:17 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/13 18:57:36 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	dstlen = (dstlen < dstsize) ? dstlen : dstsize;
	if (dstlen == dstsize) return dstsize+srclen;
	i = 0;
	if (srclen < dstsize-dstlen)
	{
		while (i < srclen + 1)
			dst[dstlen + i] = src[i];
	}
	else
	{
		while (i < dstsize - 1)
			dst[dstlen + i] = src[i];
		dst[dstlen + dstsize - 1] = '\0';
	}
	return dstlen + srclen;	
}
