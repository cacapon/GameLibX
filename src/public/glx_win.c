/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:13:57 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 14:19:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx_win.h"

/**
 * @brief
 *
 * @param self
 */
void	glx_cls(t_glx *self)
{
	mlx_clear_window(self->mlx, self->win);
}
