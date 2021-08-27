/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwiedijk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 09:27:21 by lwiedijk      #+#    #+#                 */
/*   Updated: 2021/08/27 13:27:22 by lwiedijk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stack
{
	int				sort;
	struct s_stack	*next;
}					t_stack;

typedef enum e_error_code
{
	OK,
	TEST,
	MALLOC_FAIL,
}	t_error_code;