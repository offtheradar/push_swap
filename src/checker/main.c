/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:16:06 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/19 20:39:20 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_stack_node *root)
{
	while (root)
	{
		ft_putnbr(root->data);
		root = root->next;
	}
}
int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*buff;
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
	while (get_next_line(0, &buff) > 0 && (ft_strcmp(buff, "\n") != 0
				&& ft_strcmp(buff, "\0") != 0) && is_valid_command(buff))
	{
		parse_command(buff, &a, &b);
		free(buff);
	}
	if (is_sorted(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	while (1){};
	return (0);
}
