/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:43:07 by jmeulema          #+#    #+#             */
/*   Updated: 2023/02/15 15:30:02 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_repeat(char *str, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if ((av[1][i] == av[2][j]) && check_repeat(av[1], av[1][i], i))
				{
					write (1, &av[1][i], 1);
					break ;
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
