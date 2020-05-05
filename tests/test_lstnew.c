#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
	t_list *list = ft_lstnew(NULL);

	if (!list->content)
		printf("Success\n");
	printf("list: %p\n", list);
	printf("list->content: %p\n", (char *)list->content);
	printf("list->next: %p\n", list->next);
}