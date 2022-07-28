/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:08:15 by jabae             #+#    #+#             */
/*   Updated: 2022/07/28 21:00:58 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

static void	operating(char *op, t_deque *a, t_deque *b)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		operation(PA, a, b, CHECKER);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		operation(PB, a, b, CHECKER);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		operation(SA, a, NULL, CHECKER);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		operation(SB, NULL, b, CHECKER);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(a, b, CHECKER);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		operation_R(RA, a, NULL, CHECKER);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		operation_R(RB, NULL, b, CHECKER);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(a, b, CHECKER);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		operation_R(RRA, a, NULL, CHECKER);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		operation_R(RRB, NULL, b, CHECKER);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(a, b, CHECKER);
	else
		ft_error();
}

static void	checking(t_deque *a, t_deque *b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (op == NULL)
			break;
		operating(op, a, b);
		free(op);
	}
}

static void	last_checking(t_deque *a, t_deque *b)
{
	if (is_sorted(a) && b->total == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_deque(a);
	free_deque(b);
}

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;

	if (argc < 2)
		return (0);
	init_deque(&a);
	init_deque(&b);
	parsing(argv, &a);
	checking(&a, &b);
	last_checking(&a, &b);
	return (0);
}