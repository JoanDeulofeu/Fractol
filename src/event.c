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
	mlx_destroy_image(s->m_ptr, s->img);
	ft_init_image(s, XWIN, YWIN);
	ft_fractale(s);
	return (0);
}

int		mouse_hook(int key, int i, int j, void *param)
{
	t_s *s;

	s = (t_s *)param;
	i = j;
	if (key == 2)
		ft_putnbr(s->itermax);
	exit(0);
	return (0);
}

int		ft_expose(void *param)
{
	t_s *s;

	s = (t_s *)param;
	exit(0);
}