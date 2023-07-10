#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error_and_exit - function to print error message and exit
 * @error_message: the error message
 */
void print_error_and_exit(const char *error_message)
{
	dprintf(STDERR_FILENO, "%s\n", error_message);
	exit(98);
}

/**
 * print_elf_header_info - function to print ELF header information
 * @header: pointer to the ELF header
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("Magic: ");

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class: %d-bit\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);

	printf("Data: ");
	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Unknown data encoding\n");

	printf("Version: %d\n", header->e_ident[EI_VERSION]);

	printf("OS/ABI: ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64 UNIX\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
		default:
			printf("Unknown OS/ABI\n");
			break;
	}

	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf("Type: ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("None (No file type)\n");
			break;
		case ET_REL:
			printf("Relocatable file (Relocation file)\n");
			break;
		case ET_EXEC:
			printf("Executable file\n");
			break;
		case ET_DYN:
			printf("Shared object file\n");
			break;
		case ET_CORE:
			printf("Core file\n");
			break;
		default:
			printf("Unknown file type\n");
			break;
	}

	printf("Entry point address: 0x%lx\n", header->e_entry);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, otherwise 98 on error
 */
int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	Elf64_Ehdr header;
	ssize_t read_bytes;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		return (97);
	}

	filename = argv[1];
	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot open file %s\n", filename);
		return (98);
	}

	read_bytes = read(fd, &header, sizeof(header));
	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to read from file %s\n", filename);
		close(fd);
		return (98);
	}

	if (read_bytes != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Incomplete read from file %s\n", filename);
		close(fd);
		return (98);
	}

	print_elf_header_info(&header);

	close(fd);
	return (0);
}
