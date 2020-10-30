/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:48:42 by efumiko           #+#    #+#             */
/*   Updated: 2020/10/30 20:03:19 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
#include "libasm.h"

int main(void)
{
	char	*buf1;
    char	*buf2;
	

    /* 
    *********** 
    * FT_READ *
    ***********
    */

	printf("\n----READ_TEST----\n");
	buf1 = (char*)calloc(255, sizeof(char));
	buf2 = (char*)calloc(255, sizeof(char));
	printf("STDIN CORRECT; read: %li ---- ft_read: %li\nstring: %s", read(0, buf1, 10), ft_read(0, buf2, 10), buf1);
	printf("errno: %i\n\n", errno);
	bzero(buf1, 255);
	bzero(buf2, 255);

	printf("STDIN UNCORRECT; read: %li ---- ft_read: %li\n", read(0, buf1, -10), ft_read(0, buf2, -10));
	printf("errno: %i\n\n", errno);
	bzero(buf1, 255);
	bzero(buf2, 255);

    errno = 0;
    int		fd1;
    int     fd2;
    fd1 = open("./ft_read.s", O_RDWR);
    fd2 = open("./ft_read.s", O_RDWR);
	printf("FROM FILE; read: %li ---- ft_read: %li\n", ft_read(fd1, buf1, 255), ft_read(fd2, buf2, 255));
    printf("errno: %i\n\n", errno);
    bzero(buf1, 255);
	bzero(buf2, 255);
    close(fd1);
    close(fd2);

    fd1 = open("./ft_read.s", O_WRONLY);
    fd2 = open("./ft_read.s", O_WRONLY);
	printf("FROM FILE (ONLY WRITE); read: %li ---- ft_read: %li\n", ft_read(fd1, buf1, 255), ft_read(fd2, buf2, 255));
	printf("errno: %i\n\n", errno);
	bzero(buf1, 255);
	bzero(buf2, 255);
    close(fd1);
    close(fd2);
    
    printf("UNCORRET FD; read: %li ---- ft_read: %li\n", ft_read(74, buf1, 255), ft_read(74, buf2, 255));
    printf("errno: %i\n\n", errno);
    bzero(buf1, 255);
	bzero(buf2, 255);

    free(buf1);
    free(buf2);
    
    /* 
    ************
    * FT_WRITE *
    ************
    */
    int w1;
    int w2;

    errno = 0;
    printf("\n----WRITE_TEST----\n");
    
    printf("\n**************************\n***TEST count > str_len***\n**************************\n");
    w1 = write(1, "Hello, world!", 14);
    printf("\nwrite ret: %d errno: %i\n", w1, errno);
    w2 = ft_write(1, "Hello, world!", 14);
	printf("\nft_write ret: %d errno: %i\n", w2, errno);
	
    printf("\n\n**************************\n***TEST count < str_len***\n**************************\n");
    w1 = write(1, "Hello, world!\n", 3);
    printf("\nwrite ret: %d errno: %i\n", w1, errno);
    w2 = ft_write(1, "Hello, world!\n", 3);
	printf("\nft_write ret: %d errno: %i\n", w2, errno);
	
    printf("\n*********************\n***TEST count == 0***\n*********************");
    w1 = write(1, "Hello, world!\n", 0);
    printf("\nwrite ret: %d errno: %i", w1, errno);
    w2 = ft_write(1, "Hello, world!\n", 0);
	printf("\nft_write ret: %d errno: %i\n", w2, errno);

    printf("\n********************\n***TEST count < 0***\n********************");
    w1 = write(1, "Hello, world!\n", -10);
    printf("\nwrite ret: %d errno: %i", w1, errno);
    w2 = ft_write(1, "Hello, world!\n", -10);
	printf("\nft_write ret: %d errno: %i\n", w2, errno);

    printf("\n***********************\n***TEST UNCORRECT FD***\n***********************");
    w1 = write(74, "Hello, world!\n", 10);
    printf("\nwrite ret: %d errno: %i", w1, errno);
    w2 = ft_write(74, "Hello, world!\n", 10);
	printf("\nft_write ret: %d errno: %i\n", w2, errno);

    
    /* 
    ************
    * FT_STRLEN *
    ************
    */

    printf("\n----STRLEN_TEST----\n");
	printf("%li\n", ft_strlen("fshdjfjdsjfdskf8eru8239829d3824y32y432y4983284e238eh238984e2384e8239923d23849823949234"));
	printf("%li\n", ft_strlen("a"));
	printf("%li\n", ft_strlen("ab"));
	printf("%li\n", ft_strlen("abc"));
	printf("%li\n", ft_strlen("abcd"));
    
    
    /* 
    ************
    * FT_STRCMP *
    ************
    */

    printf("\n----STRCMP_TEST----\n");
	printf("s1 == s2: %d\n", ft_strcmp("abcd", "abcd"));
	printf("s1 == s2: %d\n", ft_strcmp("", ""));
	printf("s1 < s2 : %d\n", ft_strcmp("a", "abc"));
	printf("s1 < s2 : %d\n", ft_strcmp("", "abc"));
	printf("s1 < s2 : %d\n", ft_strcmp("123", "123abc"));
	printf("s1 > s2 : %d\n", ft_strcmp("abc", "a"));
	printf("s1 > s2 : %d\n", ft_strcmp("abc", ""));
	printf("s1 > s2 : %d\n", ft_strcmp("123abc", "123"));

    
    /* 
    ************
    * FT_STRCPY *
    ************
    */

    char *s;

	printf("\n----STRCPY_TEST----\n");
	s = (char*)malloc(sizeof(char) * 30);
	printf("%s\n", ft_strcpy(s, ""));
	printf("%s\n", ft_strcpy(s, "123"));
	printf("%s\n", ft_strcpy(s, "1234"));
    printf("%s\n", ft_strcpy(s, "asfsdhfjdsfdsfsdhjfsdhkgsdgfdsfdsfsdfsdgdhsfdfdsghjkjhgfdfghjkjhgfdghjkd"));
	free(s);
    

    /* 
    ************
    * FT_STRDUP *
    ************
    */

    char *str;

	printf("\n----STRDUP_TEST----\n");
	printf("normal string: %s\n", (str = ft_strdup("HELLO WORLD\n")));
	free(str);
	printf("normal string1: %s\n", (str = ft_strdup("\n")));
	free(str);
	printf("empty: %s\n", (str = ft_strdup("")));
	free(str);
	printf("normal string2: %s\n", (str = ft_strdup("12345678901234567890\n")));
	free(str);
	printf("very long string: %s\n", (str = ft_strdup("HELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLDHELLO WORLD\n")));
	free(str);
	return (0);
}