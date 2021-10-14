/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_instructions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 09:31:11 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/14 09:30:23 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	ra(t_stack **stack_a, int rr_flag)
{
	t_stack	*last;

	if (*stack_a && (*stack_a)->next)
	{
		last = last_node(*stack_a);
		last->next = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		last->next->next = NULL;
		last->next->prev = last;
	}
	if (!rr_flag)
		write(1, "ra\n", 3);
}

void	rra(t_stack **stack_a, int rrr_flag)
{
	t_stack	*last;

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

void	pa(t_stack **stack_a, t_stack **stack_b,
			t_stack *temp_a, t_stack *temp_b)
{
	if (*stack_b)
	{
		if ((*stack_b)->next)
			temp_b = (*stack_b)->next;
		*stack_a = *stack_b;
		if ((*stack_b)->next)
			*stack_b = temp_b;
		else
			*stack_b = NULL;
		if (temp_a)
		{
			(*stack_a)->next = temp_a;
			(*stack_a)->next->prev = *stack_a;
		}
		else
			(*stack_a)->next = NULL;
		if (*stack_b)
			(*stack_b)->prev = NULL;
		(*stack_a)->prev = NULL;
	}
	write(1, "pa\n", 3);
}
