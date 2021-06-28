/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:39:12 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 20:37:15 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isspace(const char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

long long	ft_atoll(const char *str)
{
	long long	num;
	int			minus;
	int			i;

	num = 0;
	minus = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minus = -1;
		if (str[i] < '0' || str[i] > '9')
			return (123456789123456789);
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (123456789123456789);
	return (num * minus);
}
