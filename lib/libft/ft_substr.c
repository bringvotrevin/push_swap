/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:44:52 by dim               #+#    #+#             */
/*   Updated: 2020/12/30 04:30:43 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*arr;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size <= start)
		return (ft_strdup(""));
	if (size < (start + len))
		i = size - start;
	else
		i = len;
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (arr == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		arr[j] = s[j + start];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
