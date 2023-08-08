#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <elf.h>

int _putchar(char c);
size_t _strlen(char *str);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int __attribute__((__unused__)) argc, char *argv[]);
void check97(int argc);
void check98(ssize_t check, char *file, int fd_from, int fd_to);
void check99(ssize_t check, char *file, int fd_from, int fd_to);
void check100(int check, int fd);
int main(int argc, char *argv[]);

#endif
