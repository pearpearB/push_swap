/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:42:14 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 23:05:46 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;

	if(argc < 2)
		return (0);
	init_deque(&a);
	parsing(argv, &a);
	// ft_init_deque(&b);
	
	t_node *c = a.top;
	while(c)
	{
		printf("%d\n", c->num);
		c = c->next;
	}

	return (0);
}

// libft make 후
// gcc ./push_swap.c ./parsing.c ./utils.c -I ./libft -L./libft -lft
