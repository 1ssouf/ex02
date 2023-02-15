/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:04:39 by ialousse          #+#    #+#             */
/*   Updated: 2023/02/15 19:04:50 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>


// int	ft_print_hex(unsigned int n)
// {
// 	int	len;

// 	len = 0;
// 	if (n > 15)
// 	{
// 		len += ft_print_hex(n / 16);
// 		len += ft_print_hex(n % 16);
// 	}
// 	else if (n > 9)
// 		len += ft_print_char(n + 87);
// 	else
// 		len += ft_print_char(n + 48);
// 	return (len);
// }

int	ft_print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int nb)
{
	long long int	n;
	int				len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += ft_print_char('-');
		n = -n;
	}
	if (n > 9)
	{
		len += ft_print_nbr(n / 10);
		len += ft_print_nbr(n % 10);
	}
	else
		len += ft_print_char(n + 48);
	return (len);
}

int	ft_sherch_args(char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 's')
		len += ft_print_str(va_args(arg, char *));
	if (format == 'd')
		len += ft_print_nbr(va_args(arg, int));
}

int	ft_print_hex(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 15)
	{
		len += ft_print_hex(nb / 16);
		len += ft_print_hex(nb % 16);
	}
	else if (nb > 9)
		ft_print_char(nb + 87);
	else
		ft_print_char(nb + 48);
	return (len);
}

// int	ft_cher_args(va_list args, const char format)
// {
// 	int	len;

// 	len = 0;
// 	if (format == 's')
// 		len += ft_print_str(va_arg(args, char *));
// 	else if (format == 'x')
// 		len += ft_print_hex(va_arg(args, unsigned int));
// 	else if (format == 'd')
// 		len += ft_print_nbr(va_arg(args, int));
// 	return (len);
// }

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_cher_args(args, format[i + 1]);
			i++;
		}
		else
			len += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int main()
{
	
	ft_printf("--iss%s et aussi %d||--\n", "ouf", 9700);
	return (0);
}
