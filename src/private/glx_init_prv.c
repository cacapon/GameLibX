/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_init_prv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:09:47 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/21 02:12:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

t_glx_prv	*_glx_init_private(size_t update_lim)
{
	t_glx_prv	*prv;

	prv = ft_calloc(1, sizeof(t_glx_prv));
	if (!prv)
		return (NULL);
	prv->update_count = 0;
	prv->update_lim = update_lim;
	prv->error = _glx_error;
	return (prv);
}
