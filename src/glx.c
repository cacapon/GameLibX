/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:46:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/11 12:36:42 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

t_glx	*glx_init(char *title, int win_w, int win_h)
{
	t_glx	*glx;

	glx = ft_calloc(1, sizeof(t_glx));
	glx->mlx = mlx_init();
	glx->win = mlx_new_window(glx->mlx, win_w, win_h, title);
	glx->run = glx_run;
	glx->free = glx_free;
	return (glx);
}

void	glx_free(t_glx *self)
{
	free(self->mlx);
	free(self);
}

void	glx_run(t_glx *self)
{
	mlx_loop(self->mlx);
}
