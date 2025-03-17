/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_key_input_pub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:52:07 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 12:54:39 by ttsubo           ###   ########.fr       */
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
int	glx_btnp(t_glx *self, int keycode)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (false);
	if (!self->key_just_state[keycode])
		return (false);
	return (true);
}
