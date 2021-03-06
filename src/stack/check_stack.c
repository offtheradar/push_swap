/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:12:33 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/01 21:12:31 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int				is_empty(t_stack_node *root)
{
	return (!root);
}

int				stack_size(t_stack_node *root)
{
	int len;

	len = 0;
	while (root)
	{
		len++;
		root = root->next;
	}
	return (len);
}
