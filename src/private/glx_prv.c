/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_prv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:37:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/19 12:01:02 by ttsubo           ###   ########.fr       */
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

int	_glx_win_exit(t_glx *glx)
{
	glx->quit(EXIT_SUCCESS);
	return (0);
}
