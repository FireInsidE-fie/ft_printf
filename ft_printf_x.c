/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:16:14 by estettle          #+#    #+#             */
/*   Updated: 2024/10/25 14:26:34 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Puts a number to the standard input in the specified base.
 *
 * @param nb The number to print.
 * @param charset The charset for the base (length determines the base number).
 */
static void	ft_putnbr_base(int nb, char *charset)
{
	short	base;

	base = ft_strlen(charset);
	if (nb >= base)
	{
		ft_putnbr_base(nb / base, charset);
		nb = nb % base;
	}
	if (nb < base)
		ft_putchar_fd(charset[nb], 1);
}

void	process_hex(int nb, int *count)
{
	
}
