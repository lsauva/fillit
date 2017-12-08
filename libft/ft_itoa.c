/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsauvage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:06:20 by lsauvage          #+#    #+#             */
/*   Updated: 2017/11/21 14:59:27 by lsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION : Alloue (avec malloc(3)) et retourne une chaine de caractères
** “fraiche” terminée par un ’\0’ représentant l’entier n passé en paramètre.
** Les nombres négatifs doivent être gérés. Si l’allocation échoue,
** la fonction renvoie NULL.
**
** PARAM #1 : L’entier à convertir en une chaine de caractères.
**
** RETOUR : La chaine de caractères représentant l’entier passé en paramètre.
*/

char	*ft_itoa(int n)
{
	int		q;
	int		len;
	char	*toa;

	len = ft_int_len(n);
	toa = (char *)malloc(sizeof(char) * (len + 1));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 || !toa)
		return (ft_strdup("0"));
	if (n < 0)
	{
		toa[0] = '-';
		n = -n;
	}
	toa[len] = '\0';
	while (n > 0)
	{
		toa[len - 1] = n % 10 + '0';
		q = n % 10;
		n = n - q;
		n = n / 10;
		len--;
	}
	return (toa);
}
