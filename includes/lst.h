/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:39:33 by dim               #+#    #+#             */
/*   Updated: 2021/06/08 16:40:09 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

typedef struct s_lst
{
	int			size;
	struct t_st *tail;
}	t_lst;

typedef struct s_st
{
	int			num;
	struct s_st	*next;
	struct s_st *prev;
}	t_st;
