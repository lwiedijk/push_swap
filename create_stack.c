/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 13:17:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/01 13:17:18 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

t_stack	*new_stack_node(int input)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->sort = input;
	new->next = NULL;
	return (new);
}

void	ft_error(int error_code)
{
	if (error_code == TEST)
		printf("ended in error\n");
	if (error_code == MALLOC_FAIL)
		exit(1);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack *stack;
	int input;
	int i;

	if (ac < 2)
		ft_error(TEST);
	i = 1;
	while (i < ac)
	{
		input = ft_atoi(av[i]);
		printf("input from atoi [%d] (%d)\n", i, input);
		i++;
	}
	stack = new_stack_node(input);
	if (!stack)
		ft_error(MALLOC_FAIL);
}
