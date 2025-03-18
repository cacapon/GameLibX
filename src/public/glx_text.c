/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:48:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/18 13:43:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx_text.h"

/**
 * @brief 文字列textを位置posにcolorの色で出力します。
 *
 * @param str
 * @param pos
 * @param color
 */
void	glx_text(char *text, t_pos pos, t_glx_color_i color)
{
	t_glx	*glx;
	void	*mlx;
	void	*win;

	glx = get_glx();
	mlx = glx->mlx;
	win = glx->win;
	mlx_string_put(mlx, win, pos.x, pos.y, glx_get_color(color), text);
}
