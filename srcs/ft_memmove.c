/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:00:54 by asimoes           #+#    #+#             */
/*   Updated: 2020/04/27 22:52:35 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	temp[n];
	unsigned char	*s;
	unsigned char	*d;

	if (src == dest)
		return (dest);
	i = 0;
	s = (unsigned char *)src;
	d = dest;
	while (i < n)
		temp[i++] = *s++;
	n = i;
	i = 0;
	while (i < n)
		*d++ = temp[i++];
	return (dest);
}
