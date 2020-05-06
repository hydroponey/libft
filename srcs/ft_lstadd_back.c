/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:44:29 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/06 23:38:28 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	unsigned int	i;

	if (alst[0] == NULL)
	{
		alst[0] = new;
		return ;
	}
	i = 0;
	while (alst[i]->next != NULL)
		i++;
	alst[i]->next = new;
}
