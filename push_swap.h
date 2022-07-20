/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:43:39 by jabae             #+#    #+#             */
/*   Updated: 2022/07/20 22:16:50 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int	num;
	int	idx;
}	t_node;

typedef struct s_deque
{
	t_node	*top;
	t_node	*bottom;
	int			total;
}	t_deque;

# endif

/* parsing*/
void	parsing(char **argv, t_deque *a);

/* utils */
int	ft_error(void);
void	init_deque(t_deque *deque);
long long ft_atoll(const char *s);
int ft_isnum(const char *s);
