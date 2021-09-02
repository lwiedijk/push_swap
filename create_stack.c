/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 13:17:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/02 14:22:27 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

void	ft_error(int error_code)
{
	if (error_code == TEST)
		printf("ended in error\n");
	if (error_code == WRONG_AC)
		printf("wrong amound of arguments where passed\n");
	if (error_code == MALLOC_FAIL)
		exit(1);
	exit(1);
}

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

void	free_list(t_stack *lst)
{
	if (!lst)
		return ;
	lst = last_node(lst);
	while (lst)
	{
		free(lst->next);
		lst = lst->prev;
	}
}

int	check_list_is_sorted(t_stack *stack)
{
	long int compare1;
	long int compare2;
	int i;

	i = 1;
	//stack = last_node(stack);
	while (stack->next != NULL)
	{
		compare1 = stack->to_sort;
			stack = stack->next;
		compare2 = stack->to_sort;
		if (compare1 > compare2)
			return (0);
		printf("running loop [%d]\n", i);
		i++;
	}
	printf("out of loop\n");
	return (1);
}

int	main(int ac, char **av)
{
	t_stack *stack;
	t_stack *new;
	int input;
	int i;

	if (ac < 2)
		ft_error(WRONG_AC);
	stack = NULL;
	i = 1;
	while (i < ac)
	{
		input = ft_atoi(av[i]);
		printf("input from atoi [%d] (%d)\n", i, input);
		if (!stack)
		{
			stack = new_stack_node(input, i);
			if (!stack)
				ft_error(MALLOC_FAIL);
		}
		else
		{
			new = new_stack_node(input, i);
			if (!new)
				ft_error(MALLOC_FAIL);
			add_node_back(&stack, new);
		}
		i++;
	}
	stack_iter_forward(stack, &printf);
	stack_iter_backward(stack, &printf);
	if (check_list_is_sorted(stack))
		printf("list is sorted\n");
	else
		printf("not sorted\n");
	free_list(stack);
	free(stack);
}
