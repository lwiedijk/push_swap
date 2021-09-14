/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 09:31:11 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/14 11:28:50 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	ra(t_stack **stack_a)
{
	t_stack *temp;
	t_stack *last;

	if (*stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		last = last_node(*stack_a);
		last->next = temp;
		last->next->prev = last->next;
		last->next->next = NULL;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack *last;

	if (*stack_b && (*stack_b)->next)
	{
		last = last_node(*stack_b);
		last->next = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		last->next->next = NULL;
		last->next->prev = last->next;
	}
	write(1, "rb\n", 3);
}