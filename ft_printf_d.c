/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:26:11 by estettle          #+#    #+#             */
/*   Updated: 2024/10/27 21:06:49 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_int_len(int nb)
{
	int	divider;
	int	digit_count;

	if (nb == -2147483648)
		return (11);
	divider = 1;
	digit_count = 1;
	if (nb < 0)
	{
		digit_count++;
		nb = -nb;
	}
	while ((nb / divider) >= 10)
	{
		divider *= 10;
		digit_count++;
	}
	return (digit_count);
}

void	process_dec(int nb, int *count)
{
	ft_putnbr_fd(nb, 1);
	*count += get_int_len(nb);
}
