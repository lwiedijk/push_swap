/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 14:36:02 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/29 11:00:41 by lwiedijk      ########   odam.nl         */
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

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
	{
		t_stack *temp_a;
		t_stack *temp_b;

		if ((*stack_b)->next)
			temp_b = (*stack_b)->next;
		else
			temp_b = *stack_b;
		temp_a = *stack_a;
		
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

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
	{
		t_stack *temp_a;
		t_stack *temp_b;

		temp_a = (*stack_a)->next;
		temp_b = *stack_b;
	
		*stack_b = *stack_a;
		*stack_a = temp_a;
		if (temp_b)
		{
			(*stack_b)->next = temp_b;
			(*stack_b)->next->prev = *stack_b;
		}
		else
			(*stack_b)->next = NULL;
		(*stack_a)->prev = NULL;
		(*stack_b)->prev = NULL;
			
	}
	write(1, "pb\n", 3);
}
