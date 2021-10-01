/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 16:15:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/01 09:22:51 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include <stdio.h>

void	ft_error(int error_code)
{
	write(2, "Error\n", 6);
	if (error_code == TEST)
		printf("test ended in error\n"); //remove printf!
	exit(1);
}

int	list_is_sorted(t_stack *stack)
{
	long	int compare1;
	long	int compare2;

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
			return (1);
		lst = lst->next;
	}
	return (0);
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
