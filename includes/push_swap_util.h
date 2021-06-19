/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:44:04 by dim               #+#    #+#             */
/*   Updated: 2021/06/19 21:36:50 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTIL_H
# define PUSH_SWAP_UTIL_H

# include "lst.h"
# include "util.h"
# include "push_swap.h"

t_st	*check_min(t_lst *tail_a, int size);
t_st	*check_max(t_lst *tail_a, int size);
int		check_ascending(t_lst *tail_a, t_lst *tail_b);
void	three_input(t_lst *tail_a, t_lst *tail_b);
void	five_input(t_lst *tail_a, t_lst *tail_b);
void	count_input(t_lst *tail_a, t_lst *tail_b);
int		push_swap(t_lst *tail_a);
int		*arr_forsort(t_lst *tail_lst);
int		more_than_five(t_lst *tail_a, t_lst *tail_b);
void	sort(int left, int right, int *arr);
void	int_swap(int *a, int *b);

#endif
