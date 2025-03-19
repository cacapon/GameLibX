/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:46:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/19 20:56:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

static t_glx_prv	*_glx_init_private(size_t update_lim)
{
	t_glx_prv	*prv;

	prv = ft_calloc(1, sizeof(t_glx_prv));
	if (!prv)
		return (NULL);
	prv->update_count = 0;
	prv->update_lim = update_lim;
	prv->error = _glx_error;
	return (prv);
}

/**
 * @brief glxを初期化します。
 *
 * @param title
 * @param win_w
 * @param win_h
 * @param update_lim
 * @return t_glx*
 */
t_glx	*glx_init(char *title, int win_w, int win_h, size_t update_lim)
{
	t_glx	*glx;

	glx = ft_calloc(1, sizeof(t_glx));	
	glx->user = ft_calloc(1, sizeof(t_glx_user));
	glx->_ = _glx_init_private(update_lim);
	if (!glx || !glx->user || glx->_)
		_glx_error("glx_init: memory allocation failed.");
	glx->frame_count = 0;
	glx->mlx = mlx_init();
	glx->win = mlx_new_window(glx->mlx, win_w, win_h, title);
	glx->imgc = 0;
	glx->run = glx_run;
	glx->hook = glx_hook;
	glx->load_img = glx_load_img;
	glx->put_img = glx_put_img;
	glx->text = glx_text;
	glx->quit = glx_quit;
	glx->btn = glx_btn;
	glx->btnp = glx_btnp;
	glx->cls = glx_cls;
	_glx_key_state_init(glx);
	_glx_key_just_state_init(glx);
	set_glx(glx);
	return (glx);
}

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
