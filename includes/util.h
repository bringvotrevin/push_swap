/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:25:40 by dim               #+#    #+#             */
/*   Updated: 2021/06/09 02:44:11 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "lst.h"

void	memfree(char **arr, t_lst *tail_a);
void	free_arr(char **arr);
void	free_lst(t_lst *tail_lst);
t_lst	*ft_lstnew_t(void);
t_st	*ft_lstnew_s(int number);
void	ft_lstadd_tail(char **arr, t_lst *tail_lst, t_st *new);
void	rt_error(char **arr, t_lst *tail_lst);

#endif
