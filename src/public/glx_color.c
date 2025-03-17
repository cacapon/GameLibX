/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:14:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 12:49:49 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx_color.h"

/**
 * @brief GLX_COLORから始まるインデックスを指定することで、その色を取得できます。
 * 
 * @param color 
 * @return uint32_t 
 * @note 0-16以外のインデックスが指定された場合、黒(0x0000)が返されます。
 */
uint32_t	glx_get_color(t_glx_color_i color)
{
	const uint32_t	glx_colors[16] = {
		_GLX_COLOR_0, _GLX_COLOR_1, _GLX_COLOR_2, _GLX_COLOR_3,
		_GLX_COLOR_4, _GLX_COLOR_5, _GLX_COLOR_6, _GLX_COLOR_7,
		_GLX_COLOR_8, _GLX_COLOR_9, _GLX_COLOR_A, _GLX_COLOR_B,
		_GLX_COLOR_C, _GLX_COLOR_D, _GLX_COLOR_E, _GLX_COLOR_F
	};

	if (color < 0 || color > 15)
		return (_GLX_COLOR_0);
	return (glx_colors[color]);
}
