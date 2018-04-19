/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:00:39 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/19 10:10:23 by ysibous          ###   ########.fr       */
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
