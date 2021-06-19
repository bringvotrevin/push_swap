/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 03:11:50 by dim               #+#    #+#             */
/*   Updated: 2021/06/19 20:28:13 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_rotate(t_lst *tail_lst)
{
	tail_lst->tail = tail_lst->tail->next;
}

void	ra(t_lst *tail_a)
{
	if (tail_a->size > 1)
		st_rotate(tail_a);
	write(1, "ra\n", 3);
}

void	rb(t_lst *tail_b)
{
	if (tail_b->size > 1)
		st_rotate(tail_b);
	write(1, "rb\n", 3);
}

void	rr(t_lst *tail_a, t_lst *tail_b)
{
	if (tail_a->size > 1)
		st_rotate(tail_a);
	if (tail_b->size > 1)
		st_rotate(tail_b);
	write(1, "rr\n", 3);
}
