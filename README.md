notion으로 실행 시 더 보기 수월하다
ttps://www.notion.so/Libft-78424b63f7474eb1a3eca83170f11e48
- Libc functions
    
    alphabet 순서로 정렬하였으며 함수 원형과 간단한 설명이 포함되어있다.
    
    - 참고자료
        - unsigned int 와 size_t의 차이
            
            **size_t**는 a.k.a. '**long unsigned int'(별칭)**로서 '이론상 **가장 큰 사이즈**를 담을 수 있는 **unsigned 데이터 타입**'으로 정의된다.
            
            현재 대부분의 x86 컴퓨터는 32비트 또는 64비트 운영체제를 사용하고 있다. 요즘은 ARM에서도 64비트를 사용 중이다. c언어의 변수의 크기는 구동 환경에 따라 다르다. 보편적인 경우에 int형의 크기는 4바이트 (32비트)라고 알 것이다. 이는 32비트의 환경에서만 적용된다.
            
            **즉, 대부분의 변수는 동작 환경에 따라 크기가 달라진다.**
            
            하지만 size_t 의 경우에는 다르다. 보통 헤더 파일에 정의가 되어 있는데, size_t는 4바이트의 크기를 가지고 있다 (32비트 unsigned int). 이것은 환경이 바뀌어도 **항상 4바이트로 고정이 되어 있다.**
            
            그래서 어디서든 4바이트의 크기(unsigned int)를 가지는 변수를 선언하고 싶을 때는 size_t로 선언하면 된다. 이와 비슷하게 ssize_t 라는 변수도 있는데, 이것은 signed int 형태를 가진다.
            
            즉 더 안전하게 사용할 때 size_t 를 쓰시면 되겠다.
            
            참고 링크 : [https://tre2man.tistory.com/236](https://tre2man.tistory.com/236)
            
        - pointer 연산 시 unsigned_char 를 사용하는 이유
            
            GCC에서는 void포인터를 char, unsigned char 크기만큼 연산합니다 → 1 byte 씩
            
            포인터는 주솟값 연산이니까 부호를 쓰지 않습니다.
            
            char를 쓰지 않고 unsigned char를 쓰는 것이 관례입니다.
            
            참고 : [https://dojang.io/mod/page/view.php?id=790](https://dojang.io/mod/page/view.php?id=790)
            
        - restrict란
            
            restrict 포인터는 메모리 접근에 관련된 최적화 기능입니다.
            
            restrict 포인터는 각 포인터가 서로 다른 메모리 공간을 가리키고 있고, 다른 곳에서 접근하지 않으니 컴파일러가 최적화를 하라는 뜻입니다.
            
            만약 같은 메모리 공간을 가리키는 포인터에 restrict를 붙여서 컴파일하게 되면 최적화 때문에 잘못된 결과가 나올 수 있으니 주의해야 합니다. 따라서 포인터가 가리키는 메모리 공간을 프로그래머가 직접 확인한 뒤 다른 공간을 가리킬 때만 restrict를 사용해야 합니다.
            
            참고 : [https://dojang.io/mod/page/view.php?id=760](https://dojang.io/mod/page/view.php?id=760)
            
        - memcpy 와 memmove의 차이
            - memcpy는 restrict가 붙어있고 memmove는 restrict가 없습니다. 여기서 memmove는 내부적으로 같은 메모리 공간을 가리키는지, 메모리가 겹치는지 모두 확인을 하기 때문에 성능이 떨어집니다. 만약 두 메모리 공간이 다른 공간을 가리키고 겹치지 않는다면 최적화된 memcpy를 사용하여 성능을 향상시킬 수 있습니다.
            - memcpy는 메모리의 내용을 직접 copy하고, memmove는 메모리의 내용을 임시저장소에 저장한 후 복사한다. 따라서 memcpy의 속도는 memmove보다 빠르지만 안정성면에서 떨어진다. memory를 복사할 때 memcpy의 경우에는 자기 자신의 내용을 복사하여 덮어쓸 때, 인접한 메모리에 의해 겹침현상(overlap)이 일어난다.
                
                [참고](https://blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=sharonichoya&logNo=220510332768#:~:text=memcpy%EB%8A%94%20%EB%A9%94%EB%AA%A8%EB%A6%AC%EC%9D%98%20%EB%82%B4%EC%9A%A9,%EB%8F%99%EC%9E%91%ED%95%98%EB%8A%94%20%EA%B2%83%EC%9D%84%20%EC%9D%98%EB%AF%B8%ED%95%9C%EB%8B%A4.) 
                
    - ft_atoi
        - man page
            
            SYNOPSIS
            #include <stdlib.h>
            
            ```
             int
             atoi(const char *str);
            
             #include <xlocale.h>
            
             int
             atoi_l(const char *str, locale_t loc);
            
            ```
            
            DESCRIPTION
            The atoi() function converts the initial portion of the string pointed to
            by str to int representation.
            
            ```
             It is equivalent to:
            
                   (int)strtol(str, (char **)NULL, 10);
            
             While the atoi() function uses the current locale, the atoi_l() function
             may be passed a locale directly. See xlocale(3) for more information.
            ```
            
        - 함수 설명
            
            const char 형의 배열을 받아 숫자로 바꿔주는 함수이다.
            
            처음에는 whitespace 가 올 수 있으며, 그 후에는 부호 하나만 올 수 있다.
            
            그 외에는 숫자만 인식하며, 숫자가 아닌 다른 문자가 온다면 이때까지 읽은 곳 까지 리턴한다.
            
            ```c
            static int	is_space(char c)//static으로 안전하게 보호
            {
            	if (c == '\t' || c == '\f' || c == '\n'
            		|| c == '\r' || c == '\v' || c == ' ')
            		return (1);
            	else
            		return (0);
            }
            
            int	ft_atoi(const char *str)
            {
            	int			i;
            	long long	result;//-2147483648까지 계산하기 위해 long long 선언
            	long long	sign;//result와 곱해주기 위해 long long 으로 선언
            
            	i = 0;
            	result = 0;
            	sign = 1;
            	while (is_space(str[i]) && str[i] != '\0')//whitespace 처리
            		i++;
            	if (str[i] == '+' || str[i] == '-')//부호 하나만 읽음
            	{
            		if (str[i] == '+')
            			sign *= 1;
            		else if (str[i] == '-')
            			sign *= -1;
            		i++;
            	}
            	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
            		result = (result * 10) + (str[i++] - '0');
            	if (result * sign > 2147483647)//int형 반환이므로 예외처리
            		return (-1);
            	else if (result * sign < -2147483648)
            		return (0);
            	else
            		return (result * sign);
            }
            ```
            
    - ft_bzero
        - man page
            
            SYNOPSIS
            #include <strings.h>
            
            ```
             void
             bzero(void *s, size_t n);
            
            ```
            
            DESCRIPTION
            The bzero() function writes n zeroed bytes to the string s.  If n is zero,
            bzero() does nothing.
            
        - 함수 설명
            
            void *s의 주소값을 0으로 초기화해준다.
            
            ```c
            void	ft_bzero(void *s, size_t n)
            {
            	unsigned char	*pointer;
            	int				i;
            
            	pointer = (unsigned char *) s;//s의 메모리 영역을 pointer에 reference
            	i = 0;
            	while (n--)
            		pointer[i++] = 0;//pointer의 값 즉 s의 메모리 영역을 n만큼 0으로 채운다
            }
            ```
            
    - ft_calloc
        - man page
            
            SYNOPSIS
            #include <stdlib.h>
            
            ```
             void *
             calloc(size_t count, size_t size);
            ```
            
            DESCRIPTION
            
            ```
            The malloc(), calloc(), valloc(), realloc(), and reallocf() functions
            allocate memory.  The allocated memory is aligned such that it can be used
            for any data type, including AltiVec- and SSE-related types.  The
            aligned_alloc() function allocates memory with the requested alignment.
            The free() function frees allocations that were created via the preceding
            allocation functions.
            
            The calloc() function contiguously allocates enough space for count objects
            that are size bytes of memory each and returns a pointer to the allocated
            memory.  The allocated memory is filled with bytes of value zero.
            ```
            
        - 함수 설명
            
            size*count 만큼의 공간을 확보 후 메모리를 비우고 그 주소값을 전달해준다
            
            ```c
            void	*ft_calloc(size_t count, size_t size)
            //size크기의 변수를 count 만큼 저장 할 수 있는 메모리 공간 할당 
            {
            	void	*ret;
            
            	ret = malloc(sizeof(char) * count * size);//ret에 동적으로 메모리 공간 할당
            	if (!ret)//동적할당 실패 시 return NULL
            		return (NULL);
            	ft_bzero(ret, count * size);//사용 할 수 있게 메모리 공간으로 0으로 초기화해준다
            	return (ret);
            }
            ```
            
    - ft_isalnum
        - man page
            
            SYNOPSIS
            #include <ctype.h>
            
            ```
             int
             isalnum(int c);
            
            ```
            
            DESCRIPTION
            The isalnum() function tests for any character for which isalpha(3) or
            isdigit(3) is true.  The value of the argument must be representable as an
            unsigned char or the value of EOF.
            
            ```
             In the ASCII character set, this includes the following characters
             (preceded by their numeric values, in octal):
            ```
            
            RETURN VALUES
            The isalnum() function returns zero if the character tests false and
            returns non-zero if the character tests true.
            
        - 함수 설명
            
            알파벳이거나 숫자이면 해당 아스키값을 리턴
            
            ```c
            int	ft_isalnum(int c)
            {
            	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
            		|| (c >= '0' && c <= '9'))//alphabet이거나 digit인 경우에
            	{
            		return (c);//해당 아스키값 리턴
            	}
            	else
            		return (0);//아니라면 0을 리턴
            }
            ```
            
    - ft_isalpha
        - man page
            
            SYNOPSIS
            #include <ctype.h>
            
            ```
             int
             isalpha(int c);
            
            ```
            
            DESCRIPTION
            The isalpha() function tests for any character for which isupper(3) or
            islower(3) is true.  The value of the argument must be representable as an
            unsigned char or the value of EOF.
            
            ```
             In the ASCII character set, this includes the following characters
             (preceded by their numeric values, in octal):
            ```
            
            RETURN VALUES
            The isalpha() function returns zero if the character tests false and
            returns non-zero if the character tests true.
            
        - 함수 설명
            
            알파벳인 경우 해당 아스키값을 리턴
            
            ```c
            int	ft_isalpha(int c)
            {
            	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))//alphabet인 경우
            	{
            		return (c);//해당 아스키 값을 리턴
            	}
            	else
            		return (0);
            }
            ```
            
    - ft_isascii
        - man page
            
            LIBRARY
            Standard C Library (libc, -lc)
            
            SYNOPSIS
            #include <ctype.h>
            
            ```
             int
             isascii(int c);
            
            ```
            
            DESCRIPTION
            The isascii() function tests for an ASCII character, which is any character
            between 0 and octal 0177 inclusive.
            
        - 함수 설명
            
            아스키값 0부터 127사이라면 1을 리턴
            
            ```c
            int	ft_isascii(int c)
            {
            	if (c >= 0 && c <= 127)//만약 테스트하는 값이 0부터 127 사이라면
            	{
            		return (1);//1을 리턴
            	}
            	else
            		return (0);//아니면 0
            }
            ```
            
    - ft_isdigit
        - man page
            
            SYNOPSIS
            #include <ctype.h>
            
            ```
             int
             isdigit(int c);
            ```
            
            DESCRIPTION
            The isdigit() function tests for a decimal digit character.  Regardless of
            locale, this includes the following characters only:
            
            ```
             ``0''``1''``2''``3''``4''
             ``5''``6''``7''``8''``9''
            
             The isnumber() function behaves similarly to isdigit(), but may recognize
             additional characters, depending on the current locale setting.
            
             The value of the argument must be representable as an unsigned char or the
             value of EOF.
            
            ```
            
            RETURN VALUES
            The isdigit() and isnumber() functions return zero if the character tests
            false and return non-zero if the character tests true.
            
        - 함수 설명
            
            숫자라면 해당 아스키값을 리턴
            
            ```c
            int	ft_isdigit(int c)
            {
            	if (c >= '0' && c <= '9')//만약 digit에 포함 된다면
            		return (c);//해당하는 아스키 값을 리턴
            	else
            		return (0);
            }
            ```
            
    - ft_isprint
        - man page
            
            SYNOPSIS
            #include <ctype.h>
            
            ```
             int
             isprint(int c);
            
            ```
            
            DESCRIPTION
            The isprint() function tests for any printing character, including
            space (‘ ’).  The value of the argument must be representable as an
            unsigned char or the value of EOF.
            
            ```
             In the ASCII character set, this includes the following characters
             (preceded by their numeric values, in octal):
            ```
            
            RETURN VALUES
            The isprint() function returns zero if the character tests false and
            returns non-zero if the character tests true.
            
        - 함수 설명
            
            프린트 가능한 아스키값이라면 (32부터 126) 1을 리턴한다
            
            ```c
            int	ft_isprint(int c)
            {
            	if (c >= ' ' && c <= '~')//32부터 126까지 printable하다
            		return (1);//print하다면 1 return
            	else
            		return (0);//else 0
            }
            ```
            
    - ft_memchr
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             void *
             memchr(const void *s, int c, size_t n);
            
            ```
            
            DESCRIPTION
            The memchr() function locates the first occurrence of c (converted to
            an unsigned char) in string s.
            
            RETURN VALUES
            The memchr() function returns a pointer to the byte located, or NULL
            if no such byte exists within n bytes.
            
        - 함수 설명
            
            void pointer의 메모리 블럭으로 접근하여 s가 n 안에 c와 같은 값을 찾는다면 해당 주소를 리턴해준다
            
            실패시 0을 리턴
            
            ```c
            void	*ft_memchr(const void *s, int c, size_t n)
            {
            	unsigned char	*ptr_s;
            	int				i;
            
            	i = 0;
            	ptr_s = (unsigned char *)s;//ptr_s를 s의 주소로 mapping
            	while (n--)//n동안 검색
            	{
            		if (*ptr_s == (unsigned char)c)//ptr_s의 바이트가 c와 같다면 검색종료
            			return (ptr_s);//c가 있는 주소 리턴
            		else
            			ptr_s++;
            	}
            	return (0);//n동안 못찾을 경우 0 리턴
            }
            ```
            
    - ft_memcmp
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             int
             memcmp(const void *s1, const void *s2, size_t n);
            
            ```
            
            DESCRIPTION
            The memcmp() function compares byte string s1 against byte string s2.
            Both strings are assumed to be n bytes long.
            
            RETURN VALUES
            The memcmp() function returns zero if the two strings are identical,
            otherwise returns the difference between the first two differing
            bytes (treated as unsigned char values, so that ‘\200’ is greater
            than ‘\0’, for example).  Zero-length strings are always identical.
            This behavior is not required by C and portable code should only
            depend on the sign of the returned value.
            
        - 함수 설명
            
            n동안 s1과 s2의 내용이 같다면 0
            
            다르다면 차이값을 리턴한다.
            
            ```c
            int	ft_memcmp(const void *s1, const void *s2, size_t n)
            {
            	unsigned char	*ptr_s1;//s1을 메모리값을 저장하는 포인터
            	unsigned char	*ptr_s2;//s2의 메모리값을 저장하는 포인터
            
            	ptr_s1 = (unsigned char *)s1;
            	ptr_s2 = (unsigned char *)s2;
            	while (n--)//n 동안 검색
            	{
            		if (*ptr_s1 != *ptr_s2)//만약 값이 다르다면
            			return (*ptr_s1 - *ptr_s2);//차이값을 리턴
            		ptr_s1++;
            		ptr_s2++;
            	}
            	return (0);//n동안 차이가 없을 시
            }
            ```
            
    - ft_memcpy
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             void *
             memcpy(void *restrict dst, const void *restrict src, size_t n);
            
            ```
            
            DESCRIPTION
            The memcpy() function copies n bytes from memory area src to memory
            area dst.  If dst and src overlap, behavior is undefined.
            Applications in which dst and src might overlap should use memmove(3)
            instead.
            
            RETURN VALUES
            The memcpy() function returns the original value of dst.
            
        - 함수 설명
            
            n까지 src의 값을 dest으로 메모리 블럭을 통해 복사한다
            
            ```c
            void	*ft_memcpy(void *restrict dest, void *restrict src, size_t n)
            {
            	unsigned char	*ptr_dest;
            	unsigned char	*ptr_src;
            
            	ptr_dest = (unsigned char *)dest;//dest의 메모리 블럭
            	ptr_src = (unsigned char *)src;//src의 메모리 블럭
            	if (dest == NULL && src == NULL)
            		return (NULL);//둘다 없다면 NULL을 리턴
            	while (n--)
            		*ptr_dest++ = *ptr_src++;//src의 메모리블럭 내용을 dest에 복사
            	return (dest);
            }
            ```
            
    - ft_memmove
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             void *
             memmove(void *dst, const void *src, size_t len);
            
            ```
            
            DESCRIPTION
            The memmove() function copies len bytes from string src to string
            dst.  The two strings may overlap; the copy is always done in a non-
            destructive manner.
            
            RETURN VALUES
            The memmove() function returns the original value of dst.
            
        - 함수 설명
            
            overlap이 되어도 방지할 수 있게 memcpy보다 한단계 위의 레벨이지만, 조금 더 느리다.
            
            ```c
            void	*ft_memmove(void *dest, const void *src, size_t len)
            {
            	unsigned char	*ptr_dest;
            	unsigned char	*ptr_src;
            
            	ptr_dest = (unsigned char *)dest;//dest의 메모리 블럭
            	ptr_src = (unsigned char *)src;//src의 메모리 블럭
            	if (dest == NULL && src == NULL)
            		return (NULL);//둘 다 없다면 NULL 리턴
            	if (ptr_dest < ptr_src)//overlap 방지를 위해 src가 더 클 경우 
            	{
            		while (len--)
            			*ptr_dest++ = *ptr_src++;//src에서 순방향대로 넣어준다
            	}
            	else//src가 더 작을 경우
            	{
            		while (len--)
            			*(ptr_dest + len) = *(ptr_src + len);//역방향부터 삽입해 overlap방지
            	}
            	return (dest);
            }
            ```
            
    - ft_memset
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             void *
             memset(void *b, int c, size_t len);
            
            ```
            
            DESCRIPTION
            The memset() function writes len bytes of value c (converted to an
            unsigned char) to the string b.
            
            RETURN VALUES
            The memset() function returns its first argument.
            
        - 함수 설명
            
            len만큼 void b의 메모리 블럭으로 접근하여 int c(ASCII)의 값으로 바꿔준다.
            
            ```c
            void	*ft_memset(void *b, int c, size_t len)
            {
            	int				i;
            	unsigned char	*pointer;
            
            	pointer = (unsigned char *) b;//pointer가 b의 메모리블럭을 reference
            	i = 0;
            	while (len--)
            		pointer[i++] = (unsigned char)c;//len 만큼 int c로 변환
            	return (b);
            }
            ```
            
    - ft_strchr
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             char *
             strchr(const char *s, int c);
            
             char *
             strrchr(const char *s, int c);
            
            ```
            
            DESCRIPTION
            The strchr() function locates the first occurrence of c (converted to
            a char) in the string pointed to by s.  The terminating null
            character is considered to be part of the string; therefore if c is
            ‘\0’, the functions locate the terminating ‘\0’.
            
            ```
             The strrchr() function is identical to strchr(), except it locates
             the last occurrence of c.
            
            ```
            
            RETURN VALUES
            The functions strchr() and strrchr() return a pointer to the located
            character, or NULL if the character does not appear in the string.
            
        - 함수 설명
            
            char형의 배열 str에서 int c(ASCII)가 발생하는 부분의 주소를 리턴해준다.
            
            없다면 0을 리턴
            
            ```c
            char	*ft_strchr(const char *str, int c)
            {
            	int	i;
            
            	i = 0;
            	while (str[i] != '\0')
            	{
            		if (str[i] == c)//찾을 경우
            			return (&str[i]);
            		else
            			i++;
            	}
            	if (str[i] == c)//만약 c 가 0이라면
            		return (&str[i]);//마지막 배열의 주소를 리턴
            	return (0);
            }
            ```
            
    - ft_strdup
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             char *
             strdup(const char *s1);
            
             char *
             strndup(const char *s1, size_t n);
            
            ```
            
            DESCRIPTION
            The strdup() function allocates sufficient memory for a copy of the
            string s1, does the copy, and returns a pointer to it.  The pointer
            may subsequently be used as an argument to the function free(3).
            
            ```
             If insufficient memory is available, NULL is returned and errno is
             set to ENOMEM.
            
             The strndup() function copies at most n characters from the string s1
             always NUL terminating the copied string.
            ```
            
        - 함수 설명
            
            s1과 동일한 배열을 생성 후 생성한 배열의 주소를 리턴한다.
            
            ```c
            char	*ft_strdup(const char *s1)
            {
            	int		len_s1;
            	char	*ret;
            	int		i;
            
            	len_s1 = ft_strlen(s1);//먼저 s1의 크기를 구한다
            	ret = malloc(sizeof(char) * (len_s1 + 1));//ret 동적할당
            	if (!ret)//malloc 실패시 null guard
            		return (NULL);
            	i = 0;
            	while (i < len_s1)
            	{
            		ret[i] = s1[i];//데이터값 복사
            		i++;
            	}
            	ret[i] = '\0';
            	return (ret);
            }
            ```
            
    - ft_strlcat
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             size_t
             strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
            
             size_t
             strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
            
            ```
            
            DESCRIPTION
            The strlcpy() and strlcat() functions copy and concatenate strings with
            the same input parameters and output result as snprintf(3).  They are
            designed to be safer, more consistent, and less error prone replacements
            for the easily misused functions strncpy(3) and strncat(3).
            
            ```
             strlcpy() and strlcat() take the full size of the destination buffer and
             guarantee NUL-termination if there is room.  Note that room for the NUL
             should be included in dstsize.
            
             strlcpy() copies up to dstsize - 1 characters from the string src to dst,
             NUL-terminating the result if dstsize is not 0.
            
             strlcat() appends string src to the end of dst.  It will append at most
             dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
             dstsize is 0 or the original dst string was longer than dstsize (in
             practice this should not happen as it means that either dstsize is
             incorrect or that dst is not a proper string).
            
             If the src and dst strings overlap, the behavior is undefined.
            
            ```
            
            RETURN VALUES
            Besides quibbles over the return type (size_t versus int) and signal
            handler safety (snprintf(3) is not entirely safe on some systems), the
            following two are equivalent:
            
            ```
                   n = strlcpy(dst, src, len);
                   n = snprintf(dst, len, "%s", src);
            
             Like snprintf(3), the strlcpy() and strlcat() functions return the total
             length of the string they tried to create.  For strlcpy() that means the
             length of src.  For strlcat() that means the initial length of dst plus
             the length of src.
            
             If the return value is >= dstsize, the output string has been truncated.
             It is the caller's responsibility to handle this.
            ```
            
        - 함수 설명
            
            기본적으로 함수 자체는 strlcat은 문자열 src 를 dst 의 끝에 추가해주는 함수이다.
            
            dst 의 마지막 위치에 src 을 size - strlen(dst) - 1 만큼 복사하고 (-1을 해주는 이유는 더 안전한 함수로 사용하기 위해), 끝에 널문자를 삽입한다.
            
            이후, 결합되는 문자열의 총 길이를 반환한다.
            
            여기서 size는 버퍼의 크기이고 size와 dst의 크기에 따라 반환값이 달라지게 된다.
            
            - size가 dst의 크기보다 작을 때, strlen(src) + size 를 반환한다.
            - size가 dst의 크기보다 클 때, strlen(src) + strlen(dst)를 반환한다.
            
            ```c
            size_t	ft_strlcat(char *restrict dest, char *restrict src, size_t size)
            {
            	size_t	i;
            	size_t	len;
            	size_t	dest_len;
            
            	i = 0;
            	dest_len = ft_strlen(dest);//첫 dest_len
            	if (dest_len > size)
            		return (ft_strlen(src) + size);
            		//size가 더 작을 경우 어차피 추가가 안되므로 바로 리턴을 해준다
            	len = ft_strlen(dest);
            	while (len < size - 1 && src[i] != '\0')
            		dest[len++] = src[i++];
            	dest[len] = '\0';
            	return (dest_len + ft_strlen(src));//결합된 총 문자열의 길이
            }
            ```
            
    - ft_strlcpy
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             size_t
             strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
            
             size_t
             strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
            
            ```
            
            DESCRIPTION
            The strlcpy() and strlcat() functions copy and concatenate strings with
            the same input parameters and output result as snprintf(3).  They are
            designed to be safer, more consistent, and less error prone replacements
            for the easily misused functions strncpy(3) and strncat(3).
            
            ```
             strlcpy() and strlcat() take the full size of the destination buffer and
             guarantee NUL-termination if there is room.  Note that room for the NUL
             should be included in dstsize.
            
             strlcpy() copies up to dstsize - 1 characters from the string src to dst,
             NUL-terminating the result if dstsize is not 0.
            
             strlcat() appends string src to the end of dst.  It will append at most
             dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
             dstsize is 0 or the original dst string was longer than dstsize (in
             practice this should not happen as it means that either dstsize is
             incorrect or that dst is not a proper string).
            
             If the src and dst strings overlap, the behavior is undefined.
            
            ```
            
            RETURN VALUES
            Besides quibbles over the return type (size_t versus int) and signal
            handler safety (snprintf(3) is not entirely safe on some systems), the
            following two are equivalent:
            
            ```
                   n = strlcpy(dst, src, len);
                   n = snprintf(dst, len, "%s", src);
            
             Like snprintf(3), the strlcpy() and strlcat() functions return the total
             length of the string they tried to create.  For strlcpy() that means the
             length of src.  For strlcat() that means the initial length of dst plus
             the length of src.
            
             If the return value is >= dstsize, the output string has been truncated.
             It is the caller's responsibility to handle this.
            ```
            
        - 함수 설명
            
            destsize만큼 src에서 dest까지 복사하는 함수
            
            ```c
            size_t	ft_strlcpy(char *restrict dest, char *restrict src, size_t destsize)
            {
            	size_t	i;
            	size_t	len;
            
            	i = 0;
            	len = ft_strlen(src);
            	if (destsize == 0)
            		return (len);//0이라면 그냥 리턴
            	while ((i < destsize -1) && src[i] != '\0')//src가 이전에 끝나도 멈춰야 한다
            	{
            		dest[i] = src[i];//복사
            		i++;
            	}
            	dest[i] = '\0';//string이므로 마지막에 null 추가
            	return (len);
            }
            ```
            
    - ft_strlen
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             size_t
             strlen(const char *s);
            
             size_t
             strnlen(const char *s, size_t maxlen);
            
            ```
            
            DESCRIPTION
            The strlen() function computes the length of the string s.  The strnlen()
            function attempts to compute the length of s, but never scans beyond the
            first maxlen bytes of s.
            
            RETURN VALUES
            The strlen() function returns the number of characters that precede the
            terminating NUL character.  The strnlen() function returns either the
            same result as strlen() or maxlen, whichever is smaller.
            
        - 함수 설명
            
            str의 배열의 크기를 구하는 함수
            
            ```c
            size_t	ft_strlen(const char *str)
            {
            	int	i;
            
            	i = 0;
            	while (str[i] != '\0')
            		i++;
            	return (i);
            }
            ```
            
    - ft_strncmp
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             int
             strcmp(const char *s1, const char *s2);
            
             int
             strncmp(const char *s1, const char *s2, size_t n);
            
            ```
            
            DESCRIPTION
            The strcmp() and strncmp() functions lexicographically compare the null-
            terminated strings s1 and s2.
            
            ```
             The strncmp() function compares not more than n characters.  Because
             strncmp() is designed for comparing strings rather than binary data,
             characters that appear after a ‘\\0’ character are not compared.
            
            ```
            
            RETURN VALUES
            The strcmp() and strncmp() functions return an integer greater than,
            equal to, or less than 0, according as the string s1 is greater than,
            equal to, or less than the string s2.  The comparison is done using
            unsigned characters, so that ‘\200’ is greater than ‘\0’.
            
        - 함수 설명
            
            size n만큼 s1과 s2를 비교한다.
            
            계속 비교하다 만약 차이가 발생하면 s1 - s2 만큼의 값을 리턴한다
            
            ```c
            int	ft_strncmp(const char *s1, const char *s2, size_t n)
            {
            	size_t	i;
            
            	i = 0;
            	while (i < n && s1[i] != '\0')//n만큼 혹은 s1이 그전에 끝날 때 까지 반복
            	{
            		if (s1[i] == s2[i])
            			i++;
            		else
            			return ((unsigned char)s1[i] - (unsigned char)s2[i]);//차이값
            	}
            	if (s1[i] == '\0' && i != n)//만약 s1이 null 조건으로 끝났다면
            		return ((unsigned char)s1[i] - (unsigned char)s2[i]);//차이값
            	return (0);//아니면 같으므로 0
            }
            ```
            
    - ft_strnstr
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             char *
             strstr(const char *haystack, const char *needle);
            
             char *
             strcasestr(const char *haystack, const char *needle);
            
             char *
             strnstr(const char *haystack, const char *needle, size_t len);
            ```
            
            DESCRIPTION
            The strstr() function locates the first occurrence of the null-terminated
            string needle in the null-terminated string haystack.
            
            ```
             The strcasestr() function is similar to strstr(), but ignores the case of
             both strings.
            
             The strnstr() function locates the first occurrence of the null-
             terminated string needle in the string haystack, where not more than len
             characters are searched.  Characters that appear after a ‘\\0’ character
             are not searched.  Since the strnstr() function is a FreeBSD specific
             API, it should only be used when portability is not a concern.
            
             While the strcasestr() function uses the current locale, the
             strcasestr_l() function may be passed a locale directly. See xlocale(3)
             for more information.
            
            ```
            
            RETURN VALUES
            If needle is an empty string, haystack is returned; if needle occurs
            nowhere in haystack, NULL is returned; otherwise a pointer to the first
            character of the first occurrence of needle is returned.
            
        - 함수 설명
            
            len만큼 검사를 하며 haystack에서 needle이 나올 때 까지 검사를 하고, 만약 full needle이 나온다면 그 위치의 주소를 리턴한다.
            
            ```c
            char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
            {
            	size_t	i;
            	size_t	j;
            	char	*haystack_cpy;
            
            	i = 0;
            	haystack_cpy = (char *)haystack;//const를 수정하지 않기 위해 카피 사용
            	if (needle[i] == '\0')
            		return (haystack_cpy);
            	while (i < len && haystack_cpy[i] != '\0')
            	{
            		j = 0;
            		if (haystack_cpy[i] == needle[j])//첫 값이 같을 때 진입
            		{
            			while ((haystack_cpy[i + j] == needle[j])//계속 같은지 확인
            				&& (needle[j] != '\0') && (i + j < len))//needle이 끝나거나 len에 다다르거나
            				j++;
            			if (needle[j] == '\0')//needle이 끝났다면, 다 찾은 것 이므로
            				return (&haystack_cpy[i]);//처음 찾은 값의 주소를 리턴
            		}
            		i++;
            	}
            	return (0);
            }
            ```
            
    - ft_strrchr
        - man page
            
            SYNOPSIS
            #include <string.h>
            
            ```
             char *
             strchr(const char *s, int c);
            
             char *
             strrchr(const char *s, int c);
            ```
            
            DESCRIPTION
            The strchr() function locates the first occurrence of c (converted to
            a char) in the string pointed to by s.  The terminating null
            character is considered to be part of the string; therefore if c is
            ‘\0’, the functions locate the terminating ‘\0’.
            
            ```
             The strrchr() function is identical to strchr(), except it locates
             the last occurrence of c.
            ```
            
            RETURN VALUES
            The functions strchr() and strrchr() return a pointer to the located
            character, or NULL if the character does not appear in the string.
            
        - 함수 설명
            
            str안에서 c가 나올때 까지 검색 후 리턴 BUT 뒤에서부터 검색
            
            ```c
            char	*ft_strrchr(const char *str, int c)
            {
            	int		len;
            	char	*pointer;
            
            	pointer = (char *)str;//const를 건드리지 않기 위하여 복사본 사용
            	len = 0;
            	while (*pointer != '\0')//뒤에서부터 찾기위해 끝으로 보낸다
            	{
            		pointer++;
            		len++;
            	}
            	while (len >= 0)//len만큼 검색하며
            	{
            		if (*pointer == c)
            			return (pointer);
            		else//하나씩 줄여가며 뒤에서부터 검색한다
            		{
            			pointer--;
            			len--;
            		}
            	}
            	return (0);
            }
            ```
            
    - ft_tolower
        - man page
            
            SYNOPSIS
            #include <ctype.h>
            
            ```
             int
             tolower(int c);
            
             #include <ctype.h>
             #include <xlocale.h>
            
             int
             tolower_l(int c, locale_t loc);
            
            ```
            
            DESCRIPTION
            The tolower() function converts an upper-case letter to the corresponding
            lower-case letter.  The argument must be representable as an unsigned
            char or the value of EOF.
            
            ```
             Although the tolower() function uses the current locale, the tolower_l()
             function may be passed a locale directly. See xlocale(3) for more
             information.
            
            ```
            
            RETURN VALUES
            If the argument is an upper-case letter, the tolower() function returns
            the corresponding lower-case letter if there is one; otherwise, the
            argument is returned unchanged.
            
        - 함수 설명
            
            대문자라면 소문자로 변형
            
            ```c
            int	ft_tolower(int c)
            {
            	if (c >= 'A' && c <= 'Z')
            		return (c + 32);
            	else
            		return (c);
            }
            ```
            
    - ft_toupper
        - man page
            
            SYNOPSIS
            #include <ctype.h>
            
            ```
             int
             toupper(int c);
            
             #include <ctype.h>
             #include <xlocale.h>
            
             int
             toupper_l(int c, locale_t loc);
            
            ```
            
            DESCRIPTION
            The toupper() function converts a lower-case letter to the corresponding
            upper-case letter.  The argument must be representable as an unsigned
            char or the value of EOF.
            
            ```
             Although the toupper() function uses the current locale, the toupper_l()
             function may be passed a locale directly. See xlocale(3) for more
             information.
            
            ```
            
            RETURN VALUES
            If the argument is a lower-case letter, the toupper() function returns
            the corresponding upper-case letter if there is one; otherwise, the
            argument is returned unchanged.
            
        - 함수 설명
            
            소문자라면 대문자로 변형
            
            ```c
            int	ft_toupper(int c)
            {
            	if (c >= 'a' && c <= 'z')
            		return (c - 32);
            	else
            		return (c);
            }
            ```
            
    
- Additional functions
    - ft_substr
        - 함수 설명
            
            Allocates (with malloc(3)) and returns a substring from the string ’s’.
            
            The substring begins at index ’start’ and is of maximum size ’len’.
            
        - 코드 설명
            
            len + 1크기만큼의 배열을 할당하여 그 안에 s배열의 start index부터 넣기 시작해서 len크기 까지 혹은 s가 끝날 때 까지 삽입 후 마지막에 null 삽입 후 리턴한다.
            
            ```c
            char	*ft_substr(char const *s, unsigned int start, size_t len)
            {
            	size_t	i;
            	size_t	j;
            	char	*s_cpy;
            
            	i = -1;
            	j = 0;
            	if (!s)//s가 없다면 protection
            		return (NULL);
            	s_cpy = malloc(len + 1);
            	if (!s_cpy)//null guard
            		return (NULL);
            	while (s[++i] != '\0')
            		if (i >= start && j < len)
            			s_cpy[j++] = s[i];
            	s_cpy[j] = '\0';
            	return (s_cpy);
            }
            ```
            
    - ft_strjoin
        - 함수 설명
            
            Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.
            
        - 코드 설명
            
            s1과 s2를 받으며 그 둘을 합친 결과를 새로운 배열을 동적할당하여 리턴
            
            ```c
            char	*ft_strjoin(char const *s1, char const *s2)
            {
            	char	*ret;
            	size_t	len_s1;
            	size_t	len_s2;
            
            	if (!s1 || !s2)
            		return (NULL);
            	len_s1 = ft_strlen((char *)s1);//s1의 size
            	len_s2 = ft_strlen((char *)s2);//s2의 size
            	ret = malloc(sizeof(char) * (len_s1 + len_s2 + 1));//s1+s2+공백 한칸 할당
            	if (!ret)
            		return (NULL);
            	ft_strlcpy(ret, (char *)s1, len_s1 + 1);//s1+공백만큼 할당
            	ft_strlcat(ret, (char *)s2, len_s1 + len_s2 + 1);//s2+공백만큼 붙여넣기
            	return (ret);
            }
            ```
            
    - ft_strtrim
        - 함수 설명
            
            Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.
            
        - 코드 설명
            
            앞뒤로 set(안의 character)이 들어가 있는 부분만 잘라서 중간에 있는 부분만 동적할당하여 리턴, 만약 가득 차있다면 빈 배열을 리턴.
            
            ```c
            char	*ft_strtrim(char const *s1, char const *set)
            {
            	char	*result;
            	size_t	start;
            	size_t	end;
            
            	if (!s1 || !set)//둘중 하나라도 없으면 null
            		return (NULL);
            	start = 0;
            	end = ft_strlen(s1);
            	while (s1[start] != '\0' && ft_strchr(set, s1[start]))//s1[]이 set에 없다면 증가
            		start++;//처음에서부터 set에 들어가는 문자가 있는 위치
            	while (start < end && ft_strchr(set, s1[end]))//s1[]이 set에 없다면 감소
            		end--;//끝에서부터 set에 들어가는 문자가 있는 위치
            	if (start >= end)
            		return (ft_strdup(""));//가득 차있다면 -> 빈공간 리턴
            	result = (char *)malloc(sizeof(char) * (end - start) + 2);//있으니까 동적할당 시작
            	if (result == NULL)
            		return (NULL);
            	ft_strlcpy(result, &s1[start], (end - start) + 2);//start 부터 end까지 + 빈공간 채워넣기
            	return (result);
            }
            ```
            
    - ft_split
        - 함수 설명
            
            Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.  
            
            The array must beended by a NULL pointer.
            
        - 코드 설명
            
            s배열을 캐릭터c로 분할을 해주는 함수.
            
            ```c
            static size_t	wd_cnt(char const *s, char c)//단어의 개수
            {
            	size_t	cnt;
            	size_t	i;
            
            	i = 0;
            	cnt = 0;
            	while (s[i] != '\0')
            	{
            		if (s[i] == c)//캐릭터가 맞으면 그냥 진행
            			i++;
            		else
            		{
            			cnt++;//다른게 나오면 카운트 증가시키고
            			while (s[i] && s[i] != c)//계속 나온다면 카운트 증가시키면 안되므로
            				i++;
            		}
            	}
            	return (cnt);
            }
            
            static size_t	let_cnt(char const *s, char c, size_t now)//단어안에 글자개수
            {
            	size_t	cnt;
            
            	cnt = 0;
            	while (s[now] == c)//처음인 경우에 나오는 c들 skip
            		now++;
            	while (s[now] != c && s[now] != '\0')//다음 c가 나올 때 까지 계산후 return
            	{
            		now++;
            		cnt++;
            	}
            	return (cnt);
            }
            
            static size_t	let_put(char const *s, char c, size_t now, char *ret)
            {
            	size_t	i;
            
            	i = 0;
            	while (s[now] == c)//처음일 경우 c skip
            		now++;
            	while (s[now] != c && s[now] != '\0')//next c 나올 때 까지 ret에 저장
            	{
            		ret[i] = s[now];
            		i++;
            		now++;
            	}
            	ret[i] = '\0';//공백 추가
            	return (now);//리턴
            }
            
            void	free_all(char **ret, size_t j)//중간에 malloc error 시에
            {
            	while (ret[j] != NULL)//이때까지 만들어 뒀던 ret 배열 free
            		free(ret[j++]);
            	free(ret);
            }
            
            char	**ft_split(char const *s, char c)
            {
            	size_t	wd_num;
            	char	**ret;
            	size_t	i;
            	size_t	j;
            
            	i = 0;
            	j = 0;
            	if (s == 0)
            		return (NULL);
            	wd_num = wd_cnt(s, c);
            	ret = malloc(sizeof(char *) * (wd_cnt(s, c) + 1));//단어 수
            	if (!ret)
            		return (NULL);
            	while (wd_num-- > 0)//단어 수 만큼 반복
            	{
            		ret[j] = malloc(sizeof(char) * (let_cnt(s, c, i) + 1));//단어의 글자 개수만큼 동적할당
            		if (!ret[j])//동적할당 실패시
            		{
            			free_all(ret, j);//이때까지 만든 배열들은 free
            			return (ret);
            		}
            		i = let_put(s, c, i, ret[j++]);//대입
            	}
            	ret[wd_cnt(s, c)] = NULL;//마지막에 널 삽입
            	return (ret);//배열 리턴
            }
            ```
            
    - ft_itoa
        - 함수 설명
            
            Allocates (with malloc(3)) and returns a string representing the integer received as an argument.
            
            Negative numbers must be handled.
            
        - 코드 설명
            
            itoa는 int형으로 받은 수를 string으로 변환해서 return
            
            ```c
            static size_t	len_cnt(int num)//int로 받은 수를 string으로 변환시 얼마나 필요할 지
            {
            	size_t		cnt;
            	long long	n;//최대최소 생각안해도 되게 long long 으로 변환
            
            	n = num;
            	cnt = 0;
            	if (n == 0)
            		return (1);
            	else if (n < 0)//음수라면 양수로 바꿔주고 카운트 증가
            	{
            		n *= -1;
            		cnt++;
            	}
            	while (n)//10의자리로 나눠가면서 남아 있다면 카운터 증가
            	{
            		n /= 10;
            		cnt++;
            	}
            	return (cnt);//카운터 크기 리턴
            }
            
            static void	fill_ret(char *ret, int num, size_t len)//채워넣는 과정
            {
            	long long	n;
            
            	n = num;
            	if (n < 0)//음수라면 - 부터 넣기
            	{
            		n *= -1;
            		ret[0] = '-';
            	}
            	if (n >= 10)//10보다 크면 나누고, 나머지부터 반대 순서로 넣는다.
            	{
            		fill_ret(ret, (n / 10), --len);
            		ret[len] = (n % 10) + '0';
            	}
            	else//처음 넣을 수
            		ret[--len] = (n % 10) + '0';
            }
            
            char	*ft_itoa(int n)
            {
            	char	*ret;
            	size_t	wd_len;
            
            	wd_len = len_cnt(n);//배열의 크기 구하고
            	ret = malloc(sizeof(char) * (wd_len + 1));
            	if (!ret)
            		return (NULL);
            	fill_ret(ret, n, wd_len);//채워넣고
            	ret[wd_len] = '\0';//마지막은 null
            	return (ret);
            }
            ```
            
    - ft_strmapi
        - 함수 설명
            
            Applies the function ’f’ to each character of the string ’s’ , and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’.
            
        - 코드 설명
            
            s string에 있는 모든 character 에게 함수 f를 적용시키고 동적할당하여 배열에 저장 후 return
            
            ```c
            char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
            {
            	unsigned int	i;
            	char			*ret;
            
            	if (s == NULL || f == NULL)//둘중 하나라도 없다면 null
            		return (NULL);
            	ret = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
            	if (!ret)
            		return (NULL);
            	i = -1;
            	while (s[++i] != '\0')//s가 끝날 때 까지
            		ret[i] = f(i, s[i]);//s의 모든 character를 f에 적용시키고 결과를 저장
            	ret[i] = '\0';//마지막은 null 넣어서
            	return (ret);//리턴
            }
            ```
            
    - ft_striteri
        - 함수 설명
            
            Applies the function f to each character of the string passed as argument, and passing its index as first argument.  
            
            Each character is passed by address to f to be modified if necessary
            
        - 코드 설명
            
            
            ```c
            void	ft_striteri(char *s, void (*f)(unsigned int, char*))
            {
            	unsigned int	i;
            
            	if (!s || !f)//둘중 하나라도 없다면 바로 끗
            		return ;
            	i = -1;
            	while (s[++i] != '\0')
            		f(i, &s[i]);//s[i]를 f로 하여금 변경 할 수 있게 주소로 전달
            }
            ```
            
    - ft_putchar_fd
        - 함수 설명
            
            Outputs the character ’c’ to the given file descriptor.
            
        - 코드 설명
            
            fd로 전달해 character를 write 할 수 있는 함수
            
            ```c
            void	ft_putchar_fd(char c, int fd)
            {
            	if (fd < 0)//fd가 음수이면 안된다. fd는 무조건 0 이상
            		return ;
            	write(fd, &c, 1);
            }
            ```
            
    - ft_putstr_fd
        - 함수 설명
            
            Outputs the string ’s’ to the given file descriptor.
            
        - 코드 설명
            
            fd로 전달받아 만약 ascii라면 putchar로 전달해 삽입을 한다.
            
            ```c
            void	ft_putstr_fd(char *s, int fd)
            {
            	int	i;
            
            	i = 0;
            	if (fd < 0 || !s)
            		return ;
            	while (s[i] != '\0')
            	{
            		if (ft_isascii(s[i]))//캐릭터가 맞다면
            			ft_putchar_fd(s[i++], fd);//putchar
            		else
            			return ;
            	}
            }
            ```
            
    - ft_putendl_fd
        - 함수 설명
            
            Outputs the string ’s’ to the given file descriptor, followed by a newline.
            
        - 코드 설명
            
            putstr와 유사하지만 마지막에 new line 삽입
            
            ```c
            void	ft_putendl_fd(char *s, int fd)
            {
            	if (fd < 0)
            		return ;
            	ft_putstr_fd(s, fd);
            	ft_putchar_fd('\n', fd);//new line 삽입
            }
            ```
            
    - ft_putnbr_fd
        - 함수 설명
            
            Outputs the integer ’n’ to the given file descriptor.
            
        - 코드 설명
            
            fd에 number로 삽입을 하지만, int형을 char으로 형변환 하는 과정이 필요하다
            
            ```c
            static void	putnb(int n, int fd)//형변환을 하며 한번에 putchar를 해준다
            {
            	if (n >= 10)
            	{
            		putnb(n / 10, fd);
            		ft_putchar_fd('0' + (n % 10), fd);
            	}
            	else
            		ft_putchar_fd('0' + n, fd);
            }
            
            void	ft_putnbr_fd(int n, int fd)
            {
            	if (fd < 0)
            		return ;
            	if (n == -2147483648)//overflow방지로 최소값을 방지
            	{
            		ft_putstr_fd("-2147483648", fd);
            		return ;
            	}
            	else if (n < 0)//음수라면
            	{
            		n *= -1;//양수로 전환
            		ft_putchar_fd('-', fd);//제일 먼저 fd에 - 삽입
            	}
            	putnb(n, fd);//fd에 수 삽입
            }
            ```
            
        
- Bouns functions
    - ft_lstnew
        - 함수 설명
            
            Allocates (with malloc(3)) and returns a new element.  
            
            The variable ’content’ is initialized with the value of the parameter ’content’.  
            
            The variable ’next’ is initialized to NULL.
            
        - 코드 설명
            
            list에서 새로운 노드를 추가하는 함수
            
            ```c
            t_list	*ft_lstnew(void *content)
            {
            	t_list	*map;
            
            	map = (t_list *)malloc(sizeof(t_list));//객체 하나 추가
            	if (!map)//추가 실패 시
            		return (NULL);//리턴 0
            	map -> content = content;//map의 content = (파라미터)content
            	map -> next = NULL;//next는 null
            	return (map);
            }
            ```
            
    - ft_lstadd_front
        - 함수 설명
            
            Adds the element ’new’ at the beginning of the list.
            
        - 코드 설명
            
            첫 리스트에 param의 new를 추가
            
            왜 2중 포인터를 사용했을까?
            
            - 단일 연결리스트에서 삽입과 삭제를 통해 head 포인터값 변화 시킬 수 있음
            - 호출 함수의 포인터변수가 참조하는 객체를 피호출 함수에서 바꾸고 싶을 시 이중포인터 사용
            
            **lst → *lst 의 주소 → lst의 첫번째 주소. (head의 주소)
            
            ```c
            void	ft_lstadd_front(t_list **lst, t_list *new)
            {
            	new -> next = *lst;//new의 다음을 lst의 첫 노드로
            	*lst = new;//lst의 주소 즉 head를 new로 지정.
            }
            ```
            
    - ft_lstsize
        - 함수 설명
            
            Counts the number of elements in a list.
            ``
            
        - 코드 설명
            
            list에 있는 노드의 개수를 리턴
            
            ```c
            int	ft_lstsize(t_list *lst)
            {
            	int	i;
            
            	if (!lst)
            		return (0);
            	i = 0;
            	while (lst)//lst가 존재 할 때까지
            	{
            		lst = lst -> next;//넘어가면서
            		i++;//카운터 증가
            	}
            	return (i);//카운터 리턴
            }
            ```
            
    - ft_lstlast
        - 함수 설명
            
            Returns the last element of the list.
            ``
            
        - 코드 설명
            
            리스트 마지막에 있는 노드를 리턴하는 함수
            
            ```c
            t_list	*ft_lstlast(t_list *lst)
            {
            	if (!lst)//리스트가 존재하지 않는다면 null
            		return (NULL);
            	while (lst -> next)//next가 존재한다면
            		lst = lst->next;//다음으로 지정
            	return (lst);
            }
            ```
            
    - ft_lstadd_back
        - 함수 설명
            
            Adds the element ’new’ at the end of the list.
            ``
            
        - 코드 설명
            
            마지막 노드에 new 노드를 추가
            
            ```c
            void	ft_lstadd_back(t_list **lst, t_list *new)
            {
            	t_list	*curr;//마지막 노드를 가르키게 할 노드
            
            	if (!lst || !new)//둘 중에 하나라도 없다면 return
            		return ;
            	if (*lst == 0)//lst의 헤드가 없다면 빈 리스트 이므로 바로 new를 추가해 준다
            	{
            		*lst = new;
            		return ;
            	}
            	curr = *lst;//
            	while (curr -> next)//마지막 노드를 가리킬 때 까지 보낸다
            	{
            		curr = curr -> next;
            	}
            	curr -> next = new;//마지막이라면 그 다음 next를 new를 가리키게 설정
            }
            ```
            
    - ft_lstdelone
        - 함수 설명
            
            Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element.
            
            The memory of ’next’ must not be freed.
            
        - 코드 설명
            
            
            ```c
            void	ft_lstdelone(t_list *lst, void (*del)(void *))
            {
            	if (!lst || !del)//lst와 del 존재해야된다.
            		return ;
            	del(lst -> content);//content 없애고
            	free(lst);//해당 리스트를 free
            }
            ```
            
    - ft_lstclear
        - 함수 설명
            
            Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3).
            
            Finally, the pointer to the list must be set to NULL.
            
        - 코드 설명
            
            리스트 전부를 del함수를 이용해 없애고, 
            
            ```c
            void	ft_lstclear(t_list **lst, void (*del)(void *))
            {
            	t_list	*map;
            
            	if (!lst)//lst가 존재해야됨
            		return ;
            	map = *lst;//map에다 복사
            	while (*lst)//lst의 주소가 존재 할 때 까지
            	{
            		map = (*lst)->next;//map은 다음 list를 가리킴
            		del((*lst)->content);//현재 list의 content를 지우고
            		free(*lst);//현재 list삭제
            		(*lst) = map;//현재 list의 주소를 다음 list로 설정
            	}
            	*lst = 0;
            }
            ```
            
    - ft_lstiter
        - 함수 설명
            
            Iterates the list ’lst’ and applies the function ’f’ to the content of each element.
            
        - 코드 설명
            
            모든 list에 대하여 f 함수를 적용시킨다.
            
            ```c
            void	ft_lstiter(t_list *lst, void (*f)(void *))
            {
            	if (!lst)//lst가 존재해야됨
            		return ;
            	while (lst)//lst가 존재할 때 까지 
            	{
            		f(lst->content);//lst의 content를 f함수화 시킨다
            		lst = lst->next;//다음 list로 이동
            	}
            }
            ```
            
    - ft_lstmap
        - 함수 설명
            
            Iterates the list ’lst’ and applies the function ’f’ to the content of each element.  Creates a new list resulting of the successive applications of the function ’f’.  
            
            The ’del’ function is used to delete the content of an element if needed.
            
        - 코드 설명
            
            새로운 list를 생성하여, 파라미터로 받은 list에서 모든 content에 함수 f를 적용시켜 적용하되, 만약 실패를 한다면 del함수로 없애고 free 하는 과정을 거쳐야 한다.
            
            ```c
            t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
            {
            	t_list	*result;
            	t_list	*temp;
            
            	if (!lst || !f || !del)
            		return (NULL);
            	result = NULL;
            	while (lst)//lst동안
            	{
            		temp = ft_lstnew((*f)(lst->content));//temp에 f를 반영하여 새로 저장
            		if (!temp)//생성하지 못했다면 del로 clear
            		{
            			ft_lstclear(&result, del);
            			return (NULL);
            		}
            		ft_lstadd_back(&result, temp);//temp를 result의 뒤에 추가
            		temp = temp->next;//temp는 다음을 가리킴
            		lst = lst->next;//list도 다음을 가리킴
            	}
            	return (result);
            }
            ```
            
    
- Makefile
    - Makefile 마스터하기
        
        **Make에서 룰이 실행되는 조건**
        
        1. 타겟 파일이 프로젝트 폴더 안에 없을 때
        2. Prerequisites에 변경점이 발생했을 때
        
        **현재 오브젝트 파일은 없고 코드 파일만 있다고 가정했을때, Make가 어떻게 돌아가는지**
        
        1. `make a.out`을 실행하면, 먼저 prerequisite를 확인합니다.
        2. `file_a.o`를 확인하려 하는데, 현제 폴더에 `file_a.o`가 없습니다.
        3. 만약 prerequisite에 참조되는 파일이 폴더에 없다면, Make는 `file_a.o`를 타겟으로 가진 룰이 있는지 확인하고 있다면 이를 실행합니다.
        4. 타겟이 `%.o`인 룰은 파일이 `.o`로 끝난 모든 파일을 대사으로 하는 **패턴 룰**입니다. `file_a.o`는 이 패턴 룰에 포함되기 때문에 이 룰을 실행합니다. 이때 이 룰의 prerequisite에 `%.c`가 적혀있는데, 이는 실제 사용될 때 `%.o` 에서의 %부분을 가져와 채우게 됩니다. `file_a.o`에서 file_a가 %에서 대체되었기 때문에 prerequisite는 `file_a.c`가 됩니다.
        5. 커멘드 중 `$<`와 `$@`는 Make에서 제공하는 **자동 변수**입니다. `$@`는 타겟을 저장하는 변수이고, `$<`는 첫 prerequisite를 저장하는 변수입니다. 그렇다면 패턴 룰에 있는 커멘드는 `gcc file_a.c -o file_a.o`로 대체되어 실행됩니다.
        6. 이후 `$(OBJ)`의 나머지 값인 `file_b.c`와 `file_c.c`도 2~5번 과정을 거쳐가면서 오브젝트 파일을 만들고, `a.out`을 컴파일하게 됩니다.
        
        참고자료 : [Makefile겉핥기](https://velog.io/@cos/Make-%EA%B2%89-%ED%95%A5%EA%B8%B0) [makefile멍멍멍](https://bowbowbow.tistory.com/12)
        
    
    ```perl
    #FILES에 목적파일로 만든것들 정렬
    FILES		=	ft_strlen \
    				ft_strlcpy \
    				ft_strlcat \
    				ft_strchr \
    				ft_strrchr \
    				ft_strnstr \
    				ft_strncmp \
    				ft_atoi \
    				ft_isalpha \
    				ft_isdigit \
    				ft_isalnum \
    				ft_isascii \
    				ft_isprint \
    				ft_toupper \
    				ft_tolower \
    				ft_memset \
    				ft_bzero \
    				ft_memcpy \
    				ft_memchr \
    				ft_memmove \
    				ft_memcmp \
    				ft_calloc \
    				ft_strdup \
    				ft_substr \
    				ft_strjoin \
    				ft_strtrim \
    				ft_split \
    				ft_itoa \
    				ft_strmapi \
    				ft_striteri \
    				ft_putchar_fd \
    				ft_putstr_fd \
    				ft_putendl_fd \
    				ft_putnbr_fd
    
    #FILES_BONUS에 목적파일로 만든것들 정렬
    FILES_BONUS	=	ft_lstadd_back \
    				ft_lstadd_front \
    				ft_lstclear \
    				ft_lstdelone \
    				ft_lstlast \
    				ft_lstnew \
    				ft_lstsize \
    				ft_lstiter \
    				ft_lstmap
    
    DIR_OBJS	= ./
    
    #addpreffix, suffix에서 './' + FILES + '.o' 로 변경
    OBJS		= $(addprefix $(DIR_OBJS), $(addsuffix .o, $(FILES)))
    OBJS_BONUS	= $(addprefix $(DIR_OBJS), $(addsuffix .o, $(FILES_BONUS)))
    DIR_SRCS	= ./
    
    #마찬가지로 addprefix, suffix에서 './' + FILES + '.c' 로 생성
    SRCS		= $(addprefix $(DIR_SRCS), $(addsuffix .c, $(FILES)))
    SRCS_BONUS	= $(addprefix $(DIR_SRCS), $(addsuffix .c, $(FILES_BONUS)))
    
    # 매크로 정의
    CC			= gcc
    
    #gcc 옵션 flags
    CFLAGS		= -Wall -Wextra -Werror
    
    #library를 이용해 목적함수들을 엮어 libft.a 생성
    AR			= ar crs
    
    #remove
    RM			= rm -f
    
    NAME		= libft.a
    
    # prerequisite시 .o나 .c에 수정사항이 생기면 @에서 타겟을 저장하고 
    # <에서 첫 prerequisite저장된 파일을 넣어 다시 recompile 한다. 
    # -c가 목적파일 생성 후 링크까지 하지 않음
    # 목표로 선언한 .c.o는 .o에 대응하는 .c를 발견하면 해당 command가 수행됩니다. 
    # $<는 확장자를 제외한 파일의 이름과 target(.c.o)의 앞 부분인 .c를 붙여서 사용되며, 
    # 뒤의 $@는 확장자를 제외한 파일의 이름과 target 뒤의 .o를 붙여서 사용됩니다.
    .c.o:		$(SRCS) $(SRCS_BONUS)
    			$(CC) $(CFLAGS) -c -o $@ $<
    
    all:		$(NAME)
    
    #target 후 실행 
    $(NAME):	$(OBJS) #타겟절 -> NAME, 의존성 -> OBJS
    			$(AR) $(NAME) $(OBJS) #명령어
    
    bonus:		$(OBJS_BONUS)
    			$(AR) $(NAME) $(OBJS_BONUS)
    
    clean: 
    			$(RM) $(OBJS) $(OBJS_BONUS)
    
    fclean: 	clean
    			$(RM) $(NAME)
    
    re: 		fclean all
    
    #phony안에 있는 keyword는 존재 시 무시
    .PHONY:		all clean fclean re
    ```
