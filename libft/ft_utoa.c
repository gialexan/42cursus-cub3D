/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:01:19 by gialexan          #+#    #+#             */
/*   Updated: 2022/09/20 02:10:46 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int n)
{
	if (n < 10)
		return (1);
	return (count_digits(n / 10) + 1);
}

static int	isnegative(int n)
{
	return (n < 0);
}

char	*ft_utoa(unsigned int n)
{
	char			*dest;
	size_t			digit;
	unsigned int	number;
	int				negative;

	number = n;
	negative = isnegative(n);
	if (negative)
		number = n * -1;
	digit = count_digits(number);
	dest = (char *) malloc((digit + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[digit] = '\0';
	while (digit--)
	{
		dest[digit] = (number % 10) + '0';
		number /= 10;
	}
	return (dest);
}
