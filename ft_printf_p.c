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

void	process_ptr(void *ptr, int *count)
{
	uintptr_t address;
	
	address = (uintptr_t)ptr;
	write(1, "0x", 2);
	*count += 2;
	if (!ptr)
	{
		write(1, "0", 1);
		*count += 1;
		return ;
	}
	process_hex(address, count, 0);
}
