/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:11:03 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/19 12:15:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx_hook.h"

static int	_loop_function(void)
{
	t_glx	*glx;

	glx = get_glx();
	glx->_->update_count = (glx->_->update_count + 1) % SIZE_MAX;
	if (glx->_->update_count % glx->_->update_lim == 0)
	{
		glx->frame_count = (glx->frame_count + 1) % SIZE_MAX;
		glx->user->update(glx->user->param);
		glx->user->draw(glx->user->param);
		_glx_key_just_state_init(glx);
	}
	return (0);
}

/**
 * @brief
 *
 * @param update	: 更新用の関数ポインタ
 * @param draw		: 描画用の関数ポインタ
 */
void	glx_hook(int (*update)(void *), int (*draw)(void *),
		int (*clean)(void *))
{
	t_glx	*glx;

	glx = get_glx();
	glx->user->update = update;
	glx->user->draw = draw;
	glx->user->clean = clean;
	mlx_loop_hook(glx->mlx, _loop_function, NULL);
	mlx_hook(glx->win, 2, (1L << 0), _glx_key_pressed, glx);
	mlx_hook(glx->win, 3, (1L << 1), _glx_key_released, glx);
	mlx_hook(glx->win, 17, (1L << 0), _glx_win_exit, glx);
}
