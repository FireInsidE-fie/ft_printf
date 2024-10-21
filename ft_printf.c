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

/* here's the plan : 
 * go through the format string character by character and print it, unless
 * there's a % in which case you go to an alternate function and begin the
 * appropriate conversion, depending on the character that occurs after the %
*/
int ft_printf(const char *format, ...)
{
	(void)format;
	return (0);
}
