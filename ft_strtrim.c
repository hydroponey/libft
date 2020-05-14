/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:21:10 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/14 10:36:44 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_strndup(const char *str, unsigned int n)
{
	unsigned int	len;
	unsigned int	max;
	char			*copy;
	unsigned int	i;

	len = ft_strlen(str);
	max = (len < n) ? len : n;
	if (!(copy = (char *)malloc(sizeof(char) * (max + 1))))
		return (NULL);
	i = 0;
	while (i < max)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int				is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char					*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	char			*end;
	size_t			len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 != '\0' && is_in_set(*s1, set))
		s1++;
	len = ft_strlen(s1) - 1;
	while (is_in_set(s1[len--], set))
		end = s1;
	if (!(trimmed = (char *)malloc(sizeof(char) * (end - s1 + 1))))
		return (NULL);
	ft_strlcpy(trimmed, s1, end - s1 + 1);
	return (trimmed);
}
