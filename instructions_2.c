/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 09:31:11 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/13 14:27:58 by lwiedijk      ########   odam.nl         */
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