/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:00:46 by jabae             #+#    #+#             */
/*   Updated: 2022/07/28 20:56:40 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

void	ss(t_deque *a, t_deque *b, int isChecker)
{
	swap(a);
	swap(b);
	if (!isChecker)
		write(1, "ss\n", 3);
}

void	rr(t_deque *a, t_deque *b, int isChecker)
{
	rotate(a);
	rotate(b);
	if (!isChecker)
		write(1, "rr\n", 3);
}

void	rrr(t_deque *a, t_deque *b, int isChecker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!isChecker)
		write(1, "rrr\n", 3);
}
