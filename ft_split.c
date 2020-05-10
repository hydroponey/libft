/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:17:16 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/10 19:13:25 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strndup(char *str, unsigned int n)
{
	unsigned int	len;
	unsigned int	max;
	char			*copy;
	unsigned int	i;

	len = ft_strlen(str);
	max = (len <= n) ? len : n + 1;
	if (!(copy = malloc(sizeof(char) * max)))
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

static int		get_string_size(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static int		get_elem_count(const char *str, char c)
{
	int	i;
	int	count;
	int	len;
	int	string_len;

	len = ft_strlen(str);
	i = 0;
	string_len = 0;
	count = 0;
	while (str[i] && i < len)
	{
		string_len = get_string_size(&str[i], c);
		if (string_len == 0)
		{
			i += 1;
		}
		else
		{
			i += string_len;
			count++;
		}
	}
	return (count);
}

char			**ft_split(const char *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		len;
	int		string_len;

	if (!str || str[0] == '\0')
		return (NULL);
	if ((tab = malloc(sizeof(char *) * (get_elem_count(str, c) + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != c)
		{
			string_len = get_string_size(&str[i], c);
			tab[j++] = ft_strndup((char *)&str[i], string_len);
			i += string_len;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
