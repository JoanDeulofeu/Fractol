#include "fractol.h"

void	ft_init_frac(t_s *s)
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
	s->img_x = XWIN;
	s->img_y = YWIN;
	if (s->init == 0)
	{
		if (s->fract == 0)
		{
			s->left = -2.1;
			s->right = 0.6;
			s->high = -1.2;
			s->low = 1.2;
		}
		if (s->fract == 1)
		{
			s->left = -1;
			s->right = 1;
			s->high = -1.2;
			s->low = 1.2;
		}
		s->zoomx = (s->img_x / (s->right - s->left));
		s->zoomy = (s->img_y / (s->low - s->high));
	}
	s->init = 1;
}

void	ft_mandelbrot(t_s *s)
{
	ft_init_frac(s);
	while (s->pxl < XWIN * YWIN)
	{
		s->x = s->pxl <= XWIN ? s->pxl : s->pxl % XWIN;
		s->y = s->pxl / XWIN;
		s->cr = s->x / s->zoomx + s->left;
		s->ci = s->y / s->zoomy + s->high;
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

void	ft_julia(t_s *s)
{
	ft_init_frac(s);
	while (s->pxl < XWIN * YWIN)
	{
		s->x = s->pxl <= XWIN ? s->pxl : s->pxl % XWIN;
		s->y = s->pxl / XWIN;
		s->zr = s->x / s->zoomx + s->left;
		s->zi = s->y / s->zoomy + s->high;
		while (s->zr * s->zr + s->zi * s->zi < 4 && s->i < s->itermax)
		{
			s->tmp = s->zr;
			s->zr = s->zr * s->zr - s->zi * s->zi + 0.285;
			s->zi = 2 * s->zi * s->tmp + 0.01;
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

void	ft_fractales(t_s *s)
{
	if (s->fract == 0)
		ft_mandelbrot(s);
	else if (s->fract == 1)
		ft_julia(s);
}
