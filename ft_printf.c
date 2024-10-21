/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:57:28 by estettle          #+#    #+#             */
/*   Updated: 2024/10/19 23:58:03 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_conversion(char c)
{
	if (c == 'c')
		write(1, &c, 1);
	else if (c == 's')
		// strings
	else if (c == 'p')
		// pointer addresses
	else if (c == 'd' || c == 'i')
		// decimal integers (?)
	else if (c == 'u')
		// unsigned integers (?)
	else if (c == 'x')
		// hexadecimal lowercase
	else if (c == 'X')
		// hexadecimal uppercase (fuse with lowercase?)
	else if (c == '%')
		write(1, "%", 1);
}

/* here's the plan : 
 * go through the format string character by character and print it, unless
 * there's a % in which case you go to an alternate function and begin the
 * appropriate conversion, depending on the character that occurs after the %
*/
int ft_printf(const char *format, ...)
{
	while (*format)
	{
		if (*(format++) == '%') // be careful, I'm not sure if format doesn't get incremented BEFORE dereferencing
			process_conversion(*(format++));
	}
	return (0);
}
