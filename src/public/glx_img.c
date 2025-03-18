/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:48:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/18 13:53:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx_img.h"

/**
 * @brief 横幅w, 高さhのpathの画像を登録します。
 *
 * @param path
 * @param w
 * @param h
 * @note この関数で登録できる画像はxpm形式のみです。
 */
void	glx_load_img(char *path, int w, int h)
{
	t_glx	*glx;

	glx = get_glx();
	glx->imgs[glx->imgc] = mlx_xpm_file_to_image(glx->mlx, path, &w, &h);
	if (!glx->imgs[glx->imgc])
		glx->_->error(glx, "glx_load_img: Failed to load image.");
	glx->imgc++;
}

/**
 * @brief 登録済みの画像をposの位置に配置します。
 *
 * @param img_i
 * @param pos
 */
void	glx_put_img(int img_i, t_pos pos)
{
	t_glx	*glx;
	int		(*put_img)(void *, void *, void *, int, int);

	glx = get_glx();
	put_img = mlx_put_image_to_window;
	if (img_i >= glx->imgc)
		glx->_->error(glx, "glx_put_img: img_i is invalid number.");
	put_img(glx->mlx, glx->win, glx->imgs[img_i], pos.x, pos.y);
}
