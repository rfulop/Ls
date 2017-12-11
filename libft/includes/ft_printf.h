/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 23:18:18 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/07 16:02:50 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

typedef	struct		s_opt
{
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				j;
	int				z;
	int				sharp;
	int				zero;
	int				less;
	int				plus;
	int				space;
	int				point;
	int				prec;
	int				width;
	int				length;
	int				len;
	int				isneg;
	int				check;
	int				unicode;
	char			*tmp;
	char			*res;
}					t_opt;

/*
** Init functions
*/
int					ft_printf(const char *fmt, ...);
void				ft_init_opt(t_opt *opt);
void				ft_init_ret(t_opt *opt);

/*
** Check flag functions
*/
int					ft_flag(t_opt *opt, char *fmt);
void				ft_f_option(t_opt *opt, char c);
int					ft_f_length(t_opt *opt, char *str);
int					ft_f_width(t_opt *opt, char *str);
int					ft_f_precison(t_opt *opt, char *str);
int					ft_conv_type(va_list ap, t_opt *opt, char c);

/*
** Unicode functions
*/
void				ft_c_unicode(va_list ap, t_opt *opt, char c, wchar_t x);
int					ft_count_byt(wchar_t a);
void				ft_s_unicode(va_list ap, t_opt *opt);
void				ft_concat_unicode_s(va_list ap, t_opt *opt, wchar_t *str,
					int len);

/*
** Width functions
*/
char				*ft_width(t_opt *opt, char *str, char c);
char				*ft_add_width(t_opt *opt, char *str, char c, int a);
char				*ft_less(t_opt *opt, char *str, char c);
char				*ft_put_0x(char *str, char c);

/*
** Precision functions
*/
char				*ft_prec(t_opt *opt, char *str, char c);
char				*ft_no_prec(t_opt *opt, char *str, char c);
char				*ft_put_zero_s(t_opt *opt, char *str, int a, int flag);
char				*ft_prec_s(t_opt *opt, char *str);
char				*ft_no_prec(t_opt *opt, char *str, char c);

/*
** Lenght functions
*/
short				ft_hd(va_list ap);
signed char			ft_hhd(va_list ap);
long int			ft_ld(va_list ap);
long long int		ft_lld(va_list ap);
uintmax_t			ft_j(va_list ap);
size_t				ft_z(va_list ap);
unsigned short		ft_h(va_list ap);
unsigned char		ft_hh(va_list ap);
unsigned long int	ft_l(va_list ap);
t_ulong				ft_ll(va_list ap);

/*
** Convertion functions
*/
void				ft_d(va_list ap, t_opt *opt, char c);
void				ft_s(va_list ap, t_opt *opt, char c);
void				ft_c(va_list ap, t_opt *opt, char c);
void				ft_x(va_list ap, t_opt *opt, char c);
void				ft_o(va_list ap, t_opt *opt, char c);
void				ft_u(va_list ap, t_opt *opt, char c);
void				ft_b(va_list ap, t_opt *opt);
void				ft_p(va_list ap, t_opt *opt);
void				ft_percent(t_opt *opt);

/*
** Print functions
*/
char				*ft_print_xou(t_opt *opt, t_ulong n, char c);
void				ft_print_d(t_opt *opt, long long int n);
void				ft_print_s(va_list ap, t_opt *opt);
void				ft_print_unicode(t_opt *opt, wchar_t a, int byt);
void				ft_print_unicode_bis(t_opt *opt, wchar_t a);
int					ft_print_nothing(t_opt *opt, char c);
void				ft_c_null(t_opt *opt, unsigned char a);

/*
** Debug functions
*/
void				ft_print_map(t_opt *map);

#endif
