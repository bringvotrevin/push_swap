/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:54:21 by dim               #+#    #+#             */
/*   Updated: 2021/06/22 19:05:41 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	n_pa(t_lst *tail_a, t_save *save)
{
	pa(tail_a);
	save->n_pa++;
}

void	n_pb(t_lst *tail_b, t_save *save)
{
	pb(tail_b);
	save->n_pb++;
}

void	n_ra(t_lst *tail_a, t_save *save)
{
	ra(tail_a);
	save->n_ra++;
}

void	n_rb(t_lst *tail_b, t_save *save)
{
	rb(tail_b);
	save->n_rb++;
}

void	n_rra(t_lst *tail_a, t_save *save)
{
	rra(tail_a);
	save->n_rra++;
}

void	n_rrb(t_lst *tail_b, t_save *save)
{
	rrb(tail_b);
	save->n_rrb++;
}

void	n_rrr(t_lst *tail_a, t_lst *tail_b, t_save *save)
{
	rrr(tail_a, tail_b);
	save->n_rrr++;
}
