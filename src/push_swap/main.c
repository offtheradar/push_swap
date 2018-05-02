/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:16:06 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/01 21:23:16 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

void	print_stack(t_stack_node *root, char c)
{
	ft_putchar(c);
	ft_putchar('\n');
	while (root)
	{
		ft_putnbr(root->data);
		ft_putchar('\n');
		root = root->next;
	}
	ft_putchar('\n');
}

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				i;

	i = 0;
	a = 0;
	b = 0;
	while (++i < argc)
	{
		if (!is_int(argv[i]))
			return (input_error());
		push_to_end(new_node(ft_atoi(argv[i])), &a);
	}
	//sort_3(&a);
		//print_stack(a);
		//printf("the medin is %d", find_median(a));
	sort_stack(&a, &b);
	//print_stack(a);

	return (0);
}
