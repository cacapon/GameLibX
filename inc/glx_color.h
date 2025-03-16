/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:39:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/16 19:12:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_COLOR_H
# define GLX_COLOR_H

# include <stdint.h>

typedef enum {
    COLOR_BLACK = 0,
    COLOR_INDIGO,
    COLOR_VIOLET,
    COLOR_TEAL,
    COLOR_MAROON,
    COLOR_COBALT_BLUE,
    COLOR_SKY_BLUE,
    COLOR_WHITE,
    COLOR_CRIMSON,
    COLOR_BRONZE,
    COLOR_SAFFRON,
    COLOR_MINT_GREEN,
    COLOR_CORN_FLOWER_BLUE,
    COLOR_GRAY,
    COLOR_SALMON_PINK,
    COLOR_PEACH
} t_glx_color_index; 

# define GLX_COLOR_0 0x000000
# define GLX_COLOR_1 0x2B335F
# define GLX_COLOR_2 0x7E2072
# define GLX_COLOR_3 0x19959C
# define GLX_COLOR_4 0x8B4852
# define GLX_COLOR_5 0x395C98
# define GLX_COLOR_6 0xA9C1FF
# define GLX_COLOR_7 0xEEEEEE
# define GLX_COLOR_8 0xD4186C
# define GLX_COLOR_9 0xD38441
# define GLX_COLOR_A 0xE9C35B
# define GLX_COLOR_B 0x70C6A9
# define GLX_COLOR_C 0x7696DE
# define GLX_COLOR_D 0xA3A3A3
# define GLX_COLOR_E 0xFF9798
# define GLX_COLOR_F 0xEDC7B0

uint32_t glx_get_color(t_glx_color_index color);

#endif