/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:07:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/01 20:33:33 by ysibous          ###   ########.fr       */
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

void		swap_data(t_stack_node *first, t_stack_node *snd)
{
	int tmp;

	tmp = (first)->data;
	(first)->data = (snd)->data;
	(snd)->data = tmp;
}

int			find_median(t_stack_node *root)
{
	int				len;
	t_stack_node	*head;

	head = root;
	len = stack_len(root) / 2;
	if (!root)
		exit(1);
	while (root->next)
	{
		if (root->next && (root->data > root->next->data))
		{
			swap_data(root, (root->next));
			root = head;
		}
		else
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


void		sort_stack_a(t_stack_node **a, t_stack_node **b
							int size, int x, int y)
{
	int median;
	int push;

	push = 0;
	if (is_sorted(a));
		return ;
	else
	{
		median = find_median(*a, size);
		while (x < size)
		{
			if ((*a)->data < median)
			{
				push_to_stack(a, b);
				push++;
			}
			else
				rot_l(a);
		}
		while (y < (size - push))
		{
			rot_r(a)
			y++;
		}
		sort_stack_b(a, b, push, 0, 0);
	}
	return ;
}

void		sort_stack_b(t_stack_node **a, t_stack_node **b
							int size, int x, int y)
{
	int median;
	int push;
	int i;

	i = 0;
	push = 0;
	if (size <= 3)
	{
		sort_3(b);
		while (*b)
		{
			push++;
			push_to_stack(b, a);
		}
		while (i < push)
		{
			rot_l(a);
			i++;
		}
		sort_stack_a(a, b,  stack_size - push, 0, 0);
	}
	else
	{
		median = find_median(*b, size);
		while (x < size)
		{
			if ((*b)->data > median)
			{
				push_to_stack(b, a);
				push++;
			}
			else
				rot_l(b);
		}
		sort_stack_b(a, b, size - push, 0, 0);
	}
	return ;
}
