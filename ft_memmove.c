/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:00:54 by asimoes           #+#    #+#             */
/*   Updated: 2020/04/29 15:41:54 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*s;
	unsigned char	*d;

	if (dest == src)
		return (dest);
	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	i = 0;
	if (src < dest)
		while (i < n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	return (dest);
}
