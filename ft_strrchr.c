/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:53:35 by asimoes           #+#    #+#             */
/*   Updated: 2020/04/29 04:06:17 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occur;

	last_occur = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			last_occur = (char*)s;
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return (last_occur);
}