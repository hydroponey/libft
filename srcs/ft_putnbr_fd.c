/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:28:13 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/04 22:13:09 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	temp;

	temp = n;
	if (temp < 0)
	{
		ft_putchar_fd('-', fd);
	}
	if (n % 10 > 0)
	{
		temp = n % 10;
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((temp % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd(temp + '0', fd);
	}
}
