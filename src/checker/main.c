/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:16:06 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/17 09:45:09 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	parse_command(char *command, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(command, "sa") == 0 || ft_strcmp(command, "ss") == 0)
		swap(a);
	if (ft_strcmp(command, "sb") == 0|| ft_strcmp(command, "sb") == 0)
		swap(b);
	if (ft_strcmp(command, "pa") == 0)
		push_to_stack(b, a);
	if (ft_strcmp(command, "pb") == 0)
		push_to_stack(a, b);
	if (ft_strcmp(command, "ra") == 0 || ft_strcmp(command, "rr") == 0)
		rot_l(a);
	if (ft_strcmp(command, "rb") == 0 || ft_strcmp(command, "rr") == 0)
		rot_l(b);
	if (ft_strcmp(command, "rra") == 0 || ft_strcmp(command, "rrr") == 0)
		rot_r(a);
	if (ft_strcmp(command, "rrb") == 0|| ft_strcmp(command, "rrr") == 0)
		rot_r(b);
}

int		input_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
	return (0);
}

int		is_valid_command(char *command)
{
	if (ft_strcmp(command, "sa") == 0 || ft_strcmp(command, "ss") == 0 ||
			ft_strcmp(command, "sb") == 0 || (ft_strcmp(command, "pa") == 0) ||
			(ft_strcmp(command, "pb") == 0) || (ft_strcmp(command, "ra") == 0)
			|| (ft_strcmp(command, "rb") == 0)
			|| (ft_strcmp(command, "rr") == 0)
			|| (ft_strcmp(command, "rra") == 0)
			|| (ft_strcmp(command, "rrb") == 0)
			|| (ft_strcmp(command, "rrr") == 0))
		return (1);
	return (input_error());
}

int		is_sorted(t_stack_node *root)
{
	while (root)
	{
		if (root->next && root->data >= root->next->data)
			return (0);
		root = root->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*buff;
	int				i;

	i = 1;
	b = 0;
	a = new_node(ft_atoi(argv[1]));
	while (++i < argc)
		push_to_end(new_node(ft_atoi(argv[i])), &a);
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
