/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:39:33 by dim               #+#    #+#             */
/*   Updated: 2021/06/09 02:43:52 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //remove it!@#$%$^%&^*&(&*^&%^$#$@!@~

typedef struct s_st
{
	int				num;
	struct s_st		*next;
	struct s_st		*prev;
}	t_st;

typedef struct s_lst
{
	int				size;
	t_st		*tail;
}	t_lst;


#endif
