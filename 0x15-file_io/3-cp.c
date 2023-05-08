#include "main.h"

/**
 * cp - copies src to desinations
 * @file_to: the destination file
 * @file_from: the source file
 *
 * Return: integer
 */
int cp(char *file_to, char *file_from)
{
	char *buffer[1024];
	int td, fd, fr, fw;
	int fc, ftc;

	fd = open(file_from, O_RDONLY);
	if (fd < 0)
		return (98);

	td = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (td < 0)
		return (99);

	fr = read(fd, buffer, 1024);
	if (fr < 0)
		return (98);

	while (fr > 0)
	{
		fw = write(td, buffer, fr);
		if (fw < 0)
			return (99);
		fr = read(fd, buffer, 1024);
		if (fr < 0)
			return (98);
	}

	fc = close(fd);
	if (fc < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fc);
		return (100);
	}
	ftc = close(td);
	if (ftc < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ftc);
		return (100);
	}
	return (0);
}

/**
 * main - copies the content of a file to another file
 *
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, 97-100 on failure
 */
int main(int ac, char **av)
{
    int fd_from, fd_to, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    if (ac != 3)
    {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
        exit(97);
    }

    /* open file_from for reading */
    fd_from = open(av[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
        exit(98);
    }

    /* truncate or create file_to for writing */
    fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
        exit(99);
    }

    /* read from file_from and write to file_to */
    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written != bytes_read)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
            exit(99);
        }
    }

    /* check for errors while reading */
    if (bytes_read == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
        exit(98);
    }

    /* close file descriptors */
    if (close(fd_from) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }
    if (close(fd_to) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return (0);
}
