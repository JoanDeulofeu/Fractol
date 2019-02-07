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
	thr6->pxl = (YWIN / 8) * 5 * XWIN;
	while (i++ < (YWIN / 8) * XWIN) //130 pour 1040
	{
		ft_resetmand(s, thr6);
		thr6 = ft_calcul(s, thr6);
		ft_lightup_pixel(s, thr6);
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
	thr7->pxl = (YWIN / 8) * 6 * XWIN;
	while (i++ < (YWIN / 8) * XWIN) //130 pour 1040
	{
		ft_resetmand(s, thr7);
		thr7 = ft_calcul(s, thr7);
		// printf("[i %d]x=%f, y=%f, i=%d\n", i, thr7->x, thr7->y, thr7->i);
		ft_lightup_pixel(s, thr7);
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
	thr8->pxl = (YWIN / 8) * 7 * XWIN;
	while (i++ < (YWIN / 8) * XWIN) //130 pour 1040
	{
		ft_resetmand(s, thr8);
		thr8 = ft_calcul(s, thr8);
		ft_lightup_pixel(s, thr8);
	}
	free(thr8);
	pthread_exit(NULL);
}
