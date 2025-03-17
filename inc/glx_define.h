/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:39:03 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 12:47:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_DEFINE_H
# define GLX_DEFINE_H

/**
 * @brief GameLibXで使用する様々なenum,defineをこちらに定義しています。
 *
 */

/**
 * @brief 使用可能な色のインデックス
 * @note glx_get_color()にこちらを指定するとe_glx_colorを取得できます。
 *
 */
typedef enum e_glx_color_i
{
	GLX_COLOR_BLACK = 0,
	GLX_COLOR_INDIGO,
	GLX_COLOR_VIOLET,
	GLX_COLOR_TEAL,
	GLX_COLOR_MAROON,
	GLX_COLOR_COBALT_BLUE,
	GLX_COLOR_SKY_BLUE,
	GLX_COLOR_WHITE,
	GLX_COLOR_CRIMSON,
	GLX_COLOR_BRONZE,
	GLX_COLOR_SAFFRON,
	GLX_COLOR_MINT_GREEN,
	GLX_COLOR_CORN_FLOWER_BLUE,
	GLX_COLOR_GRAY,
	GLX_COLOR_SALMON_PINK,
	GLX_COLOR_PEACH
}	t_glx_color_i;

/**
 * @brief pyxelを参考に定義した16色の定義
 *
 */
typedef enum e_glx_color
{
	_GLX_COLOR_0 = 0x000000,
	_GLX_COLOR_1 = 0x2B335F,
	_GLX_COLOR_2 = 0x7E2072,
	_GLX_COLOR_3 = 0x19959C,
	_GLX_COLOR_4 = 0x8B4852,
	_GLX_COLOR_5 = 0x395C98,
	_GLX_COLOR_6 = 0xA9C1FF,
	_GLX_COLOR_7 = 0xEEEEEE,
	_GLX_COLOR_8 = 0xD4186C,
	_GLX_COLOR_9 = 0xD38441,
	_GLX_COLOR_A = 0xE9C35B,
	_GLX_COLOR_B = 0x70C6A9,
	_GLX_COLOR_C = 0x7696DE,
	_GLX_COLOR_D = 0xA3A3A3,
	_GLX_COLOR_E = 0xFF9798,
	_GLX_COLOR_F = 0xEDC7B0,
}	t_glx_color;

#endif