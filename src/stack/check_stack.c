/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:12:33 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/01 20:31:04 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		is_sorted(t_stack_node *root)
{
	while (root && size)
	{
		if (root->next && root->data >= root->next->data)
			return (0);
		size--;
		root = root->next;
	}
	return (1);
}

int				is_empty(t_stack_node *root)
{
	return (!root);
}

int				stack_size(t_stack *root)
{
	int len;

	len = 0;
	while (root)
	{
		len++;
		root = root->next;
	}
}
