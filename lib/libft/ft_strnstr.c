/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 01:43:12 by dim               #+#    #+#             */
/*   Updated: 2021/01/04 20:19:26 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*find == '\0')
		return ((char *)s);
	while (s[i] && i < len)
	{
		if (s[i] == find[0])
		{
			j = 0;
			while (find[j] && i + j < len)
			{
				if (s[j + i] != find[j])
					break ;
				j++;
			}
			if (find[j] == 0)
				return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}
