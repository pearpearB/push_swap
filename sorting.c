/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:05:54 by jabae             #+#    #+#             */
/*   Updated: 2022/07/28 20:43:07 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	route_rb_or_rrb(t_deque *deque, int max_idx)
{
	t_node	*cur;
	int		loc;

	loc = 1;
	cur = deque->top;
	while (cur->idx != max_idx)
	{
		loc++;
		cur = cur->next;
	}
	if (loc <= deque->total / 2)
		return (1);
	else
		return (0);
}

void	a_to_b(t_deque *a, t_deque *b, int chunk)
{
	int	criteria;

	criteria = 0;
	while (a->total)
	{
		if (a->top->idx <= criteria)
		{
			operation(PB, a, b, NOCHECKER);
			criteria++;
		}
		else if (a->top->idx <= criteria + chunk)
		{
			operation(PB, a, b, NOCHECKER);
			operation_R(RB, NULL, b, NOCHECKER);
			criteria++;
		}
		else
		{
			if (a->bottom->idx <= criteria + chunk) // 최악의 경우 방지
				operation_R(RRA, a, NULL, NOCHECKER);
			else
				operation_R(RA, a, NULL, NOCHECKER);
		}
	}
}

void	b_to_a(t_deque *a, t_deque *b)
{
	int	max_idx;

	while (b->total)
	{
		max_idx = b->total - 1;
		if (route_rb_or_rrb(b, max_idx))
		{
			while (b->top->idx != max_idx)
				operation_R(RB, NULL, b, NOCHECKER);
		}
		else
		{
			while (b->top->idx != max_idx)
				operation_R(RRB, NULL, b, NOCHECKER);
		}
		operation(PA, a, b, NOCHECKER);
	}
}
