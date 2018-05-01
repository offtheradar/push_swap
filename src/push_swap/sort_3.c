/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:38:20 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/30 20:00:25 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3(t_stack_node **root)
{
	if (is_sorted(*root) || !(*root)->next)
		return ;
	else if ((*root)->next && !(*root)->next->next)
	{
		if ((*root)->data > (*root)->next->data)
			rot_l(root);
		return ;
	}
	else if ((*root)->data < (*root)->next->data)
	{
		if ((*root)->next->next->data < (*root)->next->data)
		{
			if ((*root)->next->next->data < (*root)->data)
				rot_r(root);
			else
			{
				rot_r(root);
				swap(root);
			}
		}
	}
	else if ((*root)->next->data < (*root)->next->next->data)
	{
		if ((*root)->next->next->data < (*root)->data)
			rot_l(root);
		else
			swap(root);
	}
	else
	{
		swap(root);
		rot_r(root);
	}

}
