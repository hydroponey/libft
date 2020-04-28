/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:48:13 by asimoes           #+#    #+#             */
/*   Updated: 2020/04/28 13:09:48 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
        if (s1[i] != s2[i])
            return (unsigned char)(s1[i] - s2[i]);
        i++;
    }
    if ((s2[i] != '\0' || s1[i] != '\0') && i < n)
        return (unsigned char)(s1[i] - s2[i]);
    return (0);
}