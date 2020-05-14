/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 04:06:50 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/14 04:55:27 by asimoes          ###   ########.fr       */
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

static const char		*ft_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
			return (str);
		str++;
	}
	return (NULL);
}

static void				ft_freetab(char **tab)
{
	while (*tab)
		free(*tab++);
	free(tab);
}

static int				get_elem_count(const char *s, char c)
{
	int			count;
	const char	*end;

	count = 0;
	end = NULL;
	while (*s)
	{
		if (*s != c)
		{
			end = ft_strchr(s, c);
			count++;
			if (!end)
				break ;
			s = end;
		}
		s++;
	}
	return (count);
}

char					**ft_split(char const *s, char c)
{
	char			**tab;
	const char		*end;
	unsigned int	c;

	if (!(tab = malloc(sizeof(char *) * (get_elem_count(s, c) + 1))))
		return (NULL);
	c = 0;
	while (*s)
	{
		if (*s != c)
		{
			end = ft_strchr(s, c);
			if (!(tab[c++] = ft_strndup(s, (!end) ? ft_strlen(s) : end - s)))
			{
				free_tab(tab);
				return (NULL);
			}
			if (!end)
				break ;
			s = end;
		}
		s++;
	}
	tab[c] = NULL;
	return (tab);
}
