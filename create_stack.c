/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 13:17:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/01 09:45:41 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"

// Remove all printf!!! 

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *new;
	long int input;
	int i;
	int j;
	int stack_count;
	int arg_amount;
	char **split_array;

	if (ac < 2)
		exit (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < ac)
	{
		j = 0;
		split_array = ft_split(av[i], ' ', &arg_amount);
		check_isdigit(split_array, arg_amount);
		while(split_array[j])
		{
			input = ft_atoi(split_array[j]);
			if (!stack_a)
			{
				stack_a = new_stack_node(input);
				if (!stack_a)
					ft_error(ERROR);
			}
			else
			{
				new = new_stack_node(input);
				if (!new)
					ft_error(ERROR);
				add_node_back(&stack_a, new);
			}
			j++;
		}
		i++;
		free_split_array(split_array, arg_amount);
	}
	check_doubles_input(stack_a);
	check_min_max(stack_a);
	stack_count = count_list(stack_a);
	
	printf("stack_count = [%d]\n", stack_count);
	print_stack_list_forward(stack_a, &printf, 'a');
	print_stack_list_forward(stack_b, &printf, 'b');
	//print_stack_list_backward(stack_a, &printf, 'a');
	//print_stack_list_backward(stack_b, &printf, 'b');

	if (stack_count <= 3)
	{
		if (!list_is_sorted(stack_a))
			sort_mini_stack(&stack_a);
	}
	else if (stack_count <= 5)
	{
		if (!list_is_sorted(stack_a))
			sort_small_stack(&stack_a, &stack_b);
	}
	else
		printf("need sort large list\n");
	
	//sa(stack_a);
	//sb(stack_b);
	//ss(stack_a, stack_b);
	//pa(stack_a, stack_b);

	//pb(&stack_a, &stack_b);
	//pb(&stack_a, &stack_b);
	//pb(&stack_a, &stack_b);
	//print_stack_list_forward(stack_a, &printf, 'a');
	//print_stack_list_forward(stack_b, &printf, 'b');

	//ra(&stack_a, FALSE);
	//rb(&stack_b, FALSE);
	//rr(&stack_a, &stack_b);
	//rra(&stack_a, FALSE);
	//rrb(&stack_b, FALSE);
	//rrr(&stack_a, &stack_b);

	print_stack_list_forward(stack_a, &printf, 'a');
	print_stack_list_forward(stack_b, &printf, 'b');
	print_stack_list_backward(stack_a, &printf, 'a');
	print_stack_list_backward(stack_b, &printf, 'b');
	
	
	//if (list_is_sorted(stack_a))
	//	return (printf("list is sorted\n"));
	//return (printf("not sorted or stack_a is empty\n"));
	
	free_list(stack_a);
	free(stack_a);
	free_list(stack_b);
	if (stack_b)
		free(stack_b);
	//system("leaks push_swap");
	//exit(0);
}
