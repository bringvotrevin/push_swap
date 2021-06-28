/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:44:04 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 12:11:34 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "lst.h"
# include "util.h"
# include "error_util.h"
# include "ft_push_swap.h"

void	push_swap(t_lst *tail_a);
void	three_input(t_lst *tail_lst);
void	five_input(t_lst *tail_a, t_lst *tail_b);
void	five_input2(t_lst *tail_a, t_lst *tail_b, t_st *max, int flag);
void	more_than_five(t_lst *tail_a, t_lst *tail_b);
void	sort_stack(t_lst *tail_a, t_lst *tail_b, int *arr);
void	sort_stack_rest(t_lst *tail_a, t_lst *tail_b,\
t_pivot *pivot, t_save *save);
void	a_to_b(t_lst *tail_a, t_lst *tail_b, int *arr, int size);
void	ft_a_to_b(t_lst *tail_a, t_lst *tail_b, t_pivot *pivot, int size);
void	rr_stack(t_lst *tail_a, t_lst *tail_b, t_save *prev_save);
void	b_to_a(t_lst *tail_a, t_lst *tail_b, int *arr, int size);
void	ft_b_to_a(t_lst *tail_a, t_lst *tail_b, t_pivot *pivot, int size);
void	rra_to_b(t_lst *tail_a, t_lst *tail_b, int *arr, t_save *prev_save);
void	ft_rra_to_b(t_lst *tail_a, t_lst *tail_b, t_pivot *pivot, int size);
void	three_a_to_b(t_lst *tail_a, t_lst *tail_b, int size);
void	two_b_to_a(t_lst *tail_a, t_lst *tail_b, int size);
void	two_rra_to_b(t_lst *tail_a, int size);

#endif
