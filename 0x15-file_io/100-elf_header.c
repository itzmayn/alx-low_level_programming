#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * print_error - print an error message and exit with error code 98
 * @msg: the error message to print
 */
void print_error(const char *msg);

/**
 * read_header - read the ELF header from a file
 * @fd: the file descriptor to read from
 * @header: a pointer to the Elf64_Ehdr struct to store the header data in
 */
void read_header(int fd, Elf64_Ehdr *header);

/**
 * print_header - print the contents of an ELF header
 * @header: a pointer to the Elf64_Ehdr struct to print
 */
void print_header(Elf64_Ehdr *header);

/**
 * main - entry point of the program
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the program arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
    int fd;
    Elf64_Ehdr header;

    /* Check for correct number of arguments */
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    /* Open the file */
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        print_error("Can't open file");
    }

    /* Read the header */
    read_header(fd, &header);

    /* Print the header */
    print_header(&header);

    /* Close the file */
    close(fd);

    return 0;
}

/**
 * print_error - print an error message and exit with error code 98
 * @msg: the error message to print
 */
void print_error(const char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

/**
 * read_header - read the ELF header from a file
 * @fd: the file descriptor to read from
 * @header: a pointer to the Elf64_Ehdr struct to store the header data in
 */
void read_header(int fd, Elf64_Ehdr *header)
{
    /* Set the file offset to the beginning of the file */
    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        print_error("Can't set file offset");
    }

    /* Read the header data from the file */
    if (read(fd, header, sizeof(Elf64_Ehdr)) == -1)
    {
        print_error("Can't read from file");
    }

    /* Check that the file is an ELF file */
    if (strncmp((const char *)header->e_ident, ELFMAG, SELFMAG) != 0)
    {
        print_error("Not an ELF file");
    }
}
