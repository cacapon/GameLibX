/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_instance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:22:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/18 13:25:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx_instance.h"

static t_glx	*g_glx_ins = NULL;

t_glx	*get_glx(void)
{
	return (g_glx_ins);
}

void	set_glx(t_glx *glx)
{
	g_glx_ins = glx;
}
