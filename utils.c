/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:01:21 by jabae             #+#    #+#             */
/*   Updated: 2022/07/23 16:23:47 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	init_deque(t_deque *dq)
{
	dq->top = NULL;
	dq->bottom = NULL;
	dq->total = 0;
}

void free_deque(t_deque *dq)
{
	t_node *tmp;

	tmp = dq->top;
	while (dq->top)
	{
		dq->top = dq->top->next;
		free(tmp);
		tmp = dq->top;
	}
}

int ft_isnum(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

long long ft_atoll(const char *s)
{
	int sign;
	long long result;

	sign = 1;
	result = 0;
	while (((*s >= 9 && *s <= 13) || *s == ' ') && *s)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (ft_isdigit(*s) && *s)
	{
		if ((sign > 0 && result > LONG_MAX / 10) || \
			(sign < 0 && result > LONG_MAX + 1 / 10))
			break ;
		result = result * 10 + (*s - '0');
		s++;
	}
	return (sign * result);
}

