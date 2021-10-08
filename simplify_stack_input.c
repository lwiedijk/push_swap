/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simplify_stack_input.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 13:57:42 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/08 14:01:10 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdlib.h>

void	get_index_position(t_stack *stack_a, t_stack *stack_array, int stack_count)
{
	t_stack	*temp_head;
	int		i;

	i = 0;
	temp_head = stack_a;
	while (i < stack_count)
	{
		temp_head = stack_a;
		while (temp_head)
		{
			if (stack_array[i].to_sort == temp_head->to_sort)
			{
				temp_head->index = stack_array[i].index;
			}
			temp_head = temp_head->next;
		}
		i++;
	}

}

void	sort_stack_array(t_stack *stack_a, t_stack *stack_array, int stack_count)
{
	long int	temp_num;
	//t_stack		*temp_head;
	int			i;
	int			j;
	
	//temp_head = stack_a;
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
		stack_array[i].index = i;
		i++;
	}
	get_index_position(stack_a, stack_array, stack_count);
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
	sort_stack_array(stack_a, stack_array, stack_count);
	free(stack_array);
}
