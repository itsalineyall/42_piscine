/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvieira <alvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:33:33 by alvieira          #+#    #+#             */
/*   Updated: 2023/02/19 00:00:55 by alvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_convert(char *str)
{
	int	i;
	int j;

	i = 1;
	j = 2;
	while (str[i] != '\0')
	{
		str[i] = str[j];
		i++;
		j = j + 2;
	}
	str[i] = '\0';

}

int	main(void)
{
	char	string1[] = "Hzeclslpo";

	ft_convert(string1);
	printf("%s", string1);
	return (0);
}