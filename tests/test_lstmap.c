#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void *content)
{
	t_list *list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

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
		{
			new->next = cur;
			new = cur;
		}
		else
		{
			start = cur;
			new = cur;
		}
		if (del != NULL)
			del(lst->content);
		lst = lst->next;
	}
	return (start);
}

void *		lstmap_f(void *content) {
	(void)content;
	return ("OK !");
}

int main(void)
{
	printf("ok");
	t_list	*l = ft_lstnew(strdup(" 1 2 3 "));
	t_list	*ret;
	(void)&l;
	(void)&ret;
	l->next = ft_lstnew(strdup("ss"));
	l->next->next = ft_lstnew(strdup("-_-"));
	ret = ft_lstmap(l, lstmap_f, NULL);
	printf("l->content\t\t|\t\tret->content\n");
	printf("%s\t\t\t|\t\t%s\n", (char*)l->content, (char*)ret->content);
	printf("%s\t\t\t|\t\t%s\n", (char*)l->next->content, (char*)ret->next->content);
	printf("%s\t\t\t|\t\t%s\n", (char*)l->next->next->content, "");
	if (!strcmp(ret->next->next->content, "OK !"))
		printf("Test 3 OK\n");
	if (!strcmp(l->content, " 1 2 3 "))
		printf("Test 4 OK\n");
	if (!strcmp(l->next->content, "ss"))
		printf("Test 5 OK\n");
	if (!strcmp(l->next->next->content, "-_-"))
		printf("Test 6 OK\n");
	return (0);
}