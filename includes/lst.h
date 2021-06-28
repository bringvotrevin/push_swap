/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:39:33 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 12:08:59 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <unistd.h>

typedef struct	s_st
{
	long long		num;
	struct s_st		*next;
	struct s_st		*prev;
}				t_st;

typedef struct	s_lst
{
	int			size;
	t_st		*tail;
}				t_lst;

typedef struct	s_save
{
	int		n_pa;
	int		n_pb;
	int		n_ra;
	int		n_rb;
}				t_save;

typedef struct	s_pivot
{
	int		*p1;
	int		*p2;
	int		*p3;
}				t_pivot;

#endif
