#include "glx.h"
#include <stdio.h>

int	draw(void *param)
{
	t_glx	*glx;
	char	flm_c[20];
	char	up_c[20];

	glx = get_glx();
	glx->cls(glx);
	sprintf(flm_c, "%zu", glx->frame_count);
	sprintf(up_c, "%zu", glx->_->update_count);
	glx->put_str(glx, "hello glx!", (t_pos){16, 16}, glx->frame_count % 16);
	glx->put_str(glx, flm_c, (t_pos){16, 32}, GLX_COLOR_WHITE);
	glx->put_str(glx, up_c, (t_pos){16, 48}, GLX_COLOR_WHITE);
	if (glx->btnp(glx, XK_a))
		glx->put_img(glx, 0, (t_pos){0, 0});
	return (0);
}

int	update(void *param)
{
	t_glx	*glx;

	glx = get_glx();
	if (glx->btnp(glx, XK_q))
		glx->quit(glx, 0);
	return (0);
}

int	main(void)
{
	t_glx *glx;

	glx = glx_init("test", 500, 500, 500);
	glx->load_img(glx, "./plane.xpm", 16, 16);
	glx->run(update, draw);
}