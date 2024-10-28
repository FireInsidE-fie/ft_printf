/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:16:14 by estettle          #+#    #+#             */
/*   Updated: 2024/10/25 15:09:58 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Puts a number to the standard input in the specified base.
 *
 * @param nb The number to print.
 * @param charset The charset for the base (length determines the base number).
 */
static void	ft_putnbr_base(unsigned int nb, char *charset, int *count)
{
	unsigned short	base;

	base = ft_strlen(charset);
	if (nb >= base)
	{
		ft_putnbr_base(nb / base, charset, count);
		nb = nb % base;
	}
	if (nb < base)
	{
		(*count)++;
		ft_putchar_fd(charset[nb], 1);
	}
}

void	process_hex(unsigned int nb, int *count, int is_uppercase)
{
	if (is_uppercase)
		ft_putnbr_base(nb, "0123456789ABCDEF", count);
	else
		ft_putnbr_base(nb, "0123456789abcdef", count);
}
