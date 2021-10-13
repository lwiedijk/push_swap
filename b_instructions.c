/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 14:36:02 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/13 09:56:24 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	rb(t_stack **stack_b, int rr_flag)
{
	t_stack	*last;

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

void	pb(t_stack **stack_a, t_stack **stack_b,
			t_stack *temp_a, t_stack *temp_b)
{
	if (*stack_a)
	{
		if ((*stack_a)->next)
			temp_a = (*stack_a)->next;
		*stack_b = *stack_a;
		if ((*stack_a)->next)
			*stack_a = temp_a;
		else
			*stack_a = NULL;
		if (temp_b)
		{
			(*stack_b)->next = temp_b;
			(*stack_b)->next->prev = *stack_b;
		}
		else
			(*stack_b)->next = NULL;
		if (*stack_a)
			(*stack_a)->prev = NULL;
		(*stack_b)->prev = NULL;
	}
	write(1, "pb\n", 3);
}
