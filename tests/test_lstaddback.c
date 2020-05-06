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

	if (!(list = malloc(sizeof(struct s_list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	unsigned int	i;

	if (alst[0] == NULL)
	{
		printf("alst is 0\n");
		alst[0] = new;
		return ;
	}
	i = 0;
	while (alst[i]->next != NULL)
		i++;
	alst[i]->next = new;
}

int main()
{
	t_list *l = ((void*)0);
	t_list *n = ft_lstnew(strdup("OK"));

	printf("lstnew ok\n");
	ft_lstadd_back(&l, n);
	printf("lstadd_back ok\n");
	if (l == n && !strcmp(l->content, "OK"))
	{
		free(l->next);
		free(l);
		printf("Success\n");
		return (0);
	}
	free(l->next);
	free(l);
	printf("Failed");

	return (0);
}