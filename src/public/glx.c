/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:46:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/18 13:19:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

static t_glx		*g_glx_ins = NULL;

t_glx	*get_glx(void)
{
	return (g_glx_ins);
}

static t_glx_prv	*_glx_init_private(size_t update_lim)
{
	t_glx_prv	*prv;

	prv = ft_calloc(1, sizeof(t_glx_prv));
	prv->update_count = 0;
	prv->update_lim = update_lim;
	prv->error = glx_error;
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
	glx->_ = _glx_init_private(update_lim);
	glx->frame_count = 0;
	glx->mlx = mlx_init();
	glx->win = mlx_new_window(glx->mlx, win_w, win_h, title);
	glx->imgc = 0;
	glx->run = glx_run;
	glx->load_img = glx_load_img;
	glx->put_img = glx_put_img;
	glx->put_str = glx_put_str;
	glx->quit = glx_quit;
	glx->btnp = glx_btnp;
	glx->cls = glx_cls;
	_glx_key_state_init(glx);
	_glx_key_just_state_init(glx);
	g_glx_ins = glx;
	return (glx);
}

/**
 * @brief glxを終了します。内部で確保したメモリを開放します。
 *
 * @param self
 * @param sts_code
 */
void	glx_quit(t_glx *self, int sts_code)
{
	mlx_do_key_autorepeaton(self->mlx);
	while (self->imgc)
	{
		self->imgc--;
		mlx_destroy_image(self->mlx, self->imgs[self->imgc]);
	}
	mlx_destroy_window(self->mlx, self->win);
	mlx_destroy_display(self->mlx);
	free(self);
	exit(sts_code);
}

static int	_loop_function(t_glx *self)
{
	self->_->update_count = (self->_->update_count + 1) % SIZE_MAX;
	if (self->_->update_count % self->_->update_lim == 0)
	{
		self->frame_count = (self->frame_count + 1) % SIZE_MAX;
		self->update(self);
		self->draw(self);
		_glx_key_just_state_init(self);
	}
	return (0);
}

/**
 * @brief glxを実行します。キー入力を受け付けながら、frame毎にupdate,drawを実行します。
 *
 * @param self
 * @param update : 更新用の関数ポインタ
 * @param draw : 描画用の関数ポインタ
 */
void	glx_run(int (*update)(void *), int (*draw)(void *))
{
	t_glx	*glx;

	glx = get_glx();
	mlx_do_key_autorepeatoff(glx->mlx);
	glx->update = update;
	glx->draw = draw;
	mlx_loop_hook(glx->mlx, _loop_function, glx);
	mlx_hook(glx->win, 2, (1L << 0), _glx_key_pressed, glx);
	mlx_hook(glx->win, 3, (1L << 1), _glx_key_released, glx);
	mlx_loop(glx->mlx);
}
