/*  ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:00:23 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/19 12:39:54 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void			push_to_stack(t_stack_node **src, t_stack_node **dst)
{
	int to_push;

	if (*src)
	{
		to_push = pop(src);
		push(dst, to_push);
	}
}

void			swap(t_stack_node **root)
{
	int	tmp;
	
	if (is_empty(*root) || is_empty((*root)->next))
		return ;
	tmp = (*root)->data;
	(*root)->data = (*root)->next->data;
	(*root)->next->data = tmp;
}

void			rot_l(t_stack_node **root)
{
	t_stack_node *tmp;

	tmp = *root;
	while (tmp)
	{
		swap(&tmp);
		tmp = tmp->next;
	}
}

void			rot_r(t_stack_node **root)
{
	if ((*root)->next)
		rot_r(&((*root)->next));
	swap(root);
}

