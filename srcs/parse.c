/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:26:06 by dim               #+#    #+#             */
/*   Updated: 2021/06/25 16:05:21 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error_util.h"

/* void	printtail(t_lst *tail_a)
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
} */

void	check_overlen(char **arr, t_lst *tail_lst)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (arr[i])
	{
		while (arr[i][j] == '0')
			j++;
		len = ft_strlen(arr[i] + j);
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

void	check_repeatnum(t_lst *tail_a)
{
	int		size;
	int		size2;
	t_st	*cur;
	t_st	*compare;

	size = tail_a->size;
	cur = tail_a->tail;
	size2 = 0;
	while (size-- > 1)
	{
		size2 = size;
		compare = cur->next;
		while (size2-- > 0)
		{
			if (cur->num == compare->num)
				rt_error((char **)NULL, tail_a);
			compare = compare->next;
		}
		cur = cur->next;
	}
}

void	parse(char **argv, t_lst *tail_a)
{
	char		**arr;
	t_st		*new;
	int			i;
	int			j;
	long long	num;

	i = 1;
	while (argv[i])
	{
		arr = make_arr(argv[i], tail_a);
		j = 0;
		while (arr[j])
		{
			num = ft_atoll(arr[j]);
			if (num > 2147483647 || num < -2147483648)
				rt_error(arr, tail_a);
			new = ft_lstnew_s(num);
			ft_lstadd_tail(arr, tail_a, new);
			j++;
		}
		free_arr(arr);
		i++;
	}
	check_repeatnum(tail_a);
}

int		main(int argc, char *argv[])
{
	t_lst	*tail_a;
	int		i;

	tail_a = ft_lstnew_t();
	if (argc < 2 || tail_a == NULL)
		return (0);
	parse(argv, tail_a);
	// printtail(tail_a);
	i = push_swap(tail_a);
	if (i == 0)
		return (0);
	free_lst(tail_a);
	return (0);
}
