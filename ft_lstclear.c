/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 00:05:52 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/14 11:23:14 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*next;

	if (del != NULL)
	{
		cur = *lst;
		while (cur != NULL)
		{
			next = cur->next;
			del(cur->content);
			free(cur);
			cur = next;
		}
		lst = NULL;
	}
}
