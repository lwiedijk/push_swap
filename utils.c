/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 16:15:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/13 11:47:20 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void	ft_error(int error_code)
{
	if (error_code == ERROR)
		write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

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
	while (stack->next != NULL)
	{
		if (num_is_same(stack->next, stack->to_sort))
			ft_error(ERROR);
		stack = stack->next;
	}
}

void	check_isdigit(char **split_array, int arg_amount)
{
	int	i;
	int	j;

	i = 0;
	while (i < arg_amount)
	{
		j = 0;
		while (split_array[i][j])
		{
			if (!ft_isdigit(split_array[i][j]))
				ft_error(ERROR);
			j++;
		}
		i++;
	}
}

void	check_min_max(t_stack *stack)
{
	while (stack)
	{
		if (stack->to_sort > INT_MAX || stack->to_sort < INT_MIN)
			ft_error(ERROR);
		stack = stack->next;
	}
}
