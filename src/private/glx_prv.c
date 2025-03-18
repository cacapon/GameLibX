/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_prv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:37:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/18 14:01:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

/**
 * @brief 文字列mesを出力し、ゲームを終了します。
 * 
 * @param self 
 * @param mes 
 */
void	_glx_error(char *mes)
{
	t_glx	*glx;

	glx = get_glx();
	ft_putstr_fd(mes, STDERR_FILENO);
	glx->quit(EXIT_FAILURE);
}
