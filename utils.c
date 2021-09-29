/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 16:15:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/29 16:18:59 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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