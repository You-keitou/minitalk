/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:04:35 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/29 20:00:56 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>	// kill(), sigaction()
# include <stdlib.h>	// malloc(), free()
# include <unistd.h>	// write(), usleep()
# include <limits.h>	// INT_MAX, INT_MIN

int	ft_printf(const char *format, ...);
int	ft_atoi(const char *nptr);

#endif