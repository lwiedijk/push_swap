/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 09:43:16 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/14 09:30:10 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	free_list(t_stack *lst)
{
	if (!lst)
		return ;
	lst = last_node(lst);
	while (lst)
	{
		free(lst->next);
		lst = lst->prev;
	}
}

void	free_split_array(char **split_array, int arg_amount)
{
	int	i;

	i = 0;
	while (i <= arg_amount)
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}
