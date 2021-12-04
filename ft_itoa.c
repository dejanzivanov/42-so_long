/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:48:54 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/14 15:21:37 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

/*
**	Allocates (with malloc(3)) and returns a string
**	representing the integer received as an argument.
**	Negative numbers must be handled.
*/

static int	n_len(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		if (n != -2147483648)
			count += 1;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*a;
	int			l;
	long long	nb;

	nb = n;
	l = n_len(nb);
	a = (char *)malloc(sizeof(char) * (l + 1));
	if (!a)
		return (NULL);
	a[l--] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		if (nb != -2147483648)
			a[0] = '-';
	}
	if (nb == 0)
		a[l] = 0 + '0';
	while (nb > 0)
	{
		a[l--] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}

/*	1) In the first part of the function we are accepting parameter and convert
**	it to long long so we do not encounter any problems with the INT overflow or
**	int range(INT_MIN and INT_MAX).
**
**	2) In the second part we are checking if the value is negative in order to
**	know how much memory to allocate, if the value is negative, we allocate 2
**	memory slots(1 for '-' and 1 for terminating null sign '\0'). If it is not
**	negative then we only use 1, for the null terminating sign.
**
**	3) As a fail safe switch we have check for INT_MIN value, and write that
**	into the string using ft_strlcpy function and we return that pointer.
**
**	4) At the line 79 we are passing parameters to a function, that writes all
**	the number in the str pointer. Function works recursivelly simmilar to
**	ft_putnbr. Division and modulus by 10 are used until we get the last
**	digit, convert it into a character, and then write it into designated spot
**	in pointer. Based on digit value if it is positive or negative starting
**	point is changed from str[0] to str[1].
*/