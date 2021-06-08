/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 02:20:26 by dim               #+#    #+#             */
/*   Updated: 2021/06/06 22:05:50 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	int		i;
	int		f;
	int		b;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	f = i;
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i != 0)
		i--;
	b = i;
	if (f > b)
		return (ft_strdup(""));
	if (!(arr = (char *)malloc(sizeof(char) * (b - f + 2))))
		return (NULL);
	i = 0;
	ft_strlcpy(arr, s1 + f, b - f + 2);
	return (arr);
}
