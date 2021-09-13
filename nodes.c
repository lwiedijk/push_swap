/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nodes.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 15:00:16 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/13 11:08:17 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

t_stack	*new_stack_node(long int input)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->to_sort = input;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*last_node(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	add_node_back(t_stack **lst, t_stack *new)
{
	t_stack *last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = last_node(*lst);
		last->next = new;
		new->prev = last;
	}
}

void	add_node_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = (*lst);
	(*lst) = new;
	new->next->prev = new;
}

void	print_stack_list_forward(t_stack *lst, int (*f)(const char *, ...), char stack_char)
{
	int i;

	i = 0;
	if (!lst || !f)
	{
		printf("No stack_%c to print\n", stack_char);
		return ;
	}
	while (lst)
	{
		f("node[%d] of stack_%c: (%d)\n", i, stack_char, lst->to_sort);
		lst = lst->next;
		i++;
	}
}

void	stack_iter_forward(t_stack *lst, int (*f)(const char *, ...))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f("printlist: input: (%d)\n", lst->to_sort);
		lst = lst->next;
	}
}

void	stack_iter_backward(t_stack *lst, int (*f)(const char *, ...))
{
	if (!lst || !f)
		return ;
	lst = last_node(lst);
	while (lst)
	{
		f("printlist__backward: input: (%d)\n", lst->to_sort);
		lst = lst->prev;
	}
}

void	del_first_node(t_stack **lst)
{
	t_stack *temp;

	temp = *lst;
	if (!*lst)
		return ;
	*lst = (*lst)->next;
	free(temp);
}
