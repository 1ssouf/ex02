/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:18:49 by ialousse          #+#    #+#             */
/*   Updated: 2023/02/15 16:04:00 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_rep(char *str, char c, int n)
{
	int	i;

	i = 0;
	while (n > i)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void ft_srtjoin(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		ft_srtjoin(av[1], av[2]);
		while (av[1][i])
		{
			if (ft_check_rep(av[1], av[1][i], i))
				write (1, &av[1][i], 1);
			i++;	
		}
	}
	write (1, "\n", 1);
	return (0);
}