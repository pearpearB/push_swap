/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:05:57 by jabae             #+#    #+#             */
/*   Updated: 2022/07/28 20:48:24 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_deque *a)
{
	t_node	*cur;
	t_node	*cur_next;

	cur = a->top;
	while (cur->next)
	{
		cur_next = cur->next;
		if (cur->idx > cur_next->idx)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void	sort_three_util(int first, int second, int third, t_deque *a)
{
	if (first < second)
	{
		if (first < third)
		{
			operation_R(RRA, a, NULL, NOCHECKER);
			operation(SA, a, NULL, NOCHECKER);
		}
		else
			operation_R(RRA, a, NULL, NOCHECKER);
	}
	else
	{
		if (first > third && second > third)
		{
			operation_R(RA, a, NULL, NOCHECKER);
			operation(SA, a, NULL, NOCHECKER);
		}
		else if (first > third && second < third)
			operation_R(RA, a, NULL, NOCHECKER);
		else
			operation(SA, a, NULL, NOCHECKER);
	}
}

void	sort_three(t_deque *a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(a))
		return ;
	first = a->top->idx;
	second = a->top->next->idx;
	third = a->bottom->idx;
	sort_three_util(first, second, third, a);
}

void	sort_four(t_deque *a, t_deque *b)
{
	int	second;
	int	third;
	int	last;

	second = a->top->next->idx;
	third = a->top->next->next->idx;
	last = a->bottom->idx;
	if (second == 0)
		operation(SA, a, NULL, NOCHECKER);
	else if (third == 0)
	{
		operation_R(RA, a, NULL, NOCHECKER);
		operation_R(RA, a, NULL, NOCHECKER);
	}
	else if (last == 0)
		operation_R(RRA, a, NULL, NOCHECKER);
	operation(PB, a, b, NOCHECKER);
	sort_three(a);
	operation(PA, a, b, NOCHECKER);
}

void	sort_five(t_deque *a, t_deque *b)
{
	while (a->total > 3)
	{
		if (a->top->idx < 2)
			operation(PB, a, b, NOCHECKER);
		else
			operation_R(RA, a, NULL, NOCHECKER);
	}
	sort_three(a);
	while (b->total)
		operation(PA, a, b, NOCHECKER);
	if (a->top->idx != 0)
		operation(SA, a, b, NOCHECKER);
}
