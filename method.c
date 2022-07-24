/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:44:49 by jabae             #+#    #+#             */
/*   Updated: 2022/07/24 23:27:01 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_deque *dq)
{
	t_node	*node;

	if (dq->total < 2)
		return ;
	node = dq->top;
	dq->top = node->next;
	dq->top->prev = NULL;
	node->next = NULL;
	node->prev = dq->bottom;
	dq->bottom->next = node;
	dq->bottom = node;
}

void	reverse_rotate(t_deque *dq)
{
	t_node	*node;

	if (dq->total < 2)
		return ;
	node = dq->bottom;
	dq->bottom = node->prev;
	dq->bottom->next = NULL;
	node->prev = NULL;
	node->next = dq->top;
	dq->top->prev = node;
	dq->top = node;
}

void	swap(t_deque *dq)
{
	t_node	*node1;
	t_node	*node2;

	if (dq->total < 2)
		return ;
	node1 = dq->top->next;
	node2 = dq->top;
	node2->next = node1->next;
	node2->prev = node1;
	dq->top = node1;
	if (node2->next)
		node2->next->prev = node2; // node2 node1 node3 // node3의 prev 포인터가 node1을 가리키도록
	else
		dq->bottom = node2; // node 두 개만 있을 때
	node1->prev = NULL;
	node1->next = node2;
}

void	push(t_deque *dst, t_deque *src)
{
	t_node	*node;

	if (src->total == 0)
		return ;
	node = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else // 하나만 있을 때 NULL->prev는 터지니까, top이자 bottom이 됨
		src->bottom = NULL;
	node->next = dst->top;
	node->prev = NULL;
	if (dst->top)
		dst->top->prev = node;
	else // 아무것도 없을 때
		dst->bottom = node;
	dst->top = node;
	dst->total++;
	src->total--;
}
