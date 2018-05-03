/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:07:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/02 21:45:51 by ysibous          ###   ########.fr       */
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

int			find_median(t_stack_node *root, int size)
{
	int				len;
	t_stack_node	*head;


	if (!root)
		exit(1);
	head = root;
	len = size;
	while (root && size)
	{
		if (root->next && (root->data > root->next->data))
		{
			swap_data(root, (root->next));
			root = head;
			size = len;
		}
		else
			root = root->next;
		size--;
	}
	root = head;
	len /= 2;
	while (len)
	{
		root = root->next;
		len--;
	}
	return (root->data);
}

void		sort_stack_a(t_stack_node **a, t_stack_node **b,
							int num_sorted)
{
	int median;
	int push;
	int size_a;
	int i;

	push = 0;
	i = 0;
	size_a = stack_size(*a) - num_sorted;
	if (is_sorted(*a) || size_a == 0)
		return ;
	else
	{
		median = find_median(*a, size_a);
		while (i < size_a)
		{
			if ((*a)->data < median)
			{
				push_to_stack(a, b);
				push++;
			}
			else
				rot_l(a);
			i++;
		}
		i = 0;
		while (i < (size_a - push))
		{
			rot_r(a);
			i++;
		}
		delay(300);
		print_stack(*a, *b);
		sort_stack_b(a, b, num_sorted);
	}
}

void		sort_stack_b(t_stack_node **a, t_stack_node **b, int num_sorted)
{
	int i;
	int size_b;
	int median;

	i = 0;
	if (!b || !(*b))
		size_b = 0;
	else
		size_b = stack_size(*b);
	if (size_b <= 3)
	{
		sort_3(b);
		num_sorted += size_b;
		while (i < size_b)
		{
			push_to_stack(b, a);
			i++;
		}
		if (is_sorted(*a))
			return ;
		while (i > 0)
		{
			rot_l(a);
			i--;
		}
		delay(300);
		print_stack(*a, *b);
		sort_stack_a(a, b, num_sorted);
	}
	else
	{
		median = find_median(*b, size_b);
		while (i < size_b)
		{
			if ((*b)->data > median)
			{
				push_to_stack(b, a);
			}
			else
				rot_l(b);
			i++;
		}
		delay(300);
		print_stack(*a, *b);
		sort_stack_b(a, b, num_sorted);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int size_a;

	size_a = stack_size(*a);
	sort_stack_a(a, b, 0);
}
