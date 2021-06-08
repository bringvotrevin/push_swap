/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 21:12:42 by dim               #+#    #+#             */
/*   Updated: 2021/01/04 22:56:06 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(unsigned int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	i = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = n * -1;
	}
	ft_putnbr(i, fd);
}
