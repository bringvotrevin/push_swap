/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 03:11:50 by dim               #+#    #+#             */
/*   Updated: 2021/06/03 03:12:04 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_lst *tail_lst)
{
	tail_lst->tail = tail_lst->tail->next;
}

void	ra(t_lst *tail_a)
{
	ft_rotate(tail_a);
	write(1, "ra\n", 3);
}

void	rb(t_lst *tail_b)
{
	ft_rotate(tail_b);
	write(1, "rb\n", 3);
}

void	rr(t_lst *tail_a, t_lst *tail_b)
{
	ft_rotate(tail_a);
	ft_rotate(tail_b);
	write(1, "rr\n", 3);
}
