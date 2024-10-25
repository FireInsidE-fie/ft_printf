/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:44:46 by estettle          #+#    #+#             */
/*   Updated: 2024/10/25 13:56:24 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// libft
# include "libft/libft.h"

// libraries
# include <stdarg.h> // for variadic functions and va_ helpers
# include <unistd.h> // for write()

// function prototypes
int		ft_printf(const char *format, ...);
void	ft_putuns(unsigned int n);
void	ft_putnbr_base(int nb, char *charset);
void	process_string(char *str, int *count);

#endif
