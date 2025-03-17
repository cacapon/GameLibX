/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:09:55 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 13:51:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_STRUCT_H
# define GLX_STRUCT_H

# include "glx_define.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct s_glx	t_glx;

typedef struct s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct s_glx_prv
{
	size_t		update_count;
	
	void		(*error)(t_glx *, char *);
}				t_glx_prv;

typedef struct s_glx
{
	t_glx_prv	*_;
	size_t		frame_count;
	void		*mlx;
	void		*win;
	void		*imgs[MAX_IMG];
	int			imgc;
	bool		key_state[KEY_MAX];
	bool		key_just_state[KEY_MAX];
	int			(*btnp)(t_glx *, int);
	int			(*update)(t_glx *);
	int			(*draw)(t_glx *);
	void		(*load_img)(t_glx *, char *, int, int);
	void		(*put_img)(t_glx *, int, t_pos);
	void		(*put_str)(t_glx *, char *, t_pos, t_glx_color_i);
	void		(*run)(t_glx *, int (*)(t_glx *), int (*)(t_glx *));
	void		(*quit)(t_glx *, int);
}				t_glx;

#endif