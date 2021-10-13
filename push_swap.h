/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 09:27:21 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/10/13 13:50:48 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0
# define SMALL_STACK 5
# define HALF_SMALL_STACK 2

typedef struct s_stack
{
	long int		to_sort;
	unsigned int	index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef enum e_error_code
{
	OK,
	ERROR,
	TEST,
}	t_error_code;

typedef enum e_stack_position
{
	DONT_SORT,
	LOWEST,
	MIDDEL_LOW,
	MIDDEL_HIGH,
	HIGHEST,
}	t_stack_position;

/* create_stack.c */

/* utils.c */
void	ft_error(int error_code);
int		list_is_sorted(t_stack *stack);
void	check_doubles_input(t_stack *stack_a);
void	check_isdigit(char **split_array, int arg_amount);
void	check_min_max(t_stack *stack);

/* free.c */
void	free_list(t_stack *lst);
void	free_split_array(char **split_array, int arg_amount);

/* nodes.c */
t_stack	*new_stack_node(long int input);
t_stack	*last_node(t_stack *lst);
void	add_node_back(t_stack **lst, t_stack *new);
void	add_node_front(t_stack **lst, t_stack *new);
int		count_list(t_stack *lst);

/* a_instructions.c */
void	ra(t_stack **stack_a, int rr_flag);
void	rra(t_stack **stack_a, int rrr_flag);
void	sa(t_stack *stack);
void	pa(t_stack **stack_a, t_stack **stack_b, t_stack *temp_a, t_stack *temp_b);

/* b_instructions.c */
void	rb(t_stack **stack_b, int rr_flag);
void	pb(t_stack **stack_a, t_stack **stack_b, t_stack *temp_a, t_stack *temp_b);

/* sort_small_stack.c */
int		top_of_mini_stack(t_stack *stack_a);
void	sort_mini_stack(t_stack **stack_a);
void	find_middel_value(t_stack *stack_a, int *middle_value);
void	sort_small_stack(t_stack **stack_a, t_stack **stack_b);

/* sort_large_stack.c */
void	sort_large_stack(t_stack **stack_a, t_stack **stack_b, int stack_count);

/* simplify_stack_input.c */
void	simplify_stack_input(t_stack *stack_a, int stack_count);
void	put_stack_to_array(t_stack *stack_a, int stack_count);
void	sort_stack_array(t_stack *stack_a, t_stack *stack_array, int stack_count);
void	get_index_position(t_stack *stack_a, t_stack *stack_array, int stack_count);

#endif
