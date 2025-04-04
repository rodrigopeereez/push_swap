/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:38:18 by vcodrean          #+#    #+#             */
/*   Updated: 2022/10/01 10:10:00 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a string, a character to find, and a size, and returns a 
 * pointer to the first instance of
 * the character in the string, or NULL if the character is not found
 * 
 * param void s The string to search
 * param int c The character to search for.
 * param size_t n the number of bytes to be searched
 * 
 * return The address of the first occurence of the character c in the string s.
 */
void	*ft_memchr(const void *s, int c, size_t n). //Se recibe una cadena, un carácter para encontrar y el tamaño del buffer
{
	size_t			i;
	unsigned char	*str;
	unsigned char	to_find;

	i = 0;
	str = (unsigned char *)s;
	to_find = (unsigned char)c;
	while (i < n) 				//mientas i menor	que el tamaño del buffer. 
	{
		if (str[i] == to_find) 		//si recorriendo str[i] encuentro la coincidencia que busco
			return (&str[i]); 	//devuelvo la dirrecion de la posicion de la coincidencia 
		i++; 				//contador para poder recorrer el str hasta que se encuentre la coincidencia que busco
	}
	return (NULL); 				//si no hay una coincidencia devuelve NULL
}
