/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:20:33 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/06 23:35:59 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*new;
	t_list	*start;

	if (!lst)
		return (NULL);
	new = NULL;
	start = NULL;
	while (lst)
	{
		if (!(cur = malloc(sizeof(t_list))))
			return (NULL);
		cur->content = f(lst->content);
		cur->next = NULL;
		if (new != NULL)
			new->next = cur;
		else
			start = cur;
		if (del != NULL)
			del(lst->content);
		new = cur;
		lst = lst->next;
	}
	return (start);
}
