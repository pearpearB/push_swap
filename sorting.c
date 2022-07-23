/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:05:54 by jabae             #+#    #+#             */
/*   Updated: 2022/07/23 15:57:24 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int route_rb_or_rrb(t_deque *deque, int max_idx)
{
	int loc;
	t_node *cur;

	loc = 1;
	cur = deque->top;
	while(cur->idx != max_idx)
	{
		loc++;
		cur = cur->next;
	}
	if (loc <= deque->total / 2)
		return (1);
	else
		return (0);
}

void a_to_b(t_deque *a, t_deque *b, int chunk)
{
	int criteria;

	criteria = 0;
	while(a->total)
	{
		if (a->top->idx <= criteria)
		{
			operation(PB, a, b);
			criteria++;
		}
		else if (a->top->idx <= criteria + chunk)
		{
			operation(PB, a, b);
			operation(RB, NULL, b);
			criteria++;
		}
		else
		{
			if (a->bottom->idx <= criteria + chunk)
				operation(RRA, a, NULL);
			else
				operation(RA, a, NULL);
		}
	}
}

void b_to_a(t_deque *a, t_deque *b)
{
	int max_idx;

	while(b->total)
	{
		max_idx = b->total - 1;
		if (route_rb_or_rrb(b, max_idx))
		{
			while (b->top->idx != max_idx)
				operation(RB, NULL, b);
		}
		else
		{
			while (b->top->idx != max_idx)
				operation(RRB, NULL, b);
		}
		operation(PA, a, b);
	}
}
