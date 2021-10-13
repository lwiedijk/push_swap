/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small_stack.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 15:56:07 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/13 09:23:53 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int	top_of_mini_stack(t_stack *stack_a)
{
	long int	compare1;
	long int	compare2;
	long int	compare3;

	if (list_is_sorted(stack_a))
		return (DONT_SORT);
	if (stack_a->next->next == NULL)
	{
		sa(stack_a);
		return (DONT_SORT);
	}
	compare1 = stack_a->to_sort;
	compare2 = stack_a->next->to_sort;
	compare3 = stack_a->next->next->to_sort;
	if (compare1 > compare2 && compare1 > compare3)
		return (HIGHEST);
	else if (compare1 < compare2 && compare1 < compare3)
		return (LOWEST);
	else
	{
		if (compare2 < compare3)
			return (MIDDEL_LOW);
		else
			return (MIDDEL_HIGH);
	}
}

void	sort_mini_stack(t_stack **stack_a)
{
	int	stack_top;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	stack_top = top_of_mini_stack(*stack_a);
	if (stack_top == DONT_SORT)
		return ;
	if (stack_top == HIGHEST)
	{
		ra(stack_a, FALSE);
		if (!list_is_sorted(*stack_a))
			sa(*stack_a);
	}
	if (stack_top == LOWEST)
	{
		sa(*stack_a);
		ra(stack_a, FALSE);
	}
	if (stack_top == MIDDEL_LOW)
		sa(*stack_a);
	if (stack_top == MIDDEL_HIGH)
		rra(stack_a, FALSE);
}

void	find_middel_value(t_stack *stack_a, int *middle_value)
{
	t_stack	*temp_a;
	t_stack	*constant_stack_a;
	int		count;
	int		i;

	temp_a = stack_a;
	constant_stack_a = stack_a;
	i = 0;
	while (i < SMALL_STACK)
	{
		*middle_value = stack_a->to_sort;
		count = 0;
		temp_a = constant_stack_a;
		while (temp_a)
		{
			if (*middle_value > temp_a->to_sort)
				count++;
			temp_a = temp_a->next;
		}
		if (count == 2)
			break ;
		stack_a = stack_a->next;
		i++;
	}
}

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		middle_value;
	int		i;

	i = 0;
	find_middel_value(*stack_a, &middle_value);
	while (i < HALF_SMALL_STACK)
	{
		if ((*stack_a)->to_sort < middle_value)
		{
			pb(stack_a, stack_b, *stack_a, *stack_b);
			i++;
		}
		else
			ra(stack_a, FALSE);
	}
	sort_mini_stack(stack_a);
	if ((*stack_b)->to_sort > (*stack_b)->next->to_sort)
		pa(stack_a, stack_b, *stack_a, *stack_b);
	else
	{
		rb(stack_b, FALSE);
		pa(stack_a, stack_b, *stack_a, *stack_b);
	}
	pa(stack_a, stack_b, *stack_a, *stack_b);
}
