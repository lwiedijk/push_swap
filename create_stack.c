/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 13:17:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/13 15:13:27 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"

void	ft_error(int error_code)
{
	if (error_code == ERROR)
		write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_stack	*create_stack(long int input, t_stack *stack_a)
{
	t_stack	*new;

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
	return (stack_a);
}

void	parse_arguments(int ac, char**av, t_stack **stack_a)
{
	int			i;
	int			j;
	long int	input;
	int			arg_amount;
	char		**split_array;

	i = 1;
	while (i < ac)
	{
		j = 0;
		split_array = ft_split_and_count(av[i], ' ', &arg_amount);
		check_isdigit(split_array, arg_amount);
		while (split_array[j])
		{
			input = ft_atol(split_array[j]);
			*stack_a = create_stack(input, *stack_a);
			j++;
		}
		i++;
		free_split_array(split_array, arg_amount);
	}
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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_count;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(EXIT_SUCCESS);
	parse_arguments(ac, av, &stack_a);
	check_doubles_input(stack_a);
	check_min_max(stack_a);
	stack_count = count_list(stack_a);
	sort_stack(&stack_a, &stack_b, stack_count);
	free_list(stack_a);
	free(stack_a);
	free_list(stack_b);
	if (stack_b)
		free(stack_b);
	exit(EXIT_SUCCESS);
}
