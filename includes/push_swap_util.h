/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:44:04 by dim               #+#    #+#             */
/*   Updated: 2021/06/13 16:44:20 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTIL_H
# define PUSH_SWAP_UTIL_H

# include "lst.h"
# include "util.h"
# include "push_swap.h"

t_st	*check_min(t_lst *tail_a);
t_st	*check_max(t_lst *tail_a);
int		check_ascending(t_lst *tail_a, t_lst *tail_b);
int		three_input(t_lst *tail_a, t_lst *tail_b);
void	count_input(t_lst *tail_a, t_lst *tail_b);
int		push_swap(t_lst *tail_a);

#endif