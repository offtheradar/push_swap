************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:00:23 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/19 12:16:30 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int		is_sorted(t_stack_node *root)
{
	while (root)
	{
		if (root->next && root->data >= root->next->data)
			return (0);
		root = root->next;
	}
	return (1);
}

t_stack_node	*new_node(int data)
{
	t_stack_node	*node;

	node = (t_stack_node *)ft_memalloc(sizeof(t_stack_node));
	node->data = data;
	node->next = NULL;
	return (node);
}

int				is_empty(t_stack_node *root)
{
	return (!root);
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
