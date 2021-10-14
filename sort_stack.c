/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/14 09:23:36 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/14 09:31:31 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	list_is_sorted(t_stack *stack)
{
	long int	compare1;
	long int	compare2;

	if (!stack)
		return (FALSE);
	while (stack->next != NULL)
	{
		compare1 = stack->to_sort;
		stack = stack->next;
		compare2 = stack->to_sort;
		if (compare1 > compare2)
			return (FALSE);
	}
	return (TRUE);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int stack_count)
{
	if (stack_count <= 3)
	{
		if (!list_is_sorted(*stack_a))
			sort_mini_stack(stack_a);
	}
	else if (stack_count <= 5)
	{
		if (!list_is_sorted(*stack_a))
			sort_small_stack(stack_a, stack_b);
	}
	else
		if (!list_is_sorted(*stack_a))
			sort_large_stack(stack_a, stack_b, stack_count);
}
