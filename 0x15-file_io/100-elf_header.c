#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <stdlib.h>
#include <unistd.h>

int _strncmp(const char *s1, const char *s2, size_t n);
void _close(int fd);
void _read(int fd, char *buf, size_t count);
void elf_magic(const unsigned char *buffer);
size_t elf_class(const unsigned char *buffer);
int elf_data(const unsigned char *buffer);
void elf_version(const unsigned char *buffer);
void elf_osabi(const unsigned char *buffer);
void elf_abivers(const unsigned char *buffer);

int main(int argc, char **argv)
{
  int fd;
  Elf64_Ehdr header;

  if (argc != 2)
  {
    dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
    exit(98);
  }

  fd = open(argv[1], O_RDONLY);
  if (fd == -1)
  {
    dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
    exit(98);
  }

  if (read(fd, &header, sizeof(header)) == -1)
  {
    dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
    _close(fd);
    exit(98);
  }

  elf_magic(header.e_ident);
  elf_class(header.e_ident);
  elf_data(header.e_ident);
  elf_version(header.e_ident);
  elf_osabi(header.e_ident);
  elf_abivers(header.e_ident);

  _close(fd);

  return (0);
}

int _strncmp(const char *s1, const char *s2, size_t n)
{
  for ( ; n && *s1 && *s2; --n, ++s1, ++s2)
  {
    if (*s1 != *s2)
      return (*s1 - *s2);
  }
  if (n)
  {
    if (*s1)
      return (1);
    if (*s2)
      return (-1);
  }
  return (0);
}

void _close(int fd)
{
  if (close(fd) == -1)
  {
    write(STDERR_FILENO, "Error: Can't close fd\n", 22);
    exit(98);
  }
}

void _read(int fd, char *buf, size_t count)
{
  if (read(fd, buf, count) == -1)
  {
    write(STDERR_FILENO, "Error: Can't read from file\n", 28);
    _close(fd);
    exit(98);
  }
}

void elf_magic(const unsigned char *buffer)
{
  unsigned int i;

  if (_strncmp((const char *) buffer, ELFMAG, 4))
  {
    write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
    exit(98);
  }

  printf("ELF Header:\n  Magic:   ");

  for (i = 0; i < 16; ++i)
    printf("%02x%c", buffer[i], i < 15 ? ' ' : '\n');
}

size_t elf_class(const unsigned char *buffer)
{
    printf("  %-34s ", "Class:");

    if (buffer[EI_CLASS] == ELFCLASS64)
    {
        printf("ELF64\n");
        return (64);
    }

    printf("ELF32\n");
    return (32);
}

int main(int argc, char **argv)
{
    // Example usage
    unsigned char buffer[EI_NIDENT] = {0x7F, 'E', 'L', 'F', ELFCLASS64, ELFDATA2LSB, EV_CURRENT};
    size_t class = elf_class(buffer);
    printf("ELF class: %zu bits\n", class);

    return 0;
}
