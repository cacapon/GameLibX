/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:48:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 14:00:59 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx_str.h"

/**
 * @brief 文字列strを位置posにcolorの色で出力します。
 * 
 * @param self 
 * @param str 
 * @param pos 
 * @param color 
 */
void	glx_put_str(t_glx *self, char *str, t_pos pos, t_glx_color_i color)
{
	mlx_string_put(self->mlx, self->win, pos.x, pos.y, glx_get_color(color),
		str);
}
