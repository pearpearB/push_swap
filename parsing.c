/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:05:24 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 23:03:07 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void add_new_node(int num, t_deque *a)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->num = num;
	new->idx = 0;
	if (a->total == 0)
	{
		a->top = new;
		a->bottom = new;
	}
	else
	{
		new->prev = a->bottom; // 한 번 더 보기
		new->next = NULL;
		a->bottom->next = new;
		a->bottom = new;
	}
	a->total++;
}

static void check_and_add_input(const char *s, t_deque *a)
{
	long long num;

	num = ft_atoll(s);
	if (!(ft_isnum(s)) || num > 2147483647 || num < -2147483648)
		ft_error();
	add_new_node(num, a);
}

static void	split_input_str(const char *s, t_deque *a)
{
	char **sp_str;
	int i;

	sp_str = ft_split(s, ' ');
	if (sp_str == NULL) // 할당 못 받았을 때
		exit(EXIT_FAILURE);
	if (!sp_str[0]) // 공백만 있는 문자열일 때
		ft_error();
	i = -1;
	while (sp_str[++i] != NULL)
	{
		check_and_add_input(sp_str[i], a);
		free(sp_str[i]);
	}
	free(sp_str);
}

void	parsing(char **argv, t_deque *a)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' '))
			split_input_str(argv[i], a);
		else
			check_and_add_input(argv[i], a);
	}
}