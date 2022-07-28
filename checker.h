/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:08:35 by jabae             #+#    #+#             */
/*   Updated: 2022/07/28 21:11:25 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <limits.h>

# define READ_EOF 0
# define READ_SUCCESS 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
/* method_bonus */
void	ss(t_deque *a, t_deque *b, int isChecker);
void	rr(t_deque *a, t_deque *b, int isChecker);
void	rrr(t_deque *a, t_deque *b, int isChecker);

#endif
