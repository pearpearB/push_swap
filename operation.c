/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:46:18 by jabae             #+#    #+#             */
/*   Updated: 2022/07/28 20:50:03 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_R(int op, t_deque *a, t_deque *b, int isChecker)
{
	if (op == RA)
	{
		rotate(a);
		if (!isChecker)
			write(1, "ra\n", 3);
	}
	else if (op == RB)
	{
		rotate(b);
		if (!isChecker)
			write(1, "rb\n", 3);
	}
	else if (op == RRA)
	{
		reverse_rotate(a);
		if (!isChecker)
			write(1, "rra\n", 4);
	}
	else if (op == RRB)
	{
		reverse_rotate(b);
		if (!isChecker)
			write(1, "rrb\n", 4);
	}
}

void	operation(int op, t_deque *a, t_deque *b, int isChecker)
{
	if (op == PA)
	{
		push(a, b);
		if (!isChecker)
			write(1, "pa\n", 3);
	}
	else if (op == PB)
	{
		push(b, a);
		if (!isChecker)
			write(1, "pb\n", 3);
	}
	else if (op == SA)
	{
		swap(a);
		if (!isChecker)
			write(1, "sa\n", 3);
	}
	else if (op == SB)
	{
		swap(b);
		if (!isChecker)
			write(1, "sb\n", 3);
	}
}
