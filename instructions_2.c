/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 09:31:11 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/15 14:34:24 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	ra(t_stack **stack_a, int rr_flag)
{
	t_stack *temp; // like you now put in rb you dont need this temp, rewrite this
	t_stack *last;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		last = last_node(*stack_a);
		last->next = temp;
		last->next->prev = last;
		last->next->next = NULL;
	}
	if (!rr_flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int rr_flag)
{
	t_stack *last;

	if (*stack_b && (*stack_b)->next)
	{
		last = last_node(*stack_b);
		last->next = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		last->next->next = NULL;
		last->next->prev = last;
	}
	if (!rr_flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	write(1, "rr\n", 3);
}

void	rra(t_stack **stack_a, int rrr_flag)
{
	t_stack *last;

	if (*stack_a && (*stack_a)->next)
	{
		last = last_node(*stack_a);
		last->next = *stack_a;
		last->prev->next = NULL;
		*stack_a = last;
		(*stack_a)->prev = NULL;
		(*stack_a)->next->prev = *stack_a;
	
	}
	if (!rrr_flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int rrr_flag)
{
	t_stack *last;

	if (*stack_b && (*stack_b)->next)
	{
		last = last_node(*stack_b);
		last->next = *stack_b;
		last->prev->next = NULL;
		*stack_b = last;
		(*stack_b)->prev = NULL;
		(*stack_b)->next->prev = *stack_b;
	
	}
	if (!rrr_flag)
		write(1, "rra\n", 4);
}


