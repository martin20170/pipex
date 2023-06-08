/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:49:47 by mphilip           #+#    #+#             */
/*   Updated: 2023/03/04 00:18:00 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../essentials/essentials.h"
# include <stdarg.h>
# include <limits.h>

int					ft_printf(const char *format, ...);
int					check_after_percent(char c);
int					putchar_pp(char c, int result);
int					option(char c, va_list args);
int					c_option(char c);
int					s_option(char *str);
int					p_option(void *ptr);
int					d_i_option(int nb);
int					u_option(unsigned int nb);
int					x_x_option(char c, long nb);
char				*base_ten_to_m(unsigned long long nbr, char *bs, int s);
unsigned long long	rec_div(unsigned long long nbr, unsigned long divis, int r);

#endif
