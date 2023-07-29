/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:03:54 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/29 20:04:17 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# define BUFFERSIZE 1024

typedef struct t_buffer
{
	char	buffer[BUFFERSIZE];
	size_t	len;
	ssize_t	ret;
}	s_buffer;

int		ft_printf(const char *fmt, ...);
void	ft_fflush(s_buffer *Buffer);
void	ft_putchar(s_buffer *Buffer, char c);
void	ft_putstr(s_buffer *Buffer, char *str);
void	itoa_ten(int num, s_buffer *Buffer);
void	itoa_unsigned(int num, s_buffer *Buffer);
void	itoa_x(unsigned int num, char *base, s_buffer *Buffer);
void	convert_p(uintptr_t num, char *base, s_buffer *Buffer);
#endif