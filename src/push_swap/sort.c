/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:07:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/18 18:28:17 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h/"

int			find_median(t_stack_node *a)
{

}

void		partition(t_stack_node **first, t_stack_node **second)
{
	while (i < len_a)
	{
		if ((*a)->data <= median)
		{
			push_to_stack(a, b);
			count_b++;
		}
		else
			rot_l(a);
	}
}

void		sort_stack(t_stack_node **a, t_stack_node **b)
{
	int median;
	int count_b;
	int i;

	i = 0;
	count_b = 0;
	median = find_median(*a, );
	while (i < len_a)
	{
		if ((*a)->data <= median)
		{
			push_to_stack(a, b);
			count_b++;
		}
		else
			rot_l(a);
	}
	i = 0;
	if (count_b > 3)
	{
		median = find_median(*b);
		while (i < count_b)
		{
			if ((*b)->data <= median)
			{
				push_to_stack(b, a);
				count_b++;
			}
			else
				rot_l(a);
	}
		else
			push_to_bottom(a, b, num_swapped);

	}

}

