#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <elf.h>

#define ELF_MAGIC_SIZE 4

/**
 * error_exit - Prints an error message and exits
 * @code: The exit code.
 * @msg: The error message.
 */
void error_exit(int status, const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(status);
}

/**
 * print_elf_header_info - Prints the ELF header information.
 * @header: The ELF header structure.
 */
void print_elf_header_info(Elf64_Ehdr header)
{
	int i;

	printf("ELF Header:\n");

	printf("  Magic:   ");
	for (i = 0; i < ELF_MAGIC_SIZE; i++)
	{
		printf("%02x ", header.e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             %s\n", (header.e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n", (header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", (header.e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "Unknown");
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", (header.e_type == ET_EXEC) ? "EXEC (Executable file)" : (header.e_type == ET_DYN) ? "DYN (Shared object file)" : (header.e_type == ET_REL) ? "REL (Relocatable file)" : "Unknown");
	printf("  Entry point address:               0x%lx\n", header.e_entry);
}

/**
 * read_elf_header - Reads the ELF header from the file.
 * @fd: The file descriptor.
 * @header: Pointer to the ELF header structure.
 */
void read_elf_header(int fd, Elf64_Ehdr *header)
{
	ssize_t bytes_read = read(fd, header, sizeof(Elf64_Ehdr));

	if (lseek(fd, 0, SEEK_SET) == -1)
		error_exit(98, "Error: Unable to read ELF header");

	if (bytes_read == -1 || bytes_read != sizeof(Elf64_Ehdr))
		error_exit(98, "Error: Unable to read ELF header");
}

/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	const char *filename = argv[1];
	Elf64_Ehdr header;
	int fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		return (97);
	}

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		error_exit(98, "Error: Unable to open file");

	read_elf_header(fd, &header);

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 || header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		error_exit(98, "Error: Not an ELF file");
	}
	print_elf_header_info(header);

	if (close(fd) == -1)
		error_exit(100, "Error: Unable to close file");

	return (0);
}
