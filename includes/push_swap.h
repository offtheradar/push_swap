/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:29:59 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/01 21:25:15 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct	s_stack_node
{
	int					data;
	struct s_stack_node *next;
}				t_stack_node;

/*
****************************** Basic Stack *************************************
*/

t_stack_node	*new_node(int data);

void			push_to_end(t_stack_node *new_l, t_stack_node **lst);

void			push(t_stack_node **root, int data);

int				pop(t_stack_node **root);

/*
****************************** Stack Operators *********************************
*/
void			push_to_stack(t_stack_node **src, t_stack_node **dst);

void			swap(t_stack_node **root);

void			rot_l(t_stack_node **root);

void			rot_r(t_stack_node **root);

/*
******************************* Check Stack ************************************
*/

int				is_sorted(t_stack_node *root);

int				is_empty(t_stack_node *root);

/*
******************************** Parse Input ***********************************
*/

void			parse_command(char *command, t_stack_node **a,
								t_stack_node **b);

int				is_valid_command(char *command);

int				input_error(void);

int				is_int(char *str);

/*
********************************** Sorting *************************************
*/

int				find_median(t_stack_node *root, int size);

void			sort_3(t_stack_node **root);

void			sort_stack(t_stack_node **a, t_stack_node **b);

void	print_stack(t_stack_node *root, char c);

int				stack_size(t_stack_node *root);
#endif
