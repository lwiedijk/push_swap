/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 14:36:02 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/14 13:03:56 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

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

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last;

	if (*stack_a)
	{
		last = last_node(*stack_b);
		if (last)
		{
			last->next = *stack_a;
			*stack_a = (*stack_a)->next;
			(*stack_a)->prev = NULL;
			last->next->next = NULL;
			last->prev = last->next;
		}
		else
		{
			*stack_b = *stack_a;
			*stack_a = (*stack_a)->next;
			(*stack_a)->prev = NULL;
			(*stack_b)->prev = NULL;
			(*stack_b)->next = NULL;
		}
	}
	write(1, "pb\n", 3);
}
