/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:26:06 by dim               #+#    #+#             */
/*   Updated: 2021/06/06 22:05:50 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_lst	*tail_a;

	tail_a = ft_lstnew_t();
	if (argc < 2 || tail_a == NULL)
		return (0);
	parse(argv, tail_a);


	return (0);
}

t_lst	ft_lstnew_t(void)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (tail_a == NULL)
		return (0);
	lst->size = 0;
	lst->tail = NULL;
	return (lst);
}

void	parse(char **argv, t_lst *tail_a)
{
	t_st	*new;
	char	**arr;
	char	*num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		arr = check_str(argv[i]);
		while (arr[j])
		{
			num = ft_atol();
			if (num > 2147483647 || num < -2147483648)
				error();
			new = ft_lstnew(num);
			ft_lstadd_tail(tail_a, new);
			tail_a->count++;
		}
		mem_free(arr);
		i++;
	}
}

t_st	ft_lstnew(int num)
{
}

void	mem_free()
{
}

void	error()
{
}

char	**check_str(char *str)
{
	char	**arr;
	int		i;

	i = 0;
	arr = NULL;
	arr = ft_split(str, ' ');
	if (arr == NULL || arr[0] == NULL)
		error();
	while (arr[i])
	{
		if (ft_strlen(arr[i]) > 11)
			error();
		i++;
	}
}

//void	ft_lstadd_tail(t_lst *tail_lst, t_st *new)
void	ft_lstadd_tail(t_st **tail, t_st *new)
{
	if (tail_lst == NULL || new = NULL)
		return ;
	if (tail_lst->tail == NULL)
	{
		tail_lst->tail = new;
		tail_lst->tail->next = new;
		tail_lst->tail->prev = new;
	}
	else
	{
		new->prev = tail_lst->tail;
		new->next = tail_lst->tail->next;
		tail_lst->tail->next->prev = new;
		tail_lst->tail->next = new;
		tail_lst->tail = new;
	}
}
