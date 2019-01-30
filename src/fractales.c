#include "fractol.h"

void	ft_init_fract(t_s *s)
{
		s->zr = 0;
		s->zi = 0;
		s->i = 0;
		s->pxl = 0;
		s->x = 0;
		s->y = 0;
		s->tmp = 0;
		s->cr = 0;
		s->ci = 0;
		s->x1 = -2.1;
		s->x2 = 0.6;
		s->y1 = -1.2;
		s->y2 = 1.2;
		s->img_x = XWIN;
		s->img_y = YWIN;
		s->zoomx = s->img_x / (s->x2 - s->x1);
		s->zoomy = s->img_y / (s->y2 - s->y1);
}

void	ft_fractale(t_s *s)
{
	ft_init_fract(s);
	while (s->pxl < XWIN * YWIN)
	{
		s->x = s->pxl <= XWIN ? s->pxl : s->pxl % XWIN;
		s->y = s->pxl / XWIN;
		s->cr = s->x / s->zoomx + s->x1;
		s->ci = s->y / s->zoomy + s->y1;
		while (s->zr * s->zr + s->zi * s->zi < 4 && s->i < s->itermax)
		{
			s->tmp = s->zr;
			s->zr = s->zr * s->zr - s->zi * s->zi + s->cr;
			s->zi = 2 * s->zi * s->tmp + s->ci;
			s->i++;
		}
		if (s->i == s->itermax)
			ft_lightup_pixel(s, s->x, s->y, 255);
		else
			ft_lightup_pixel(s, s->x, s->y, s->i * 255 / s->itermax);
		s->i = 0;
		s->zr = 0;
		s->zi = 0;
		s->pxl++;
	}
	mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->img, 0, 0);
}
