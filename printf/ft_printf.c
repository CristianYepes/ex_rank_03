/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:30:40 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/30 01:54:06 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putstr(const char *s1, int *count)
{
	int	i;

	i = 0;
	if (!s1)
	{
		s1 = "(null)";
	}
	while (s1[i])
	{
		write(1, &s1[i], 1);
		i++;
		(*count)++;
	}
}

void	ft_putnbr(int n, int *count)
{
	char	c;

	if (n == -2147483648) //es el INT_MIN 2^31
	{
		ft_putstr("-2147483648", count); //NO con write, SI con ft_putstr
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}

void	ft_puthex(unsigned int nb, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_puthex(nb / 16, count);
	write(1, &hex[nb % 16], 1); //CUIDADO
	(*count)++;
}

int	ft_printf(const char *format, ... )
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 's')
			{
				ft_putstr(va_arg(args, char *), &count);
			}
			else if (format[i] == 'd')
			{
				ft_putnbr(va_arg(args, int), &count);
			}
			else if (format[i] == 'x')
			{
				ft_puthex(va_arg(args, unsigned int), &count); //unsigned int
			}
			else
			{
				write(1, &format[i], 1);
				count++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

