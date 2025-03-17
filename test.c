#include "glx.h"
#include <stdio.h>

int	draw(t_glx *self)
{
	char	flm_c[20];
	char	up_c[20];

	self->cls(self);
	sprintf(flm_c, "%zu", self->frame_count);
	sprintf(up_c, "%zu", self->_->update_count);
	self->put_str(self, "hello glx!", (t_pos){16, 16}, self->frame_count % 16);
	self->put_str(self, flm_c, (t_pos){16, 32}, GLX_COLOR_WHITE);
	self->put_str(self, up_c, (t_pos){16, 48}, GLX_COLOR_WHITE);
	if (self->btnp(self, XK_a))
		self->put_img(self, 0, (t_pos){0, 0});
	return (0);
}

int	update(t_glx *self)
{
	if (self->btnp(self, XK_q))
		self->quit(self, 0);
	return (0);
}

int	main(void)
{
	t_glx *glx;

	glx = glx_init("test", 500, 500, 50000);
	glx->load_img(glx, "./plane.xpm", 16, 16);
	glx->run(glx, update, draw);
}