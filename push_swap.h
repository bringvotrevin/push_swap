/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:18:57 by dim               #+#    #+#             */
/*   Updated: 2021/06/07 15:37:14 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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

