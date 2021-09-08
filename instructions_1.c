/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 14:36:02 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/08 14:20:32 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *stack_a)
{
	long int	temp;
	
	if (stack_a->next)
	{
		temp = stack_a->to_sort;
		stack_a->to_sort = stack_a->next->to_sort;
		stack_a->next->to_sort = temp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	long int	temp;
	
	if (stack_b && stack_b->next)
	{
		temp = stack_b->to_sort;
		stack_b->to_sort = stack_b->next->to_sort;
		stack_b->next->to_sort = temp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	long int	temp;

	if (stack_b && stack_a)
	{
		temp = stack_a->to_sort;
		stack_a->to_sort = stack_b->to_sort;
		stack_b->to_sort = temp;
	}
	write(1, "ss\n", 3);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	long int	temp;
	t_stack		*new_node;

	if (stack_b)
	{
		temp = stack_b->to_sort;
		new_node = new_stack_node(temp);
		add_node_front(&stack_a, new_node);
	}
	write(1, "pa\n", 3);
}

t_stack	*pb(t_stack *stack_a, t_stack *stack_b)
{
	long int	temp;

	temp = stack_a->to_sort;

	//remove that node
	del_first_node(&stack_a);
	stack_b = new_stack_node(temp);
	if (!stack_b)
		ft_error(MALLOC_FAIL);
	return (stack_b);
}
