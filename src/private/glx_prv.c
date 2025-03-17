/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_prv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:37:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 13:37:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

void	glx_error(t_glx *self, char *mes)
{
	ft_putstr_fd(mes, STDERR_FILENO);
	self->quit(self, EXIT_FAILURE);
}