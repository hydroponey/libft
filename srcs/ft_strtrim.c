/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:21:10 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/04 22:16:55 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short	is_in_set(char const c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	unsigned int	j;
	unsigned int	i;

	j = 0;
	i = 0;
	if (!s1 || s1[0] == '\0' || !set || set[0] == '\0')
		return (char*)(s1);
	if (!(trimmed = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[j])
	{
		if (is_in_set(s1[j], set))
			j++;
		else
			break ;
	}
	while (s1[j])
		trimmed[i++] = s1[j++];
	while (i > 0 && is_in_set(trimmed[i - 1], set))
	{
		trimmed[i-- - 1] = '\0';
	}
	trimmed[i] = '\0';
	return (trimmed);
}
