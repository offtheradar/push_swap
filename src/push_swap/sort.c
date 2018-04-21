/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:07:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/21 15:20:42 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			stack_len(t_stack_node *root)
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

void		swap_data(t_stack_node **first, t_stack_node **snd)
{
	int tmp;

	tmp = (*first)->data;
	(*first)->data = (*snd)->data;
	(*snd)->data = tmp;
}

int			find_median(t_stack_node *root)
{
	int len;
	t_stack_node *head;

	head = root;
	len = stack_len(root) / 2;
	while (root)
	{
		if (root->next && root->data > root->next->data)
		{
			swap_data(&root, &(root->next));
			root = head;
		}
			root = root->next;
	}
	root = head;
	while (len)
	{
		root = root->next;
		len--;
	}
	return (root->data);
}

// While there remains elements to be sorted...
// Step 1 - Find Median of Stack A
// Step 2 - Put all numbers smaller than Median in Stack B
// Step 3 - If len(Stack B) <= 3 - Sort Stack B and change the "top" 
// stack B
// else - find the median of Stack B and add all numbers larger than median
// to stack A
// Keep track of the number of ints added to Stack A and add this number to a
// queue
// Repeat the above until Stack B has size 3
// Sort three elements
// Repeat this by going through queue and adding the elements added to a from b
// back to a
// Substract the number of elements sorted from left_to_sort
// loop

/*
void		sort_stack(t_stack_node **a, t_stack_node **b)
{
	int median;
	int	left_to_sort;
	int	pushed_to_a;
	int count_b;
	int i;

	i = 0;
	count_b = 0;
	median = find_median(*a);
	left_to_sort = len_a;
	while (left_to_sort)
	{
		median = find_median(*a);
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
		if (count_b > 3)
		{
			median = find_median(b);
			while (count_b > 3)
			{
				if ((*b)->data > median)
				{
					push_to_stack(b, a);
					pushed_to_a += 1;
					count_b--;
				}
				else
					rot_l(b);
			}
		}
		else
			sort_3(b);
		left_to_sort -= count_b;
	}
}
*/
