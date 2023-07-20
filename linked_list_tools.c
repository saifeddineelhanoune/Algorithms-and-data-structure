#include <libc.h>

#include "push_swap.h"

t_stack *ft_lstnew(int content)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return NULL;
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst)
	{
		new->index = 0;
		*lst = new;
	}
}

int		ft_lst_size(t_stack *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_stack *ft_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return lst;
		lst = lst->next;
	}
	return NULL;
}

void ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack *node;
	
	node = ft_lstlast(*lst);
	if (!node)
		ft_lstadd_front(lst, new);
	else {
		new->index = ft_lst_size(*lst);
		node->next = new;
	}
}

void swap(t_stack **list)
{
	t_stack *tmp;

	if (*list && (*list)->next)
	{
		tmp = (*list)->next;
		(*list)->next = tmp->next;
		tmp->next = *list;
		*list = tmp;
	}
}

void push(t_stack **list1, t_stack **list2)
{
	t_stack *tmp;

	if (*list1)
	{
		tmp = (*list1)->next;
		(*list1)->next = *list2;
		*list2 = *list1;
		*list1 = tmp;
	}
}

void rotate(t_stack **list)
{
	t_stack *tmp;
	t_stack *node;

	if (*list && (*list)->next)
	{
		tmp = *list;
		*list = (*list)->next;
		node = ft_lstlast(*list);
		node->next = tmp;
		tmp->next = NULL;
	}
}

void reverse_rotate(t_stack **list)
{
	t_stack *tmp;
	t_stack *node;

	if (*list && (*list)->next)
	{
		node = *list;
		while (node->next->next)
			node = node->next;
		tmp = node->next;
		node->next = NULL;
		tmp->next = *list;
		*list = tmp;
	}
}

void swap_both(t_stack **list1, t_stack **list2)
{
	swap(list1);
	swap(list2);
}

void push_both(t_stack **list1, t_stack **list2)
{
	push(list1, list2);
	push(list2, list1);
}
