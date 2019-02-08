#include "fractol.h"

void *ft_thread_6(void *arg)
{
	t_thr	*thr6;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr6 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	thr6->pxl = (s->img_y / 8) * 5 * s->img_x;
	while (i++ < (s->img_y / 8) * s->img_x) //130 pour 1040
	{
		ft_resetmand(s, thr6);
		if (s->fract != 2)
		{
			thr6 = ft_calcul(s, thr6);
			ft_lightup_pixel(s, thr6);
		}
		else
			ft_fougere(s, thr6);
	}
	free(thr6);
	pthread_exit(NULL);
}

void *ft_thread_7(void *arg)
{
	t_thr	*thr7;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr7 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	thr7->pxl = (s->img_y / 8) * 6 * s->img_x;
	while (i++ < (s->img_y / 8) * s->img_x) //130 pour 1040
	{
		ft_resetmand(s, thr7);
		if (s->fract != 2)
		{
			thr7 = ft_calcul(s, thr7);
			ft_lightup_pixel(s, thr7);
		}
		else
			ft_fougere(s, thr7);
	}
	free(thr7);
	pthread_exit(NULL);
}

void *ft_thread_8(void *arg)
{
	t_thr	*thr8;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr8 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	thr8->pxl = (s->img_y / 8) * 7 * s->img_x;
	while (i++ < (s->img_y / 8) * s->img_x) //130 pour 1040
	{
		ft_resetmand(s, thr8);
		if (s->fract != 2)
		{
			thr8 = ft_calcul(s, thr8);
			ft_lightup_pixel(s, thr8);
		}
		else
			ft_fougere(s, thr8);
	}
	free(thr8);
	pthread_exit(NULL);
}
