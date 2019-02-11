#include "fractol.h"

void	ft_init_mand(t_s *s)
{
	s->fract = 0;
	s->left = -2.1;
	s->right = 0.6;
	s->high = -1.2;
	s->low = 1.2;
}

void	ft_init_julia(t_s *s)
{
	s->fract = 1;
	s->left = -1;
	s->right = 1;
	s->high = -1.2;
	s->low = 1.2;
	if (s->dolink != 42)
	{
		if (s->dolink == 3)
		{
			s->movex = 0.26;
			s->movey = 0;
		}
		else
		{
			s->movex = 0.4;
			s->movey = 0.2;
		}
	}
}

void	ft_init_joan(t_s *s)
{
	s->fract = 3;
	if (s->dolink != 4)
	{
		s->left = -1.013;
		s->right = 0.286;
		s->high = -1.735;
		s->low = 0.465;
		s->zoomx = 512.4;
		s->zoomy = 302.5;
		s->itermax = 200;
		s->movex = 0.14;
		s->movey = 0;
	}
	else
	{
		s->left = -1.2;
		s->right = 0.22;
		s->high = -2.0;
		s->low = 0.1;
		s->zoomx = 68;
		s->zoomy = 40;
	}
}
