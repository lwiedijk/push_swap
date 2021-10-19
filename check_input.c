/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 16:15:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/19 09:17:54 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"
#include "libft/libft.h"

void	ft_error(t_stack *stack_a)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (stack_a)
		free_list(stack_a);
	exit(EXIT_FAILURE);
}

static int	num_is_same(t_stack *lst, long int check)
{
	while (lst)
	{
		if (lst->to_sort == check)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

void	check_doubles_input(t_stack *stack)
{
	if (!stack)
		exit(EXIT_SUCCESS);
	while (stack->next != NULL)
	{
		if (num_is_same(stack->next, stack->to_sort))
			ft_error(stack);
		stack = stack->next;
	}
}

int	check_isdigit(char **split_array, int arg_amount)
{
	int	i;
	int	j;

	i = 0;
	while (i < arg_amount)
	{
		j = 0;
		while (split_array[i][j])
		{
			if (!ft_isdigit_min(split_array[i][j]))
				return (ERROR);
			else if (ft_isdigit_min(split_array[i][j])
						&& split_array[i][j + 1] == '-')
				return (ERROR);
			else if (split_array[i][j] == '-'
						&& !ft_isdigit_min(split_array[i][j + 1]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (OK);
}

void	check_min_max(t_stack *stack, int stack_count)
{
	while (stack)
	{
		if (stack->to_sort > INT_MAX || stack->to_sort < INT_MIN)
			ft_error(stack);
		stack = stack->next;
	}
	if (stack_count < 0)
		ft_error(stack);
}
