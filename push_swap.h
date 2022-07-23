/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:43:39 by jabae             #+#    #+#             */
/*   Updated: 2022/07/23 16:41:46 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define PA 0
# define PB 1
# define RA 2
# define RB 3
# define SA 4
# define SB 5
# define RRA 6
# define RRB 7

# define LONG_MAX 9223372036854775807
# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

/* parsing*/
void	parsing(char **argv, t_deque *a);
/* method */
void	rotate(t_deque *dq);
void	reverse_rotate(t_deque *dq);
void	swap(t_deque *dq);
void	push(t_deque *dst, t_deque *src);
/* operation */
void	operation2(int op, t_deque *a, t_deque *b);
void	operation(int op, t_deque *a, t_deque *b);
/* sorting */
void	a_to_b(t_deque *a, t_deque *b, int chunk);
void	b_to_a(t_deque *a, t_deque *b);
/* sorting_small */
int		is_sorted(t_deque *a);
void	sort_three(t_deque *a);
void	sort_four(t_deque *a, t_deque *b);
void	sort_five(t_deque *a, t_deque *b);
/* utils */
int		ft_error(void);
void	init_deque(t_deque *dq);
void	free_deque(t_deque *dq);
long long ft_atoll(const char *s);
int	ft_isnum(const char *s);

# endif
