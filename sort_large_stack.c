/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large_stack.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 09:40:23 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/08 11:37:53 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	get_index_position(t_stack *stack_a, t_stack *stack_array, int stack_count)
{
	long int	temp_num;
	t_stack		*temp_head;
	int			i;
	int			j;
	
	temp_head = stack_a;
	i = 0;
	while (i < stack_count)
	{
		j = 1 + i;
		while (j < stack_count)
		{
			if (stack_array[i].to_sort > stack_array[j].to_sort)
			{
				temp_num = stack_array[i].to_sort;
				stack_array[i].to_sort = stack_array[j].to_sort;
				stack_array[j].to_sort = temp_num;
			}
			j++;
		}
		i++;
	}

}

void	put_stack_to_array(t_stack *stack_a, int stack_count)
{
	t_stack	*temp_head;
	t_stack	*stack_array;
	int	i;

	temp_head = stack_a;
	stack_array = (t_stack *)malloc(sizeof(t_stack) * stack_count);
	if (!stack_array)
		ft_error(ERROR);
	i = 0;
	while (i < stack_count)
	{
		stack_array[i] = *temp_head;
		//temp_head->index = i; pas na gesorteerd tuurlijk
		temp_head = temp_head->next;
		i++;
	}
	//stack_array[i] = NULL; dit werkt niet want geen node, is 0 termination nodig hier? 
	get_index_position(stack_a, stack_array, stack_count);
	free(stack_array);

	
	
}

void	sort_large_stack(t_stack **stack_a, t_stack **stack_b, int stack_count)
{
	put_stack_to_array(*stack_a, stack_count);
	stack_b = stack_a; //remove
}