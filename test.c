#include "glx.h"
#include <stdio.h>

int	draw(void *param)
{
	t_glx	*glx;
	char	flm_c[20];
	char	up_c[20];

	glx = get_glx();
	glx->cls();
	sprintf(flm_c, "%zu", glx->frame_count);
	sprintf(up_c, "%zu", glx->_->update_count);
	glx->text("hello glx!", (t_pos){16, 16}, glx->frame_count % 16);
	glx->text(flm_c, (t_pos){16, 32}, GLX_COLOR_WHITE);
	glx->text(up_c, (t_pos){16, 48}, GLX_COLOR_WHITE);
	if (glx->btn(XK_a))
		glx->put_img(0, (t_pos){0, 0});
	return (0);
}

int	update(void *param)
{
	t_glx	*glx;

	glx = get_glx();
	if (glx->btnp(XK_q))
		glx->quit(EXIT_SUCCESS);
	return (0);
}

int	main(void)
{
	t_glx *glx;

	glx = glx_init("test", 500, 500, 500);
	glx->load_img("./plane.xpm", 16, 16);
	glx->run(update, draw);
}