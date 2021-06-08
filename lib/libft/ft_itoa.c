/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 17:56:02 by dim               #+#    #+#             */
/*   Updated: 2021/05/14 20:12:14 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				for_len(long long n)
{
	int len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*make_string(long long n, size_t minus)
{
	size_t	len;
	char	*str;

	len = for_len(n);
	str = (char *)malloc(sizeof(char) * len + 1 + minus);
	return (str);
}

char			*for_minus(char *str, long long n)
{
	size_t len;

	len = for_len(n) + 1;
	str[len] = '\0';
	while (len-- > 1)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	size_t		minus;
	size_t		len;
	long long	nbr;
	char		*str;

	nbr = (long long)n;
	nbr = (nbr < 0 ? -nbr : nbr);
	minus = (n < 0 ? 1 : 0);
	len = for_len(nbr);
	str = make_string(nbr, minus);
	if (str == NULL)
		return (NULL);
	if (minus)
		for_minus(str, nbr);
	else
	{
		str[len] = '\0';
		while (len--)
		{
			str[len] = nbr % 10 + '0';
			nbr /= 10;
		}
	}
	return (str);
}
