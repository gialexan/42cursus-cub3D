/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:24:10 by gialexan          #+#    #+#             */
/*   Updated: 2022/06/20 19:29:25 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;

	i = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i *= -1;
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		i = i % 10;
	}
	if (i <= 9)
		ft_putchar_fd(i + 48, fd);
}
