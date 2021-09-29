/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 09:27:21 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/29 16:14:01 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	long int		to_sort;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef enum e_error_code
{
	OK,
	TEST,
	WRONG_AC,
	MALLOC_FAIL,
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
void	ft_error(int error_code);

/* nodes.c */
t_stack	*new_stack_node(long int input);
t_stack	*last_node(t_stack *lst);
void	add_node_back(t_stack **lst, t_stack *new);
void	add_node_front(t_stack **lst, t_stack *new);
int	count_list(t_stack *lst);
void	print_stack_list_forward(t_stack *lst, int (*f)(const char *, ...), char stack_char);
void	print_stack_list_backward(t_stack *lst, int (*f)(const char *, ...), char stack_char);
void	stack_iter_forward(t_stack *lst, int (*f)(const char *, ...));
void	stack_iter_backward(t_stack *lst, int (*f)(const char *, ...));
void	del_first_node(t_stack **lst);

/* instructions_1.c */
void	sa(t_stack *stack);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/* instructions_2.c */
void	ra(t_stack **stack_a, int rr_flag);
void	rb(t_stack **stack_b, int rr_flag);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, int rrr_flag);
void	rrb(t_stack **stack_b, int rrr_flag);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* sort_small_stack.c */
int	top_of_mini_stack(t_stack *stack_a);
void	sort_mini_stack(t_stack **stack_a);
void	find_middel_value(t_stack *stack_a, int *middle_value);
void	sort_small_stack(t_stack **stack_a, t_stack **stack_b);


#endif


