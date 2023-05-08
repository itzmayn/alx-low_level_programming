#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_error(const char *msg);
void read_header(int fd, Elf64_Ehdr *header);
void print_header(Elf64_Ehdr *header);

int main(int argc, char **argv)
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        print_error("Can't open file");
    }

    read_header(fd, &header);
    print_header(&header);

    close(fd);

    return 0;
}

void print_error(const char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

void read_header(int fd, Elf64_Ehdr *header)
{
    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        print_error("Can't set file offset");
    }

    if (read(fd, header, sizeof(Elf64_Ehdr)) == -1)
    {
        print_error("Can't read from file");
    }

    if (strncmp((const char *)header->e_ident, ELFMAG, SELFMAG) != 0)
    {
        print_error("Not an ELF file");
    }
}

void print_header(Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; ++i)
    {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("  %-34s", "Class:");
    if (header->e_ident[EI_CLASS] == ELFCLASS64)
    {
        printf("ELF64\n");
    }
    else if (header->e_ident[EI_CLASS] == ELFCLASS32)
    {
        printf("ELF32\n");
    }
    else
    {
        print_error("Invalid ELF class");
    }

    printf("  %-34s", "Data:");
    if (header->e_ident[EI_DATA] == ELFDATA2LSB)
    {
        printf("2's complement, little endian\n");
    }
    else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
    {
        printf("2's complement, big endian\n");
    }
    else
    {
        print_error("Invalid ELF data encoding");
    }

    printf("  %-34s%d\n", "Version:", header->e_ident[EI_VERSION]);

    printf("  %-34s", "OS/ABI:");
    switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - GNU\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_AIX:
        printf("UNIX - AIX\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
        }
    // Type
printf("  %-34s ", "Type:");
switch (header->e_type)
{
case ET_NONE:
    printf("NONE (No file type)\n");
    break;
case ET_REL:
    printf("REL (Relocatable file)\n");
    break;
case ET_EXEC:
    printf("EXEC (Executable file)\n");
    break;
case ET_DYN:
    printf("DYN (Shared object file)\n");
    break;
case ET_CORE:
    printf("CORE (Core file)\n");
    break;
default:
    printf("Unknown\n");
}

// Machine
printf("  %-34s ", "Machine:");
switch (header->e_machine)
{
case EM_X86_64:
    printf("Advanced Micro Devices X86-64\n");
    break;
case EM_386:
    printf("Intel 80386\n");
    break;
case EM_ARM:
    printf("ARM\n");
    break;
case EM_AARCH64:
    printf("AArch64\n");
    break;
case EM_RISCV:
    printf("RISC-V\n");
    break;
default:
    printf("Unknown\n");
}

// Version
printf("  %-34s %d\n", "Version:", header->e_version);

// Entry point address
printf("  %-34s 0x%lx\n", "Entry point address:", header->e_entry);

// Program header offset
printf("  %-34s %ld (bytes into file)\n", "Start of program headers:", header->e_phoff);

// Section header offset
printf("  %-34s %ld (bytes into file)\n", "Start of section headers:", header->e_shoff);

// Flags
printf("  %-34s 0x%x\n", "Flags:", header->e_flags);

// Size of this header
printf("  %-34s %d (bytes)\n", "Size of this header:", header->e_ehsize);

// Size of program headers
printf("  %-34s %d (bytes)\n", "Size of program headers:", header->e_phentsize);

// Number of program headers
printf("  %-34s %d\n", "Number of program headers:", header->e_phnum);

// Size of section headers
printf("  %-34s %d (bytes)\n", "Size of section headers:", header->e_shentsize);

// Number of section headers
printf("  %-34s %d\n", "Number of section headers:", header->e_shnum);

// Section header string table index
printf("  %-34s %d\n", "Section header string table index:", header->e_shstrndx);
    }
