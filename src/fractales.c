#include "fractol.h"

void	ft_init_frac(t_s *s)
{
	if (s->dolink == 0 || s->dolink > 4)
	{
		s->img_x = XWIN;
		s->img_y = YWIN;
	}
	else
	{
		s->img_x = 160;
		s->img_y = 160;
	}
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
		if (s->fract == 3)
		{
			if (s->dolink != 4)
			{
				s->left = -1.013;
				s->right = 0.286;
				s->high = -1.735;
				s->low = 0.465;
				s->zoomx = 512.4;
				s->zoomy = 302.5;
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
		s->randx = 0;
		s->randy = 0;
	}
	s->init = 1;
}

void	ft_resetmand(t_s *s, t_thr *thr)
{
	thr->i = 0;
	thr->x = thr->pxl < s->img_x ? thr->pxl : thr->pxl % s->img_x;
	thr->y = thr->pxl / s->img_x;
	thr->zr = 0;
	thr->zi = 0;
	thr->cr = thr->x / s->zoomx + s->left;
	thr->ci = thr->y / s->zoomy + s->high;
	if (s->fract == 1 || s->fract == 3) // Julia
	{
		ft_swap_double(&thr->zr, &thr->cr);
		ft_swap_double(&thr->zi, &thr->ci);
		thr->cr = s->movex;
		thr->ci = s->movey;
	}
	if (s->fract == 2) // Fougere
	{
		thr->zr = 50;
		thr->zi = 0;
	}
	thr->pxl++;
}

int		ft_fractales(t_s *s)
{
	ft_init_frac(s);
	pthread_t thread[8];
	int i;

	i = 0;
	if (pthread_create(&thread[i++], NULL, ft_thread_1, (void *) s) == -1)
		ft_exit(0);
	if (pthread_create(&thread[i++], NULL, ft_thread_2, (void *) s) == -1)
		ft_exit(0);
	if (pthread_create(&thread[i++], NULL, ft_thread_3, (void *) s) == -1)
		ft_exit(0);
	if (pthread_create(&thread[i++], NULL, ft_thread_4, (void *) s) == -1)
		ft_exit(0);
	if (pthread_create(&thread[i++], NULL, ft_thread_5, (void *) s) == -1)
		ft_exit(0);
	if (pthread_create(&thread[i++], NULL, ft_thread_6, (void *) s) == -1)
		ft_exit(0);
	if (pthread_create(&thread[i++], NULL, ft_thread_7, (void *) s) == -1)
		ft_exit(0);
	if (pthread_create(&thread[i++], NULL, ft_thread_8, (void *) s) == -1)
		ft_exit(0);
	i = 0;
	while (i < 8)
	{
		if (pthread_join(thread[i++], NULL) == -1)
			ft_exit(1);
	}
	if (s->dolink == 0 || s->dolink == 42)
		mlx_put_image_to_window(s->m_ptr, s->w_ptr, s->img, 0, 0);
	if (s->dolink == 0)
		ft_do_link(s);
	if (s->dolink == 42)
		ft_affiche_menu(s);
	return (0);
}
