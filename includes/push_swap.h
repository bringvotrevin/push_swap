/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:44:04 by dim               #+#    #+#             */
/*   Updated: 2021/06/26 02:27:48 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "lst.h"
# include "util.h"
# include "error_util.h"
# include "ft_push_swap.h"

void	three_input(t_lst *tail_lst);
void	five_input(t_lst *tail_a, t_lst *tail_b);
int		more_than_five(t_lst *tail_a, t_lst *tail_b);
int		push_swap(t_lst *tail_a);
void	set_pivot(int *arr, t_pivot *pivot, int size);
int		*arr_forsort(t_lst *tail_lst);
void	quick_sort(int left, int right, int *arr);
void	int_swap(int *a, int *b);

void	sort_stack(t_lst *tail_a, t_lst *tail_b, int *arr);
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
