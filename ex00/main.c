/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:29:03 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/24 20:54:08 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

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
	int	fd;

	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 21);
		return (-1);
	}
	if (argc < 2)
	{
		write(2, "File name missing.\n", 20);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 19);
		return (-1);
	}
	write_file(fd);
	close(fd);
}
