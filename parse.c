/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:26:06 by dim               #+#    #+#             */
/*   Updated: 2021/06/07 17:23:11 by dim              ###   ########.fr       */
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
	//free_lst(tail_a);
	return (0);
}

void	parse(char **argv, t_lst *tail_a)
{
	t_st	*new;
	char	**arr;
	int		num;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		arr = make_arr(argv[i]);
		j = 0;
		while (arr[j])
		{
			num = ft_atol(arr[j]);
			isover_range(num, arr);
			new = ft_lstnew_s(num);
			ft_lstadd_tail(tail_a, new);
			free(arr[j]);
			j++;
		}
		free(arr);
		i++;
	}
}

void	rt_error(void)
{
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

void	isover_range(int num, char **arr)
{
	if (num > 2147483647 || num < -2147483648)
		rt_error(arr);
}

void	check_overlen(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) > 11)
		{
			memfree(
			rt_error();
		i++;
	}
}
