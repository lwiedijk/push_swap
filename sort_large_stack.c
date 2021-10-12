/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large_stack.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 09:40:23 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/12 14:34:57 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	radix_binary(t_stack **stack_a, t_stack **stack_b,
						int bit_count, int stack_count)
{	
	int	i;
	int	node_count;

	i = 0;
	while (i < bit_count)
	{
		node_count = 0;
		while (node_count < stack_count)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a, FALSE);
			node_count++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

int	numlen_in_bits(int stack_count)//put in utils or smth
{
	int	len;

	len = 0;
	while (stack_count)
	{
		stack_count = stack_count / 2;
		len++;
	}
	return (len);
}

void	sort_large_stack(t_stack **stack_a, t_stack **stack_b, int stack_count)
{
	int	bit_count;

	simplify_stack_input(*stack_a, stack_count);
	bit_count = numlen_in_bits(stack_count);
	radix_binary(stack_a, stack_b, bit_count, stack_count);
}
