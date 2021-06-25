/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:20:27 by dim               #+#    #+#             */
/*   Updated: 2021/06/25 15:18:07 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "lst.h"

t_st	*check_min(t_lst *tail_a, int size);
t_st	*check_max(t_lst *tail_a, int size);
int		check_ascending(t_lst *tail_lst, int size);
void	init_lstsave(t_save *save);
void	int_swap(int *a, int *b);
#endif
