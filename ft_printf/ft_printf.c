/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:58:30 by mouad             #+#    #+#             */
/*   Updated: 2024/11/26 15:05:49 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char    *format, ...)
{
    va_list args;
    int printed_char;
    const char  *ptr;

    printed_char = 0;
    ptr = format;

    va_start(args,format);
    while(*ptr)
    {
        if(*ptr == '%')
        {
            ptr++;
            if(*ptr == 'd')
            {
                printed_char += ft_print_d(va_arg(args,int));
            }
            else if(*ptr == 's')
            {
                printed_char += ft_putstr(va_arg(args,char *));
            }
            else if(*ptr == 'c')
            {
                printed_char += ft_putchar(va_arg(args,int));
            }
            else if(*ptr == 'u')
            {
                printed_char += ft_print_u(va_arg(args,unsigned int));
            }
            else if(*ptr == 'i')
            {
                printed_char += ft_print_i(va_arg(args,int));
            }
            else if(*ptr == 'x')
            {
                printed_char += ft_puthexalow(va_arg(args,unsigned int));
            }
            else if(*ptr == 'p')
            {
                printed_char += ft_print_hex(va_arg(args,unsigned int));
            }
        }
        else
        {
            printed_char += ft_putchar(*ptr);
        }
        ptr++;
    } 
    va_end(args);
    return(printed_char);  
}

int main(void)
{
    ft_printf("my name is %s and i have %d years old and i have %c dirham\n","mouad",20,'d');
}
