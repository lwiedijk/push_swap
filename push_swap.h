/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 09:27:21 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/02 15:03:26 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
	int				node_num;
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

/* nodes.c */
t_stack	*new_stack_node(int input, int node_num);
t_stack	*last_node(t_stack *lst);
void	add_node_back(t_stack **lst, t_stack *new);
void	stack_iter_forward(t_stack *lst, int (*f)(const char *, ...));
void	stack_iter_backward(t_stack *lst, int (*f)(const char *, ...));