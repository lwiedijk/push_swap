/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 09:27:21 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/09/02 11:26:36 by lwiedijk      ########   odam.nl         */
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