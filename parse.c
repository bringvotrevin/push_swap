/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:26:06 by dim               #+#    #+#             */
/*   Updated: 2021/06/07 03:43:58 by dim              ###   ########.fr       */
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
	int		num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		arr = make_arr(argv[i]);
		while (arr[j])
		{
			num = ft_atol(arr[j]);
			over_range(num);
			new = ft_lstnew_s(num);
			ft_lstadd_tail(tail_a, new);
			j++;
		}
		memfree(arr);
		i++;
	}
}

void	over_range(int num)
{
	if (num > 2147483647 || num < -2147483648)
		rt_error();
}

t_st	ft_lstnew_s(int number)
{
	t_st	*lst;

	lst = (t_st *)malloc(sizeof(t_st));
	if (lst == NULL)
		return (NULL);
	lst->num = number;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void	memfree(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

void	rt_error(char **arr)
{
	memfree(arr);
	write(2, "Error\n", 6);
	exit();
}

char	**make_arr(char *str)
{
	char	**arr;
	int		i;

	i = 0;
	arr = NULL;
	arr = ft_split(str, ' ');
	if (arr == NULL || arr[0] == NULL)
		rt_error(arr);
	check_overlen(arr);
	return (arr);
}

void	check_overlen(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) > 11)
			rt_error(arr);
		i++;
	}
}

void	ft_lstadd_tail(t_lst *tail_lst, t_st *new)
{
	if (tail_lst == NULL || new = NULL)
		rt_error(//??);
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
	tail_lst->size++;
}
