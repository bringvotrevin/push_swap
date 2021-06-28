/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:20:27 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 20:13:49 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "lst.h"

void	memfree(char **arr, t_lst *tail_lst);
void	free_arr(char **arr);
void	free_lst(t_lst *tail_lst);
t_lst	*ft_lstnew_t(void);
t_st	*ft_lstnew_s(int number);
void	ft_lstadd_tail(char **arr, t_lst *tail_lst, t_st *new);
void	rt_error(char **arr, t_lst *tail_lst);

void	set_pivot(int *arr, t_pivot *pivot, int size);
int		*arr_forsort(t_lst *tail_lst);
void	quick_sort(int left, int right, int *arr);
t_st	*check_min(t_lst *tail_a, int size);
t_st	*check_max(t_lst *tail_a, int size);
int		check_ascending(t_lst *tail_lst, int size);
void	init_lstsave(t_save *save);
void	int_swap(int *a, int *b);

#endif
