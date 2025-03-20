/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_key_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:52:07 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/18 13:51:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

/**
 * @brief 指定したkeyが丁度押されたかチェックします。
 * 
 * @param self 
 * @param keycode: X11ベースのキーコード 
 * @return int: 丁度押された場合1を返します。それ以外は0。
 */
int	glx_btnp(int keycode)
{
	t_glx	*glx;

	glx = get_glx();
	if (keycode < 0 || keycode > KEY_MAX)
		return (false);
	if (!glx->key_just_state[keycode])
		return (false);
	return (true);
}

/**
 * @brief 指定したキーが押されているかチェックします。
 * 
 * @param keycode 
 * @return int 押されている場合は1を返します。それ以外は0。
 */
int	glx_btn(int keycode)
{
	t_glx	*glx;

	glx = get_glx();
	if (keycode < 0 || keycode > KEY_MAX)
		return (false);
	return (glx->key_state[keycode]);
}
