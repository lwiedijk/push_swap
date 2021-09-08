/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/02 14:36:02 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/08 11:08:49 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *stack_a)
{
	long int temp;
	
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
	long int temp;
	
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
	long int temp;

	if (stack_b && stack_a)
	{
		temp = stack_a->to_sort;
		stack_a->to_sort = stack_b->to_sort;
		stack_b->to_sort = temp;
	}
	write(1, "ss\n", 3);
}


