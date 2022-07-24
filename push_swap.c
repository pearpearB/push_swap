/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:42:14 by jabae             #+#    #+#             */
/*   Updated: 2022/07/24 23:30:00 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_chunk(int x)
{
	return (0.000000053 * x * x + 0.03 * x + 14.5);
}

static void	push_swap(t_deque *a, t_deque *b)
{
	if (a->total == 2)
		operation(SA, a, NULL);
	else if (a->total == 3)
		sort_three(a);
	else if (a->total == 4)
		sort_four(a, b);
	else if (a->total == 5)
		sort_five(a, b);
	else
	{
		a_to_b(a, b, calc_chunk(a->total));
		b_to_a(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;

	if (argc < 2)
		return (0);
	init_deque(&a);
	parsing(argv, &a);
	if (is_sorted(&a))
	{
		free_deque(&a);
		return (0);
	}
	init_deque(&b);
	push_swap(&a, &b);
	free_deque(&a);
	free_deque(&b);
	return (0);
}
