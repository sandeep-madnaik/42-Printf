/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 17:36:13 by lhurt             #+#    #+#             */
/*   Updated: 2017/05/01 17:38:10 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*call_len_lx(va_list ap, t_conv *obj)
{
	if (obj->len.hh)
		return (ft_usctoa_base(va_arg(ap, unsigned int), 16));
	else if (obj->len.h)
		return (ft_usitoa_base(va_arg(ap, unsigned int), 16));
	else if (obj->len.l)
		return (ft_ultoa_base(va_arg(ap, unsigned long int), 16));
	else if (obj->len.ll)
		return (ft_ulltoa_base(va_arg(ap, unsigned long long int), 16));
	else if (obj->len.j)
		return (ft_ujtoa_base(va_arg(ap, uintmax_t), 16));
	else if (obj->len.z)
		return (ft_ztoa_base(va_arg(ap, size_t), 16));
	else
		return (ft_utoa_base(va_arg(ap, unsigned int), 16));
}

int		printf_lx(va_list ap, t_conv *obj)
{
	char			*tmp;

	tmp = call_len_lx(ap, obj);
	if (obj->b_prec)
		tmp = modify_prec(obj, tmp);
	if (obj->flags.hash && tmp[0] != '0')
		tmp = ft_strjoin("0X", tmp);
	if (obj->width)
		tmp = modify_width(obj, tmp);
	obj->size += ft_strlen(tmp);
	obj->rtn = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (obj->size);
}
