/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   nodes.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 15:00:16 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/02 15:04:09 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

t_stack	*new_stack_node(int input, int node_num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->to_sort = input;
	new->node_num = node_num;
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

void	stack_iter_forward(t_stack *lst, int (*f)(const char *, ...))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f("printlist: node[%d], input: (%d)\n", lst->node_num, lst->to_sort);
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
		f("printlist__backward: node[%d], input: (%d)\n", lst->node_num, lst->to_sort);
		lst = lst->prev;
	}
}
