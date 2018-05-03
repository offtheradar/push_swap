/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:16:06 by ysibous           #+#    #+#             */
/*   Updated: 2018/05/02 13:08:47 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#import <time.h>
#include <stdio.h>

void	print_stack(t_stack_node *a, t_stack_node *b)
{
	ft_putchar('a');
	ft_putchar('\t');
	ft_putchar('b');
	ft_putchar('\n');
	while (a || b)
	{
		if (a)
		{
			ft_putnbr(a->data);
			a = a->next;
		}
		if (!a)
			ft_putchar(' ');
		ft_putchar('\t');
		if (b)
		{
			ft_putnbr(b->data);
			b = b->next;
		}
		if (!b)
			ft_putchar(' ');
		ft_putchar('\n');
	}
	ft_putchar('\n');
}


void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Stroing start time
    clock_t start_time = clock();
 
    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
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
