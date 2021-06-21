/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:44:04 by dim               #+#    #+#             */
/*   Updated: 2021/06/22 04:33:15 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "lst.h"
# include "util.h"
# include "error_util.h"
# include "ft_push_swap.h"

void	three_input(t_lst *tail_a, t_lst *tail_b);
void	five_input(t_lst *tail_a, t_lst *tail_b);
void	count_input(t_lst *tail_a, t_lst *tail_b);
int		push_swap(t_lst *tail_a);
int		*arr_forsort(t_lst *tail_lst);
int		more_than_five(t_lst *tail_a, t_lst *tail_b);
void	quick_sort(int left, int right, int *arr);
void	int_swap(int *a, int *b);
void	sort_stack(t_lst *tail_a, t_lst *tail_b, int *arr);

#endif
