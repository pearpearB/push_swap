/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:46:18 by jabae             #+#    #+#             */
/*   Updated: 2022/07/24 23:27:50 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation2(int op, t_deque *a, t_deque *b)
{
	if (op == RA)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (op == RB)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	else if (op == RRA)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (op == RRB)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
}

void	operation(int op, t_deque *a, t_deque *b)
{
	if (op == PA)
	{
		push(a, b);
		write(1, "pa\n", 3);
	}
	else if (op == PB)
	{
		push(b, a);
		write(1, "pb\n", 3);
	}
	else if (op == SA)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	else if (op == SB)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	else
		operation2(op, a, b);
}
