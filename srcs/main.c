/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:24:56 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 21:08:31 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_lst	*tail_a;

	tail_a = ft_lstnew_t();
	if (argc < 2)
		return (0);
	parse(argv, tail_a);
	push_swap(tail_a);
	free_lst(tail_a);
	return (1);
}
