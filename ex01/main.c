/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:29:03 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/24 21:02:50 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}


void	write_file(int fd)
{
	int		end;
	char	c;

	end = 1;
	while (end)
	{
		end = read(fd, &c, 1);
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	char	str[100];
	int		fd;
	int		i;
	int		end;
	int		bufferlength;

	end = 1;
	if (argc == 1)
	{
		while (end)
		{
			end = read(1, str, 1);
		}
		bufferlength = ft_strlen(str);
		write(1, str, bufferlength);
		return (0);
	}
	i = 0;
	while (i < argc - 1)
	{
		fd = open(argv[i + 1], O_RDONLY);
		if (fd == -1)
		{
			bufferlength = ft_strlen(strerror(errno));
			write(2, strerror(errno), bufferlength);
			return (-1);
		}
		write_file(fd);
		close(fd);
		i++;
	}
}
