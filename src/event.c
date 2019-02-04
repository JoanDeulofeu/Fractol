#include "fractol.h"

int		key_hook(int key, void *param)
{
	t_s *s;

	s = (t_s *)param;
	if (key == 53)
		exit(0);
	if (key == 125)
		s->itermax -= 1;
	if (key == 126)
		s->itermax += 1;
	if (key == 83)
	{
		s->fract = 0;
		s->init = 0;
	}
	if (key == 84)
	{
		s->fract = 1;
		s->init = 0;
	}
	mlx_destroy_image(s->m_ptr, s->img);
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s);
	return (0);
}

int		mouse_hook(int key, int x, int y, void *param)
{
	t_s *s;

	s = (t_s *)param;
	(void)y;
	if (key == 1)
		s->move = s->move == 1 ? 0 : 1;
	if (key == 2)
	{
		ft_putnbr(s->itermax);
		ft_putstr("     ");
		ft_putnbr(s->zoomx);
		ft_putstr("     ");
		ft_putnbr(s->move);
		exit(0);
	}
	if (key == 4)
		ft_zoom(s, x, y, 1);
	if (key == 5)
		ft_zoom(s, x, y, 0);
	mlx_destroy_image(s->m_ptr, s->img);
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_s *s;

	s = (t_s *)param;
	if (s->move == 1)
	{
		if (s->savex < x)
			s->zr += 0.02;
		if (s->savex < y)
			s->zi += 0.02;
		if (s->savex > x)
			s->zr -= 0.02;
		if (s->savex > y)
			s->zi -= 0.02;
		s->savex = x;
		s->savey = y;
	}
	mlx_destroy_image(s->m_ptr, s->img);
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s);
	return (0);
}

int		ft_expose(void *param)
{
	t_s *s;

	s = (t_s *)param;
	exit(0);
}
