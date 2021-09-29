/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 13:17:40 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/29 14:24:58 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"
// Remove all printf!!! 

void	ft_error(int error_code)
{
	write(2, "Error\n", 6);
	if (error_code == TEST)
		printf("ended in error\n");
	if (error_code == WRONG_AC)
		printf("wrong amound of arguments where passed\n");
	if (error_code == MALLOC_FAIL)
		exit(1);
	exit(1);
}

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

int	top_of_mini_stack(t_stack *stack_a)
{
	long	int compare1;
	long	int compare2;
	long	int compare3;

	if (!stack_a || stack_a->next == NULL)
		return (DONT_SORT);
	if (list_is_sorted(stack_a))
		return (DONT_SORT);
	if (stack_a->next->next == NULL)
	{
		sa(stack_a);
		return (DONT_SORT);
	}
	compare1 = stack_a->to_sort;
	compare2 = stack_a->next->to_sort;
	compare3 = stack_a->next->next->to_sort;
	if (compare1 > compare2 && compare1 > compare3)
		return (HIGHEST);
	else if (compare1 < compare2 && compare1 < compare3)
		return (LOWEST);
	else
	{
		if (compare2 < compare3)
			return (MIDDEL_LOW);
		else
			return (MIDDEL_HIGH);
	}
}

void	sort_mini_stack(t_stack **stack_a)
{
	int	stack_top;
	
	stack_top = top_of_mini_stack(*stack_a);
	if (stack_top == DONT_SORT)
		return ;
	if (stack_top == HIGHEST)
	{
		ra(stack_a, FALSE);
		if (!list_is_sorted(*stack_a))
			sa(*stack_a);
	}
	if (stack_top == LOWEST)
	{
		sa(*stack_a);
		ra(stack_a, FALSE);
	}
	if (stack_top == MIDDEL_LOW)
		sa(*stack_a);
	if (stack_top == MIDDEL_HIGH)
		rra(stack_a, FALSE);
}

void	find_middel_value(t_stack *stack_a, int *middle_value)
{
	t_stack *temp_a;
	t_stack *constant_stack_a;
	int	count;
	int i;

	temp_a = stack_a;
	constant_stack_a = stack_a;
	i = 0;
	while (i < 5)
	{
		*middle_value = stack_a->to_sort;
		count = 0;
		temp_a = constant_stack_a;
		while(temp_a)
		{
			if (*middle_value > temp_a->to_sort)
				count++;
			temp_a = temp_a->next;
		}
		if (count == 2)
			break;
		stack_a = stack_a->next;
		i++;
	}
}

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	middle_value;
	int	i;
	t_stack *temp;

	i = 0;
	temp = *stack_a;
	find_middel_value(*stack_a, &middle_value);
	while (i < 2)
	{
		if (temp->to_sort < middle_value)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a, FALSE);
		temp = *stack_a;
	}
	sort_mini_stack(stack_a);
	if ((*stack_b)->to_sort > (*stack_b)->next->to_sort)
		pa(stack_a, stack_b);
	else
	{
		rb(stack_b, FALSE);
		pa(stack_a, stack_b);
	}
	pa(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *new;
	int input;
	int i;
	int stack_count;

	if (ac < 2)
		ft_error(WRONG_AC);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < ac)
	{
		input = ft_atoi(av[i]);
		//printf("input from atoi [%d] (%d)\n", i, input);
		if (!stack_a)
		{
			stack_a = new_stack_node(input);
			if (!stack_a)
				ft_error(MALLOC_FAIL);
		}
		else
		{
			new = new_stack_node(input);
			if (!new)
				ft_error(MALLOC_FAIL);
			add_node_back(&stack_a, new);
		}
		i++;
	}

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
	
	
	if (list_is_sorted(stack_a))
		return (printf("list is sorted\n"));
	return (printf("not sorted or stack_a is empty\n"));
	
	free_list(stack_a);
	free(stack_a);
	free_list(stack_b);
	if (stack_b)
		free(stack_b);
	//system("leaks push_swap");
	//exit(0);
}
