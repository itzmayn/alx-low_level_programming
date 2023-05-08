#include "main.h"

/**
 * create_file - creates a file and writes to it
 * @filename: name of the file to be created (const char *)
 * @text_content: content to be written to the file (char *)
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd, len, w;

    if (filename == NULL) {
        return (-1);
    }

    /* Open file with read/write permissions, and create/truncate it if it doesn't exist */
    fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 00600);
    if (fd == -1) {
        return (-1);
    }

    /* If text_content is not NULL, calculate the length of the string and write it to the file */
    if (text_content != NULL) {
        for (len = 0; text_content[len] != '\0'; len++) {
            /* empty loop body */
        }

        /* Write the content to the file */
        w = write(fd, text_content, len);
    }

    /* Check if write was successful */
    if (w == -1) {
        close(fd);
        return (-1);
    }

    /* Close the file and return success */
    close(fd);
    return (1);
}
