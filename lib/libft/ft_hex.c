/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:44:16 by gialexan          #+#    #+#             */
/*   Updated: 2022/10/02 02:33:01 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_hexadecimal(unsigned long n)
{
	if (n != 0)
		return (count_hexadecimal(n / 16) + 1);
	return (0);
}

static char	*hexadecimal_to_str(unsigned long n, char *base)
{
	int		size;
	char	*hexadecimal;

	size = count_hexadecimal(n);
	hexadecimal = (char *) malloc ((size + 1) * sizeof(char));
	if (!hexadecimal)
		return (NULL);
	hexadecimal[size] = '\0';
	while (size > 0)
	{
		hexadecimal[size - 1] = base[n % 16];
		n /= 16;
		size--;
	}
	return (hexadecimal);
}

int	ft_hex(unsigned long nb, char *base)
{
	int				len;
	char			*str;

	if (nb < 1)
		return (md_putchar('0'));
	str = hexadecimal_to_str(nb, base);
	len = md_putstr(str);
	free(str);
	str = NULL;
	return (len);
}
