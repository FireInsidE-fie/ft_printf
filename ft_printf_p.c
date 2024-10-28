/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:58:59 by estettle          #+#    #+#             */
/*   Updated: 2024/10/27 21:13:39 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(uintptr_t nb, char *charset, int *count)
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

void	process_ptr(void *ptr, int *count)
{
	uintptr_t	address;

	address = (uintptr_t)ptr;
	write(1, "0x", 2);
	*count += 2;
	if (!ptr)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	ft_putnbr_base(address, "0123456789abcdef", count);
}
