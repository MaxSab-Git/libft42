#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>
#include <assert.h>
#include <time.h>

#define TEST_VS_OG(test_func, og_func) \
    printf("ft_"#og_func" vs "#og_func" : "); \
    (test_func)(ft_##og_func, (og_func)); \
    printf("OK\n")

static char caesar(unsigned int i, char c)
{
    return ((c - 'a' + i) % 26) + 'a'; 
}

static void justlol(unsigned int i, char *c)
{
    (void)i;
    if (*c != 'l' && *c != 'o')
        *c = ' ';
}

static void printmem(void *s, size_t size)
{
	printf("\t[");
	for (size_t i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", ((int *)s)[i]);
	}
	printf("]\n");
}

static void print_list(t_list *lst)
{
    printf("\t");
    if (lst == NULL)
        printf("[empty]");
    while (lst != NULL)
    {
        printf("[%d]->", *((int *)lst->content));
        lst = lst->next;
    }
    printf("\n");
}

static void reverse_sign_list(void *content)
{
    *(int *)content = -*(int *)content;
}

static void *plus_one_list(void *content)
{
    int *newint = malloc(sizeof(int));
    *newint = *(int *)content + 1;
    return newint;
}

static const char *hellostr[] = {"Hello, World !", "troll", "", "abcdefghijklmnopqrstuvwxyz", "A quick brown fox jumps over the lazy dog"};
static const size_t hellosize = sizeof(hellostr) / sizeof(*hellostr);

static void test_isX(int(*ft_func)(int), int(*og_func)(int))
{
	for (int i = -1; i <= 128; i++)
	{
		assert(ft_func(i) == (og_func(i) != 0));
	}
}

static void test_strlen(size_t(*ft_func)(const char *), size_t(*og_func)(const char *))
{
    for (size_t i = 0; i < hellosize; i++)
	{
	    assert(ft_func(hellostr[i]) == og_func(hellostr[i]));
    }
}

static void test_memset(void *(*ft_func)(void *s, int c, size_t n), void *(*og_func)(void *s, int c, size_t n))
{
    const int fixedmemsize = 32;
	char ft_fixedmem[fixedmemsize];
	char og_fixedmem[fixedmemsize];

	ft_func(ft_fixedmem, -1, fixedmemsize);
	og_func(og_fixedmem, -1, fixedmemsize);

    assert(memcmp(ft_fixedmem, og_fixedmem, fixedmemsize) == 0);

    for (int i = 0; i < fixedmemsize; i++)
    {
        int random = rand() % 127;
	    ft_func(ft_fixedmem, random, i);
	    og_func(og_fixedmem, random, i);
        assert(memcmp(ft_fixedmem, og_fixedmem, fixedmemsize) == 0);
    }
}

static void test_bzero(void (*ft_func)(void *s, size_t n), void (*og_func)(void *s, size_t n))
{
    const int fixedmemsize = 32;
	char ft_fixedmem[fixedmemsize];
	char og_fixedmem[fixedmemsize];

	ft_func(ft_fixedmem, fixedmemsize);
	og_func(og_fixedmem, fixedmemsize);

    assert(memcmp(ft_fixedmem, og_fixedmem, fixedmemsize) == 0);
}

static void test_memcpy(void *(*ft_func)(void *dest, const void *src, size_t n), void *(*og_func)(void *dest, const void *src, size_t n))
{
    const int fixedmemsize = 32;
	char ft_fixedmem[fixedmemsize];
	char og_fixedmem[fixedmemsize];

    for (size_t i = 0; i < hellosize; i++)
    {
        ft_bzero(ft_fixedmem, fixedmemsize);
        ft_bzero(og_fixedmem, fixedmemsize);

        size_t len = strlen(hellostr[i]);
        if (len > fixedmemsize)
        {
            len = fixedmemsize;
        }

	    ft_func(ft_fixedmem, hellostr[i], len);
	    og_func(og_fixedmem, hellostr[i], len);

        assert(memcmp(ft_fixedmem, og_fixedmem, fixedmemsize) == 0);
    }
}

static void test_memmove(void *(*ft_func)(void *dest, const void *src, size_t n), void *(*og_func)(void *dest, const void *src, size_t n))
{
    const int fixedmemsize = 32;
	char ft_fixedmem[fixedmemsize];
	char og_fixedmem[fixedmemsize];

    test_memcpy(ft_func, og_func);

    for (size_t i = 0; i < 20; i++)
    {
        int randsrc = rand() % (fixedmemsize / 2);
        int randdst = rand() % (fixedmemsize / 2);
        int randsize = rand() % (fixedmemsize / 2);

	    ft_func(ft_fixedmem, hellostr[hellosize - 1], fixedmemsize);
	    og_func(og_fixedmem, hellostr[hellosize - 1], fixedmemsize);

	    ft_func(ft_fixedmem + randdst, ft_fixedmem + randsrc, randsize);
	    og_func(og_fixedmem + randdst, og_fixedmem + randsrc, randsize);

        assert(memcmp(ft_fixedmem, og_fixedmem, fixedmemsize) == 0);
    }
}

static void test_strl(size_t(*ft_func)(char *dest, const char *src, size_t n), size_t(*og_func)(char *dest, const char *src, size_t n))
{
    const int fixedmemsize = 32;
	char ft_fixedmem[fixedmemsize];
	char og_fixedmem[fixedmemsize];

    for (size_t i = 0; i < hellosize; i++)
    {
        ft_bzero(ft_fixedmem, fixedmemsize);
        ft_bzero(og_fixedmem, fixedmemsize);

	    size_t ft_ret = ft_func(ft_fixedmem, hellostr[i], fixedmemsize);
	    size_t og_ret = og_func(og_fixedmem, hellostr[i], fixedmemsize);

        assert(memcmp(ft_fixedmem, og_fixedmem, fixedmemsize) == 0);
        assert(ft_ret == og_ret);
    }

    for (size_t i = 0; i < 20; i++)
    {
        int randsrc = rand() % (fixedmemsize / 2);
        int randdst = rand() % (fixedmemsize / 2);
        int randsize = rand() % (fixedmemsize / 4);

	    size_t ft_ret = ft_func(ft_fixedmem + randdst, hellostr[hellosize - 1] + randsrc, randsize);
	    size_t og_ret = og_func(og_fixedmem + randdst, hellostr[hellosize - 1] + randsrc, randsize);

        assert(memcmp(ft_fixedmem, og_fixedmem, fixedmemsize) == 0);
        assert(ft_ret == og_ret);
    }
}

static void test_toX(int(*ft_func)(int), int(*og_func)(int))
{
    for (int i = -1; i <= 128; i++)
	{
	    assert(ft_func(i) == og_func(i));
    }
}

static void test_strchr(char *(*ft_func)(const char *s, int c), char *(*og_func)(const char *s, int c))
{
    for (size_t i = 0; i < hellosize; i++)
    {
        for (int c = -1; c <= 128; c++)
	    {
	        assert(ft_func(hellostr[i], c) == og_func(hellostr[i], c));
        }
    }
}

static void test_strncmp(int(*ft_func)(const char *s1, const char *s2, size_t n), int(*og_func)(const char *s1, const char *s2, size_t n))
{
    for (size_t i = 0; i < 50; i++)
    {
        int rands1 = rand() % hellosize;
        int rands2 = rand() % hellosize;
        size_t randsize = rand() % 50;
        
        size_t ft_ret = ft_func(hellostr[rands1], hellostr[rands2], randsize);
        size_t og_ret = og_func(hellostr[rands1], hellostr[rands2], randsize);
	    assert((ft_ret == 0 && og_ret == 0) || (ft_ret < 0 && og_ret < 0) || (ft_ret > 0 && og_ret > 0));
    }
}

static void test_memchr(void *(*ft_func)(const void *s, int c, size_t n), void *(*og_func)(const void *s, int c, size_t n))
{
    for (size_t i = 0; i < hellosize; i++)
    {
        for (int c = -1; c <= 128; c++)
	    {
	        assert(ft_func(hellostr[i], c, strlen(hellostr[i])) == og_func(hellostr[i], c, strlen(hellostr[i])));
        }
    }
}

static void test_memcmp(int(*ft_func)(const void *s1, const void *s2, size_t n), int(*og_func)(const void *s1, const void *s2, size_t n))
{
    for (size_t i = 0; i < 50; i++)
    {
        int rands1 = rand() % hellosize;
        int rands2 = rand() % hellosize;
        int randsize = rand() % 50;

        size_t ft_ret = ft_func(hellostr[rands1], hellostr[rands2], randsize);
        size_t og_ret = og_func(hellostr[rands1], hellostr[rands2], randsize);
	    assert((ft_ret == 0 && og_ret == 0) || (ft_ret < 0 && og_ret < 0) || (ft_ret > 0 && og_ret > 0));
    }
}

static void test_strnstr(char *(*ft_func)(const char *big, const char *little, size_t len), char *(*og_func)(const char *big, const char *little, size_t len))
{
	assert(ft_func("", "", 5) == og_func("", "", 5));
	assert(ft_func("", "555", 5) == og_func("", "555", 5));
    for (size_t i = 0; i < hellosize; i++)
    {
        for (int j = 0; j <= 1000; j++)
	    {
			int randomlen = (rand() % 50);
            char duo[3] = { (rand() % 26) + 'a', (rand() % 26) + 'a', '\0' };
	        assert(ft_func(hellostr[i], duo, randomlen) == og_func(hellostr[i], duo, randomlen));
        }
    }
}

static void test_atoi(int(*ft_func)(const char *nptr), int(*og_func)(const char *nptr))
{
	assert(ft_func("42") == og_func("42"));
	assert(ft_func("-42") == og_func("-42"));
	assert(ft_func("+42") == og_func("+42"));
	assert(ft_func("--42") == og_func("--42"));
	assert(ft_func("\t  -42") == og_func("\t  -42"));

    for (int j = 0; j <= 100; j++)
	{
        char nstr[11];
        nstr[0] = (rand() % 2) ? '-' : '+';
        for (size_t i = 1; i < 10; i++)
        {
            nstr[i] = (rand() % 10) + '0';
        }
        nstr[10] = '\0';
	    assert(ft_func(nstr) == og_func(nstr));

    }
}

int main()
{
    srand(time(0));
    printf("autotests begins :\n\n");

    TEST_VS_OG(test_isX, isalpha);
    TEST_VS_OG(test_isX, isdigit);
    TEST_VS_OG(test_isX, isalnum);
    TEST_VS_OG(test_isX, isascii);
    TEST_VS_OG(test_isX, isprint);
    TEST_VS_OG(test_strlen, strlen);
	TEST_VS_OG(test_memset, memset);
	TEST_VS_OG(test_bzero, bzero);
	TEST_VS_OG(test_memcpy, memcpy);
	TEST_VS_OG(test_memmove, memmove);
    TEST_VS_OG(test_strl, strlcpy);
    TEST_VS_OG(test_strl, strlcat);
    TEST_VS_OG(test_toX, tolower);
    TEST_VS_OG(test_toX, toupper);
    TEST_VS_OG(test_strchr, strchr);
    TEST_VS_OG(test_strchr, strrchr);
    TEST_VS_OG(test_strncmp, strncmp);
    TEST_VS_OG(test_memchr, memchr);
    TEST_VS_OG(test_memcmp, memcmp);
    TEST_VS_OG(test_strnstr, strnstr);
    TEST_VS_OG(test_atoi, atoi);

    printf("\nautotest end\n");

	{
		const size_t size = 10;
		int *dynamicmem = ft_calloc(size, sizeof(int));

		printf("\nft_calloc :\n");
		printmem(dynamicmem, size);
		dynamicmem[3] = 4;
		dynamicmem[6] = 2;
		printmem(dynamicmem, size);
		free(dynamicmem);

		dynamicmem = ft_calloc(0, 0);
		printf("\t%p\n", dynamicmem);
		free(dynamicmem);
	}

	{
		const size_t size = 10;
		int *dynamicmem = calloc(size, sizeof(int));

		printf("\ncalloc :\n");
		printmem(dynamicmem, size);
		dynamicmem[3] = 4;
		dynamicmem[6] = 2;
		printmem(dynamicmem, size);
		free(dynamicmem);

		dynamicmem = calloc(0, 0);
		printf("\t%p\n", dynamicmem);
		free(dynamicmem);
	}

	{
		char *dynamicmem = ft_strdup(hellostr[0]);

		printf("\nft_strdup:\n");
		printf("\t%s\n", dynamicmem);
		dynamicmem[3] = '4';
		dynamicmem[6] = '2';
		printf("\t%s\n", dynamicmem);
		free(dynamicmem);
	}

	{
		char *dynamicmem = strdup(hellostr[0]);

		printf("\nstrdup :\n");
		printf("\t%s\n", dynamicmem);
		dynamicmem[3] = '4';
		dynamicmem[6] = '2';
		printf("\t%s\n", dynamicmem);
		free(dynamicmem);
	}

	{
		char *dynamicmem = NULL;

		printf("\nft_substr :\n");
		printf("\t%s\n", hellostr[4]);

		for (size_t i = 0; i < 10; i++)
		{
			size_t start = rand() % ft_strlen(hellostr[4]);
			size_t len = rand() % 15 + 5;
			dynamicmem = ft_substr(hellostr[4], start, len);
			printf("\tsub string starting from %zu with max lenght %zu : \"%s\"\n", start, len, dynamicmem);
			free(dynamicmem);
		}
	}

	{
		char *dynamicmem = ft_strjoin(hellostr[0], hellostr[1]);

		printf("\nft_strjoin :\n");
		printf("\t%s\n", dynamicmem);
		free(dynamicmem);
	}

	{
		char *dynamicmem = ft_strtrim(hellostr[1], "lt");

		printf("\nft_strtrim :\n");
		printf("\ttrim \"%s\" from \"%s\" : %s\n", "lt", hellostr[1], dynamicmem);
		free(dynamicmem);
		dynamicmem = ft_strtrim(hellostr[1], "l");
		printf("\ttrim \"%s\" from \"%s\" : %s\n", "l", hellostr[1], dynamicmem);
		free(dynamicmem);
		dynamicmem = ft_strtrim(hellostr[1], "t");
		printf("\ttrim \"%s\" from \"%s\" : %s\n", "t", hellostr[1], dynamicmem);
		free(dynamicmem);
		dynamicmem = ft_strtrim(hellostr[1], hellostr[1]);
		printf("\ttrim \"%s\" from \"%s\" : %s\n", hellostr[1], hellostr[1], dynamicmem);
		free(dynamicmem);
		dynamicmem = ft_strtrim(hellostr[1], "trl");
		printf("\ttrim \"%s\" from \"%s\" : %s\n", "trl", hellostr[1], dynamicmem);
		free(dynamicmem);
		dynamicmem = ft_strtrim(hellostr[1], "ro");
		printf("\ttrim \"%s\" from \"%s\" : %s\n", "ro", hellostr[1], dynamicmem);
		free(dynamicmem);
		dynamicmem = ft_strtrim(hellostr[1], "to");
		printf("\ttrim \"%s\" from \"%s\" : %s\n", "to", hellostr[1], dynamicmem);
		free(dynamicmem);
	}

	{
		printf("\nft_split (by 'o'):\n");
		for (size_t j = 0; j < hellosize; j++)
		{
			char **dynamicmem = ft_split(hellostr[j], 'o');
			if (dynamicmem == NULL)
				continue;
			printf("\t[");
			for (size_t i = 0; dynamicmem[i] != NULL; i++)
			{
				if (i > 0)
					printf(", ");
				printf("\"%s\"", dynamicmem[i]);
				free(dynamicmem[i]);
			}
			printf("]\n");
			free(dynamicmem);
		}
	}

    {
        int n[] = { 0x7fffffff, 0x80000000, 0, 1337, -42 };
        const size_t nsize = sizeof(n) / sizeof(*n);

	    printf("\nft_itoa :\n");
        for (size_t i = 0; i < nsize; i++)
        {
		    char *dynamicmem = ft_itoa(n[i]);

		    printf("\tconvert %d: \"%s\"\n", n[i], dynamicmem);
		    free(dynamicmem);
        }
	}

    {
        char *dynamicmem = ft_strmapi(hellostr[1], caesar);

	    printf("\nft_strmapi :\n");
        printf("\tcaesar \"%s\" : \"%s\"\n", hellostr[1], dynamicmem);
        free(dynamicmem);
    }

    {
        char *dynamicmem = ft_strdup(hellostr[0]);

	    printf("\nft_striteri :\n");
        ft_striteri(dynamicmem, justlol);
        printf("\tjust lol \"%s\" : \"%s\"\n", hellostr[0], dynamicmem);
        free(dynamicmem);
    }

    {
	    printf("\nft_putchar_fd :\n\t");
        fflush(stdout);
        for (size_t i = 0; hellostr[0][i] != '\0'; i++)
        {
            ft_putchar_fd(hellostr[0][i], STDOUT_FILENO);
        }
        ft_putchar_fd('\n', STDOUT_FILENO);
    }

    {
	    printf("\nft_putstr_fd :\n\t");
        fflush(stdout);
        
        ft_putstr_fd((char *)hellostr[0], STDOUT_FILENO);
        ft_putchar_fd('\n', STDOUT_FILENO);
    }

    {
	    printf("\nft_putendl_fd :\n\t");
        fflush(stdout);
        
        ft_putendl_fd((char *)hellostr[0], STDOUT_FILENO);
    }

    {
        int n[] = { 0x7fffffff, 0x80000000, 0, 1337, -42 };
        const size_t nsize = sizeof(n) / sizeof(*n);

	    printf("\nft_putnbr_fd :\n");
        fflush(stdout);
        for (size_t i = 0; i < nsize; i++)
        {
            write(STDOUT_FILENO, "\t", 1);
            ft_putnbr_fd(n[i], STDOUT_FILENO);
            write(STDOUT_FILENO, "\n", 1);
        }
	}

    {
        printf("\nft_lstnew :\n");

        int initn[] = {42, -6, 7804, 1337, 0, -420, 67};
        const size_t initsize = sizeof(initn) / sizeof(*initn);

        t_list *master = ft_lstnew(malloc(sizeof(int)));
        *(int *)master->content = 100;
        print_list(master);

        printf("\nft_lstadd_front :\n");

        for (size_t i = 0; i < initsize; i++)
        {
            ft_lstadd_front(&master, ft_lstnew(malloc((sizeof(int)))));
            *(int *)master->content = initn[i];
        }
        print_list(master);

        printf("\nft_lstsize :\n");
        printf("\tmaster list size : %d\n", ft_lstsize(master));

        printf("\nft_lstlast :\n");
        printf("\tmaster last : %d\n", *(int *)ft_lstlast(master)->content);

        {
            printf("\nft_lstadd_back :\n");

            t_list *back = ft_lstnew(malloc((sizeof(int))));
            *(int *)back->content = 101;
            ft_lstadd_back(&master, back);
            print_list(master);
        }

        {
            printf("\nft_lstdelone :\n");

            t_list *tmp = master;
            master = master->next;
            ft_lstdelone(tmp, free);
            print_list(master);
        }

        {
            printf("\nft_lstiter :\n");
            ft_lstiter(master, reverse_sign_list);
            print_list(master);
        }

        {
            printf("\nft_lstmap :\n");
            t_list *dark_master = ft_lstmap(master, plus_one_list, free);
            print_list(dark_master);
            ft_lstclear(&dark_master, free);
        }

        printf("\nft_lstclear :\n");
        
        ft_lstclear(&master, free);
        print_list(master);
    }

    return 0;
}