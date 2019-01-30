#include "fractol.h"

void	ft_lightup_pixel(t_s *s, int x, int y, int color)
{
	int new_x;

	if (x < XWIN && y < YWIN && x > 0 && y > 0)
	{
		new_x = x * 4 + ((XWIN * 4) * y);
		s->s_img[new_x] = 0;
		s->s_img[new_x + 1] = 0;
		s->s_img[new_x + 2] = color;
		s->s_img[new_x + 3] = 0;
	}
}

int		ft_init_image(t_s *s, int sizex, int sizey)
{
	int size;
	int	bpp;
	int endian;

	size = sizex;
	bpp = 4;
	endian = 0;
	s->img = mlx_new_image(s->m_ptr, sizex, sizey);
	s->s_img = (unsigned char*)(mlx_get_data_addr(s->img, &(bpp), &(size),
	&(endian)));
	return (0);
}
