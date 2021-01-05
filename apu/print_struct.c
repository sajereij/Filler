#include "filler.h"

void	print_struct(t_d *d)
{
	ft_printf("{#FD}STRUCT:\n", d->fd);
	ft_printf("{#FD}%d pnb\n", d->fd, d->pnb);
	ft_printf("{#FD}%d my\n", d->fd, d->my);
	ft_printf("{#FD}%d mx\n", d->fd, d->mx);
	ft_printf("{#FD}%d py\n", d->fd, d->py);
	ft_printf("{#FD}%d px\n", d->fd, d->px);
	ft_printf("{#FD}%d lmx col\n", d->fd, d->lmxx);
	ft_printf("{#FD}%d lmx row\n", d->fd, d->lmxy);
	ft_printf("{#FD}%d lmo col\n", d->fd, d->lmox);
	ft_printf("{#FD}%d lmo row\n", d->fd, d->lmoy);
	ft_printf("{#FD}END OF STRUCT\n\n", d->fd);
}
