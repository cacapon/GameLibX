/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:46:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/21 01:15:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

/**
 * @brief glxを終了します。内部で確保したメモリを開放します。
 *
 * @param sts_code
 */
void	glx_quit(int sts_code)
{
	t_glx	*glx;

	glx = get_glx();
	mlx_do_key_autorepeaton(glx->mlx);
	while (glx->imgc)
	{
		glx->imgc--;
		mlx_destroy_image(glx->mlx, glx->imgs[glx->imgc]);
	}
	mlx_destroy_window(glx->mlx, glx->win);
	mlx_destroy_display(glx->mlx);
	glx->user->clean(glx->user->param);
	free(glx->mlx);
	free(glx->_);
	free(glx->user);
	free(glx);
	exit(sts_code);
}

/**
 * @brief glxを実行します。キー入力を受け付けながら、frame毎にupdate,drawを実行します。
 *
 * @param param		: 更新・描画用のパラメータ
 */
void	glx_run(void *param)
{
	t_glx	*glx;

	glx = get_glx();
	mlx_do_key_autorepeatoff(glx->mlx);
	glx->user->param = param;
	mlx_loop(glx->mlx);
}
