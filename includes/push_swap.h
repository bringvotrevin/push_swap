/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:18:57 by dim               #+#    #+#             */
/*   Updated: 2021/06/19 20:29:17 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "util.h"
# include "lst.h"
# include "libft.h"

void	st_push(t_lst *stack_loss, t_lst *stack_gain);
void	pb(t_lst *tail_a, t_lst *tail_b);
void	pa(t_lst *tail_a, t_lst *tail_b);
void	st_swap(t_st *stack);
void	sa(t_lst *tail_a);
void	sb(t_lst *tail_b);
void	ss(t_lst *tail_a, t_lst *tail_b);
void	st_rotate(t_lst *tail_lst);
void	ra(t_lst *tail_a);
void	rb(t_lst *tail_b);
void	rr(t_lst *tail_a, t_lst *tail_b);
void	st_rev_rotate(t_lst *tail_lst);
void	rra(t_lst *tail_a);
void	rrb(t_lst *tail_b);
void	rrr(t_lst *tail_a, t_lst *tail_b);

#endif
