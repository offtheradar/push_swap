/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:03:49 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/17 16:48:23 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		find_pivot(t_stack_node *a)
{
	int min;
	int max; 

	min = MAX_INT;
	max = MIN_INT;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		if (a->data > max)
			max = a->data;
		a = a->next;
	}
	return ((max - min) / 2);
}

void	quick_sort(t_stack_node **a, int len_a)
{
	int				i;
	int				len_b;
	int				pivot;
	t_stack_node	*b;

	if (!(*a) || !((*a)->next))
		return ;
	pivot = 2;
	b = (t_stack_node *)ft_memalloc(sizeof(t_stack_node));
	len_b = 0;
	i = 0;
	while (i < len_a)
	{
		if ((*a)->data > pivot)
		{
			push_to_stack(a, &b);
			ft_putstr("pb");
			len_b++;
		}
		rot_l(a);
		ft_putstr("ra");
		i++;
	}
	i = 0;
	while (i < (len_a - len_b))
	{
		rot_r(a);
		ft_putstr("rra");
		i++;
	}
	i = 0;
	while (i < len_b)
	{
		push_to_stack(&b, a);
		ft_putstr("pb");
		i++;
	}
	quick_sort(&b, len_b);
	i = 0;
	while (i < len_b)
	{
		rot_l(a);
		ft_putstr("ra");
		i++;
	}
	quick_sort(a, len_a - len_b);
	i = 0;
	while (i < len_b)
	{
		rot_r(a);
		ft_putstr("rra");
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stack_node	*a;
	char			*buff;
	int				i;

	i = 1;
	a = new_node(ft_atoi(argv[1]));
	while (++i < argc)
		push_to_end(new_node(ft_atoi(argv[i])), &a);
	quick_sort(&a, argc - 1);
	if (is_sorted(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	//while (1){};
	return (0);
}
