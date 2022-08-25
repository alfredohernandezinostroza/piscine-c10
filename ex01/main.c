/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:29:03 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/25 13:32:16 by aantonio         ###   ########.fr       */
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
		if (!end)
			break ;
		write(1, &c, 1);
	}
}

void	print_files(int argc, char *argv[])
{
	int	bufferlength;
	int	fd;
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		fd = open(argv[i + 1], O_RDONLY);
		if (fd == -1)
		{
			bufferlength = ft_strlen(strerror(errno));
			write(2, argv[0], ft_strlen(argv[0]));
			write(2, ": ", 2);
			write(2, argv[i + 1], ft_strlen(argv[i + 1]));
			write(2, ": ", 2);
			write(2, strerror(errno), bufferlength);
			write(2, "\n", 1);
			i++;
			continue ;
		}
		write_file(fd);
		close(fd);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	str[3];
	int		end;

	end = 1;
	if (argc == 1)
	{
		while (end)
		{
			end = read(0, str, 1);
			if (*str == '\n' && !end)
				break ;
			write(1, str, 1);
		}
	}
	print_files(argc, argv);
	return (0);
}
