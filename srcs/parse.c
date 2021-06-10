/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:26:06 by dim               #+#    #+#             */
/*   Updated: 2021/06/10 21:28:13 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util.h"
#include "lst.h"

void	printtail(t_lst *tail_a)
{
	t_st	*cur;
	int		size;

	size = tail_a->size;
	cur = tail_a->tail->next;
	while (size--)
	{
		printf("lst->num : %lld\n", cur->num);
		cur = cur->next;
	}
}

void	rt_error(char **arr, t_lst *tail_lst)
{
	if (arr && tail_lst)
		memfree(arr, tail_lst);
	else if (arr && tail_lst == NULL)
		memfree(arr, (t_lst *)NULL);
	else if (arr == NULL && tail_lst)
		memfree((char **)NULL, tail_lst);
	write(2, "Error\n", 6);
	exit(-1);
}

/*
void	isover_range(int num, char **arr, )
{
	if (num > 2147483647 || num < -2147483648)
		rt_error(arr, tail_lst);
}
*/

void	check_overlen(char **arr, t_lst *tail_lst)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		if (len > 11)
			rt_error(arr, tail_lst);
		i++;
	}
}

char	**make_arr(char *str, t_lst *tail_a)
{
	char	**arr;
	int		i;

	i = 0;
	arr = NULL;
	arr = ft_split_str(str, " ");
	if (arr == NULL || arr[0] == NULL)
		rt_error(arr, tail_a);
	check_overlen(arr, tail_a);
	return (arr);
}

void	parse(char **argv, t_lst *tail_a)
{
	t_st		*new;
	char		**arr;
	long long	num;
	int			i;
	int			j;

	i = 1;
	while (argv[i])
	{
		arr = make_arr(argv[i], tail_a);
		j = 0;
		while (arr[j])
		{
			num = ft_atol(arr[j]);
			if (num > 2147483647 || num < -2147483648)
				rt_error(arr, tail_a);
			new = ft_lstnew_s(num);
			ft_lstadd_tail(arr, tail_a, new);
			// free(arr[j]);
			// arr[j] = NULL;1234567890-09876543
			j++;
		}
		free_arr(arr);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	t_lst	*tail_a;

	tail_a = ft_lstnew_t();
	if (argc < 2 || tail_a == NULL)
		return (0);
	parse(argv, tail_a);
	printtail(tail_a);
	free_lst(tail_a);
	return (0);
}