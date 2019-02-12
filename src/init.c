#include "fractol.h"

void	ft_init_mand(t_s *s)
{
	s->fract = 0;
	s->left = -2.1;
	s->right = 0.6;
	s->high = -1.2;
	s->low = 1.2;
	s->itermax = 250;
}

void	ft_init_julia(t_s *s, int julia)
{
	s->fract = 1;
	s->itermax = 250;
	s->julia = julia;
	s->left = -1;
	s->right = 1;
	s->high = -1.2;
	s->low = 1.2;
	if (s->julia == 2)
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
		s->itermax = 250;
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

int		ft_init_image_menu(t_s *s, void *ptr, int sizex, int sizey)
{
	int size;
	int	bpp;
	int endian;
	t_link *link;

	link = (t_link *)ptr;
	size = sizex;
	bpp = 4;
	endian = 0;
	link->img = mlx_new_image(s->m_ptr, sizex, sizey);
	link->s_img = (unsigned char*)(mlx_get_data_addr(link->img, &(bpp), &(size),
	&(endian)));
	return (0);
}
