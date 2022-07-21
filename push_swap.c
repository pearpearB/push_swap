/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:42:14 by jabae             #+#    #+#             */
/*   Updated: 2022/07/21 21:36:20 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void operation2(int op, t_deque *a, t_deque *b)
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

void operation(int op, t_deque *a, t_deque *b)
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

static int is_sorted(t_deque *a)
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

static void push_swap(t_deque *a, t_deque *b)
{
	if (a->total == 2)
		operation(SA, a, NULL);
	else if (a->total == 3)
		sort_three(a);
	else if (a->total == 4)
		sort_four(a, b);
	else if (a->total == 5)
		sort_five(a, b);
	// else
	// {
	// 	a_to_b(a, b);
	// 	b_to_a(a, b);
	// }
}

int main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;

	if(argc < 2)
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

// check
	t_node *c = a.top; // 뒤로 연결 확인
	while(c)
	{
		printf("%d\n", c->num);
		c = c->next;
	}
	return (0);
}

// gcc ./push_swap.c ./parsing.c ./utils.c method.c -I ./libft -L./libft -lft