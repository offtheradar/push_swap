/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:12:15 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/19 12:37:07 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack_node	*new_node(int data)
{
	t_stack_node	*node;

	node = (t_stack_node *)ft_memalloc(sizeof(t_stack_node));
	node->data = data;
	node->next = NULL;
	return (node);
}

void			push(t_stack_node **root, int data)
{
	t_stack_node *node;

	node = new_node(data);
	if (!root || !(*root))
		*root = node;
	else
	{
		node->next = *root;
		*root = node;
	}
}

int				pop(t_stack_node **root)
{
	t_stack_node	*tmp;
	int				popped;

	if (is_empty(*root))
		return (-1);
	tmp = *root;
	*root = (*root)->next;
	popped = tmp->data;
	free(tmp);
	return (popped);
}

void			push_to_end(t_stack_node *new_l, t_stack_node **lst)
{
	t_stack_node *curr;

	if (!new_l || !lst)
		return ;
	if (!*lst)
		*lst = new_l;
	else
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = new_l;
	}
}
