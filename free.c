/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 09:43:16 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/01 09:44:38 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
	while(i <= arg_amount)
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}
