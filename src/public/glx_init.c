/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:59:56 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/21 01:41:41 by ttsubo           ###   ########.fr       */
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

static void	_set_glx_property(t_glx *glx)
{
	glx->frame_count = 0;
	glx->imgc = 0;
	_glx_key_state_init(glx);
	_glx_key_just_state_init(glx);
}

static void	_set_glx_method(t_glx *glx)
{
	glx->run = glx_run;
	glx->hook = glx_hook;
	glx->load_img = glx_load_img;
	glx->put_img = glx_put_img;
	glx->text = glx_text;
	glx->quit = glx_quit;
	glx->btn = glx_btn;
	glx->btnp = glx_btnp;
	glx->cls = glx_cls;
}

static void	_glx_allocate_failed(char *target)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(target, STDERR_FILENO);
	ft_putstr_fd(": allocate failed.\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
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
	if (!glx)
		_glx_allocate_failed("glx");
	glx->user = ft_calloc(1, sizeof(t_glx_user));
	glx->_ = _glx_init_private(update_lim);
	if (!glx->user || !glx->_)
		_glx_allocate_failed("glx->user or glx->_");
	glx->mlx = mlx_init();
	if (!glx->mlx)
		_glx_allocate_failed("glx->mlx");
	glx->win = mlx_new_window(glx->mlx, win_w, win_h, title);
	if (!glx->win)
		_glx_allocate_failed("glx->win");
	_set_glx_property(glx);
	_set_glx_method(glx);
	set_glx(glx);
	return (glx);
}
