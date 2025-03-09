/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:46:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/09 13:55:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_glx	*glx_init(void)
{
	t_glx	*glx;

	glx = ft_calloc(1, sizeof(t_glx));
	glx->mlx = mlx_init();
	glx->free = glx_free;
	return (glx);
}

void	glx_free(t_glx *self)
{
	free(self->mlx);
	free(self);
}
