/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:54:21 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 11:47:28 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	n_pa(t_lst *tail_a, t_lst *tail_b, t_save *save)
{
	pa(tail_a, tail_b);
	save->n_pa++;
}

void	n_pb(t_lst *tail_a, t_lst *tail_b, t_save *save)
{
	pb(tail_a, tail_b);
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

int		cur_next(t_st **cur)
{
	*cur = (*cur)->next;
	return (1);
}
