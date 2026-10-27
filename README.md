*This project has been created as part of the 42 curriculum by mtoudic*

<h1>Description</h1>

<p>libft is a collection of basic function ranging from reimplementation of basic standard C library function, some variants and linked list.<br>

The goal is to have a good base to make even greater project without reinventing the wheel each time.</p>

<h1>Instructions</h1>

<p>To compile, launch 'make' in your terminal and then 'make clean' to remove all *.o files, This should compile fine on most POSIX compliant systems.<br>

To use it, include 'libft.h' in your *.c file and add '-lft' in your compiler options.</p>

<h1>Ressources</h1>

References for the standard C library have mainly been taken from the [linux man pages project](https://man7.org/linux/man-pages/).<br>

<h1>Features</h1>

<h2>Standard C library</h2>

These are reimplementation of some standard C library function, you can find the documentation for each one by removing the 'ft_' prefix when searching the [man pages](https://man7.org/linux/man-pages/).<br>

- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint
- ft_strlen
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_strlcpy
- ft_strlcat
- ft_toupper
- ft_tolower
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_memchr
- ft_memcmp
- ft_strnstr
- ft_atoi
- ft_calloc
- ft_strdup

Please note that 'ft_calloc' always return a valid unique pointer value when nmemb or size is 0, opposed to what you can see on the [man pages](https://man7.org/linux/man-pages/) documentation.

<h2>Advanced functions</h2>

These are more or less variants of existing function of the standard C library.<br>

- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split
- ft_itoa
- ft_strmapi
- ft_striteri
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

<h2>Linked list</h2>

These are some utility function made to manipulate linked lists.<br>

A linked list is a data structure where each node contains a pointer to his content and a pointer to the next node in the list or NULL if it's the last one, if you wants more details, see [here](https://en.wikipedia.org/wiki/Linked_list).<br>

Each node use this structure :

```C
typedef struct  s_list
{
    void		*content;
    struct s_list	*next;
}			t_list;
```
<br>
And you should use these following functions to write it :<br><br>

- ft_lstnew
- ft_lstadd_front
- ft_lstsize
- ft_lstlast
- ft_lstadd_back
- ft_lstdelone
- ft_lstclear
- ft_lstiter
- ft_lstmap
