/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:07:03 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/02 19:06:04 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		sort_stack_b(t_stack_node **a, t_stack_node **b,
							int size, int x, int size_a);

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
	ft_putnbr(size);
	while (root && size)
	{
		if (root->next && (root->data > root->next->data))
		{
			swap_data(root, (root->next));
			root = head;
			size = len;
			//size;
		}
		else
			root = root->next;
		size--;
	}
	root = head;
	ft_putstr("Sorted stack is \n");
			print_stack(root, NULL);
	len /= 2;
	while (len)
	{
		root = root->next;
		len--;
	}
	return (root->data);
}

void		sort_stack_a(t_stack_node **a, t_stack_node **b,
							int size, int x, int size_a)
{
	int median;
	int push;
	int i;

	push = 0;
	i = 0;
	if (is_sorted(*a))
		return ;
	else
	{
		median = find_median(*a, size_a);
		ft_putnbr(size);
		ft_putnbr(median);
		while (x < size)
		{
			if ((*a)->data < median)
			{
				push_to_stack(a, b);
				delay(100);
				ft_putstr("Pushing from A to B\n");
				print_stack(*a, *b);
				push++;
			}
			else
			{
				rot_l(a);
				delay(100);
				ft_putstr("Rotate L A\n");
				print_stack(*a, *b);
			}
			x++;
		}
		while (i < (size - push))
		{
			rot_r(a);
			i++;
		}
		delay(100);
		ft_putstr("Rotate R A\n");
		print_stack(*a, *b);
		sort_stack_b(a, b, push, 0, size_a);
	}
	return ;
}

void		sort_stack_b(t_stack_node **a, t_stack_node **b,
							int size, int x, int size_a)
{
	int median;
	int push;
	int i;

	i = 0;
	push = 0;
	if (stack_size(*b) <= 3)
	{
		sort_3(b);
		while (*b)
		{
			push++;
			delay(100);
			push_to_stack(b, a);
			ft_putstr("Push from B to A\n");
			print_stack(*a, *b);
		}
		while (i < push)
		{
			rot_l(a);
			delay(100);
			ft_putstr("Rotate A\n");
			print_stack(*a, *b);
			i++;
		}
		sort_stack_a(a, b,  size_a - push, 0, size_a - push);
	}
	else
	{
		median = find_median(*b, size);
		while (x < size)
		{
			if ((*b)->data > median)
			{
				push_to_stack(b, a);
				delay(100);
				print_stack(*a, *b);
				i++;
				size_a++;
			}
			else
			{
				rot_l(b);
				delay(100);
				print_stack(*a, *b);
			}
			x++;
		}
		delay(100);
		print_stack(*a, *b);
		sort_stack_b(a, b, size - i, 0, size_a);
	}
	return ;
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int size_a;

	size_a = stack_size(*a);
	sort_stack_a(a, b, size_a, 0, size_a);
}
