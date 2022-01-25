#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "libasm.h"

int main(void)
{
	printf("__________len__________\n");
	printf("my     %d  s= empty\n", (int)ft_strlen(""));
	printf("origin %d  s= empty\n", (int)strlen(""));
	printf("my     %d  s= big string\n", (int)ft_strlen("Summary: The aim of this project is to get familiar with assembly language."));
	printf("origin %d  s= big string\n", (int)strlen("Summary: The aim of this project is to get familiar with assembly language."));
	printf("__________cmp__________\n");
	printf("my     'HELLO WORLD' 'BYE!!!'   %d\n", ft_strcmp("HELLO WORLD","BYE!!!"));
	printf("origin 'HELLO WORLD' 'BYE!!!'   %d\n", strcmp("HELLO WORLD","BYE!!!"));
	printf("my      empty                %d\n", ft_strcmp("",""));
	printf("origin  empty                %d\n", strcmp("",""));
	printf("my      '12' '122'         %d\n", ft_strcmp("12","122"));
	printf("origin  '12' '122'         %d\n", strcmp("12","122"));
	printf("my      'HELLO' ''         %d\n", ft_strcmp("HELLO",""));
	printf("origin  'HELLO' ''         %d\n", strcmp("126",""));
	printf("my      '122' '122'         %d\n", ft_strcmp("122","122"));
	printf("origin  '122' '122'         %d\n", strcmp("122","122"));

	char s[20] = "HELLO WORLD";
	char s1[20] = "BYE!!!";
	char s_[20] = "HELLO WORLD";
	char s_1[20] = "BYE!!!";
	char *s2;
	errno = 0;
	//int i;
	s2 = NULL;
	printf("__________cpy__________\n");
	printf("\ns1: %s, s2: %s\n", s, s1);
	printf("s2 -> s1: \n");
	ft_strcpy(s,s1);
	printf("s1: %s, s2: %s\n", s, s1);
	s[3] = '5';
	printf("\ns1: %s, s2: %s\n", s, s1);
	printf("s1 -> s2: \n");
	ft_strcpy(s1,s);
	printf("s1: %s, s2: %s\n", s, s1);

	printf("__________cpy original__________\n");
	printf("\ns1: %s, s2: %s\n", s_, s_1);
	printf("s2 -> s1:\n");
	strcpy(s_,s_1);
	printf("s1: %s, s2: %s\n", s_, s_1);
	s_[3] = '5';
	printf("\ns1: %s, s2: %s\n", s_, s_1);
	printf("s1 -> s2:\n");
	strcpy(s_1,s_);
	printf("s1: %s, s2: %s\n", s_, s_1);

	printf("\n___________write_________\n");
	printf("symbols = %d\n", (int)ft_write(1, "HELLO\n", 6));
	printf("errno = %d\n", errno);
	printf("symbols = %d\n", (int)write(1, "HELLO\n", 6));
	printf("errno = %d\n", errno);
	printf("___________write NULL_________\n");
	printf("symbols = %d\n", (int)ft_write(1, NULL, 6));
	printf("errno = %d\n", errno);
	printf("symbols = %d\n", (int)write(1, NULL, 6));
	printf("errno = %d\n", errno);
	printf("____________________\n\n");
	printf("\n___________read_________\n");
	errno = 0;
	int fd;
	fd = open("Makefile", O_WRONLY);
	printf("symbols = %d\n", (int)ft_read(fd, s, 3));
	s[3] = '\0';
	printf("errno = %d\n", errno);
	printf("%s\n", s);
	close(fd);
	fd = open("Makefile", O_WRONLY);
	printf("symbols = %d\n", (int)read(fd, s, 3));
	s[3] = '\0';
	printf("errno = %d\n", errno);
	printf("%s\n", s);
	close(fd);
	printf("\n________________dup_______________\n");
	s2 = NULL;
	printf("s = %s\n", s2);
	s2 = ft_strdup("LALALALLAAL");
	printf("s = %s\n", s2);
	s2 = NULL;
	printf("s = %s\n", s2);
	s2 = strdup("LALALALLAAL");
	printf("s = %s\n", s2);
	s2 = NULL;
	printf("s = %s\n", s2);
	s2 = ft_strdup("");
	printf("s = %s\n", s2);
	s2 = NULL;
	printf("s = %s\n", s2);
	s2 = strdup("");
	printf("s = %s\n", s2);
	return (0);
}
