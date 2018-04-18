/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:29:59 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/17 16:36:43 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct	s_stack_node
{
	int data;
	struct s_stack_node *next;
}				t_stack_node;

t_stack_node	*new_node(int data);

int				is_empty(t_stack_node *root);

void			push(t_stack_node **root, int data);

void			push_to_stack(t_stack_node **src, t_stack_node **dst);

void			swap(t_stack_node **root);

void			rot_l(t_stack_node **root);

void			rot_r(t_stack_node **root);

void			push_to_end(t_stack_node *new_l, t_stack_node **lst);

int				is_sorted(t_stack_node *root);
#endif
