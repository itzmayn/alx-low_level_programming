#include "main.h"

/**
 * read_textfile - reads text from a file and prints it to POSIX
 * @filename: name of the file to read (char *)
 * @letters: number of letters to read (size_t)
 *
 * Return: number of bytes printed, or 0 if there was an error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd, rd, wd;
    char *buff;

    /* Allocate memory for buffer */
    buff = malloc(sizeof(char) * letters);
    if (buff == NULL) {
        /* Handle malloc error */
        return (0);
    }

    /* Check for null filename */
    if (filename == NULL) {
        /* Free memory and return 0 */
        free(buff);
        return (0);
    }

    /* Open file */
    fd = open(filename, O_RDWR);
    if (fd == -1) {
        /* Handle open error */
        free(buff);
        return (0);
    }

    /* Read from file */
    rd = read(fd, buff, letters);
    if (rd == -1) {
        /* Handle read error */
        close(fd);
        free(buff);
        return (0);
    }

    /* Write to STDOUT */
    wd = write(STDOUT_FILENO, buff, rd);
    if (wd == -1 || wd != rd) {
        /* Handle write error */
        close(fd);
        free(buff);
        return (0);
    }

    /* Clean up and return bytes written */
    close(fd);
    free(buff);
    return (wd);
}
