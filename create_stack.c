/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 13:17:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/01 15:20:36 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

t_stack	*new_stack_node(int input)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->sort = input;
	new->next = NULL;
	return (new);
}

t_stack	*is_node_last(t_stack *lst)
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
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		is_node_last(*lst)->next = new;
}


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

void	stack_iter(t_stack *lst, int (*f)(const char *, ...))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f("printlist %d\n", lst->sort);
		lst = lst->next;
	}
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
			stack = new_stack_node(input);
			if (!stack)
				ft_error(MALLOC_FAIL);
		}
		else
		{
			new = new_stack_node(input);
			if (!new)
				ft_error(MALLOC_FAIL);
			add_node_back(&stack, new);
		}
		i++;
	}
	stack_iter(stack, printf);
	
}
