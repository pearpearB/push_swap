/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:01:21 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 22:52:26 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_putendl_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	init_deque(t_deque *deque)
{
	deque->top = NULL;
	deque->bottom = NULL;
	deque->total = 0;
}

long long ft_atoll(const char *s)
{
	int i;
	int sign;
	long long result;

	i = 0;
	sign = 1;
	result = 0;
	while (((s[i] >= 9 && s[i] <= 13) || s[i] == ' ') && s[i])
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(s[i]) && s[i])
	{
		result = result * 10 + (s[i] - '0');
		if (sign * result > 2147483647 || sign * result < -2147483648)
			break ;
		s++;
	}
	return (sign * result);
}

int ft_isnum(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
