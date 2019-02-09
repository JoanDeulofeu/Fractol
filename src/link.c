#include "fractol.h"

void	ft_affiche_link(t_s *s)
{
	mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->link1->img, 0, 0);
	mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->link2->img, XWIN - 160, 0);
	mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->link3->img, 0, YWIN - 160);
	mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->link4->img, XWIN - 160, YWIN - 160);
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

int		ft_do_link(t_s *s)
{
	if (!(s->link1 = (t_link *)malloc(sizeof(t_link))))
		return (0);
	s->dolink = 1;
	s->fract = 0;
	s->init = 0;
	s->itermax = 150;
	s->img_x = 160;
	s->img_y = 160;
	ft_init_image_menu(s, s->link1, s->img_x, s->img_y);
	ft_fractales(s);
	mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->link1->img, 0, 0);

	if (!(s->link2 = (t_link *)malloc(sizeof(t_link))))
		return (0);
	s->dolink = 2;
	s->fract = 1;
	s->movex = 0.4;
	s->movey = 0.2;
	// printf("s->img_x = %d\n", s->img_x);
	// printf("s->img_y = %d\n", s->img_y);
	s->init = 0;
	s->itermax = 150;
	// ft_putstr("image 1\n");
	ft_init_image_menu(s, s->link2, s->img_x, s->img_y);
	ft_fractales(s);
	mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->link2->img, XWIN - 160, 0);

	if (!(s->link3 = (t_link *)malloc(sizeof(t_link))))
		return (0);
	s->dolink = 3;
	s->fract = 1;
	s->movex = 0.26;
	s->movey = 0;
	s->init = 0;
	s->itermax = 150;
	ft_init_image_menu(s, s->link3, s->img_x, s->img_y);
	ft_fractales(s);
	mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->link3->img, 0, YWIN - 160);

	if (!(s->link4 = (t_link *)malloc(sizeof(t_link))))
		return (0);
	s->dolink = 4;
	s->fract = 3;
	s->init = 0;
	s->movex = 0.14;
	s->movey = 0;
	s->itermax = 150;
	ft_init_image_menu(s, s->link4, s->img_x, s->img_y);
	ft_fractales(s);
	mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->link4->img, XWIN - 160, YWIN - 160);
	s->dolink = 42;
	s->fract = 0;
	s->init = 0;
	s->itermax = 250;
	s->color = 0;
	return (0);
}

void	ft_lightup_menu(t_s *s, t_thr *thr, unsigned char *s_img)
{
	int new_x;

		if (thr->x <= s->img_x && thr->y <= s->img_y && thr->x >= 0 && thr->y >= 0)
		{
			new_x = thr->x * 4 + ((s->img_x * 4) * thr->y);
			s_img[new_x + 0] = ft_blue(s, thr);
			s_img[new_x + 1] = ft_green(s, thr);
			s_img[new_x + 2] = ft_red(s, thr);
			s_img[new_x + 3] = 0;
		}
}