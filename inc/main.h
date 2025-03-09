/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:47:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/09 13:14:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include "libft.h"

typedef struct s_glx t_glx;

typedef struct s_glx
{
	void	*mlx;
	void	(*free)(t_glx *self);
}			t_glx;

t_glx		*glx_init(void);
void		glx_free(t_glx *self);

#endif