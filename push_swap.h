/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 09:27:21 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/08 14:19:15 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

/* create_stack.c */
void	ft_error(int error_code);

/* nodes.c */
t_stack	*new_stack_node(long int input);
t_stack	*last_node(t_stack *lst);
void	add_node_back(t_stack **lst, t_stack *new);
void	add_node_front(t_stack **lst, t_stack *new);
void	stack_iter_forward(t_stack *lst, int (*f)(const char *, ...));
void	stack_iter_backward(t_stack *lst, int (*f)(const char *, ...));

/* instructions_1.c */
void	sa(t_stack *stack);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
t_stack	*pb(t_stack *stack_a, t_stack *stack_b);
void	del_first_node(t_stack **lst);



