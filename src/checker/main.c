/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:16:06 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/16 19:51:10 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node	*root;
	int				i;

	i = 1;
	root = new_node(ft_atoi(argv[1]));
	while (++i < argc)
		push_to_end(new_node(ft_atoi(argv[i])), &root);
	rot_l(&root);
	while (root)
	{
		ft_putnbr(root->data);
		root = root->next;
	}
	return (0);
}
