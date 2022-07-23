/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:05:57 by jabae             #+#    #+#             */
/*   Updated: 2022/07/23 17:25:36 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_deque *a)
{
	t_node *cur;
	t_node *cur_next;

	cur = a->top;
	while(cur->next)
	{
		cur_next = cur->next;
		if (cur->idx > cur_next->idx)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void sort_three_util(int first, int second, int third)
{
		if (first < second)
	{
		if (first < third)
		{
			operation(RRA, a, NULL);
			operation(SA, a, NULL);
		}
		else
			operation(RRA, a, NULL);
	}
	else
	{
		if (first > third && second > third)
		{
			operation(RA, a, NULL);
			operation(SA, a, NULL);
		}
		else if (first > third && second < third)
			operation(RA, a, NULL);
		else
			operation(SA, a, NULL);
	}
}

void sort_three(t_deque *a)
{
	int first;
	int second;
	int third;

	if (is_sorted(a))
		return ;
	first = a->top->idx;
	second = a->top->next->idx;
	third = a->bottom->idx;
	sort_three_util(first, second, third);
}

void sort_four(t_deque *a, t_deque *b)
{
	int second;
	int third;
	int last;

	second = a->top->next->idx;
	third = a->top->next->next->idx;
	last = a->bottom->idx;
	if (second == 0)
		operation(SA, a, NULL);
	else if (third == 0)
	{
		operation(RA, a, NULL);
		operation(RA, a, NULL);
	}
	else if (last == 0)
		operation(RRA, a, NULL);
	operation(PB, a, b);
	sort_three(a);
	operation(PA, a, b);
}

void sort_five(t_deque *a, t_deque *b)
{
	while (a->total > 3)
	{
		if (a->top->idx < 2)
			operation(PB, a, b);
		else
			operation(RA, a, NULL);
	}
	sort_three(a);
	while(b->total)
		operation(PA, a, b);
	if (a->top->idx != 0)
		operation(SA, a, b);
}
