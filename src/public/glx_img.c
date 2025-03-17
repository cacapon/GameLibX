/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:48:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 14:03:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx_img.h"

/**
 * @brief 横幅w, 高さhのpathの画像を登録します。
 * 
 * @param self 
 * @param path 
 * @param w 
 * @param h
 * @note この関数で登録できる画像はxpm形式のみです。 
 */
void	glx_load_img(t_glx *self, char *path, int w, int h)
{
	self->imgs[self->imgc] = mlx_xpm_file_to_image(self->mlx, path, &w, &h);
	if (!self->imgs[self->imgc])
		self->_->error(self, "glx_load_img: Failed to load image.");
	self->imgc++;
}

/**
 * @brief 登録済みの画像をposの位置に配置します。
 * 
 * @param self 
 * @param img_i
 * @param pos 
 */
void	glx_put_img(t_glx *self, int img_i, t_pos pos)
{
	static int	(*put_img)(void *, void *, void *, int,
			int) = mlx_put_image_to_window;

	put_img(self->mlx, self->win, self->imgs[img_i], pos.x, pos.y);
}
