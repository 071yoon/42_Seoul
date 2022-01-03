- Value Argument란
    
    가변인자란 무엇인가.
    
    printf함수 같은 경우에 사용하면 고정된 인자값이 들어가는 것이 아닌 여러 인자값이 동시에 들어가게 된다. 
    
    ex) printf(”hello I am %s and I am %d years old”, name, year); → 3개의 인자값
    
    이러한 상태에서 가변인자를 사용하여 쉽게 해결 할 수 있다
    
    간단한 가변인수의 사용 예시
    
    ```c
    #include <stdio.h>
    #include <stdarg.h>
    
    int main(){
    	int a = 1, b = 2, c = 3, d = 4;
    	printf("%d\n", sum(5, a, b, c, d);
    	return (0);
    }
    
    int sum(int num_args, ...){//...가 뒤에 얼마나 오던지 받겠다 (num_args -> 가변인수 개수)
    	va_list ap;//va_list란 list type을 사용한다 -> 가변인수를 저장하는 스택 주소 포인터
    	va_start (ap, num_args);//ap가 맨 처음 가변인수를 가리킨다
    	int arg = 0;
    	int result = 0;
    	for (int i = 0; i < num_args, i++){
    		arg = va_arg(ap, int);//반복문을 돌아가며 인자값을 하나씩 받아간다 list로
    		result += arg;
    	}
    	va_end(ap);//가변인자 사용 끗!!
    	return (result);
    }
    ```
    
    - <stdarg.h> : 헤더파일에 매크로를 사용하여 가변인자를 사용
    - va_list : 가변인자목록을 선언하는 typedef → 가변인자들의 메모리 주소를 저장
    - va_start(ap, param) : 가변 인자를 가져 올 수 있게 처음 설정
    - va_arg(ap, type) → type의 크기만큼 역참조 해서 값을 가져 올 수 있다
    - va_end(ap) : 가변인자의 포인터를 null로 초기화
    
- Test Case
    - **십진수로 출력: %d → int**
    - **부호있는 십진수로 출력: %i → int**
    - **부호없는 십진수로 출력: %u → unsigned int**
    - **부호없는 16진수로 출력(소문자): %x → unsigned int as heximal(lower case)**
    - **부호없는 16진수로 출력(대문자): %X → unsigned int as heximal(capital)**
    - **문자 출력: %c → char**
    - **문자열 출력: %s → null terminating string**
    - **메모리 주소 출력: %p → void* in implementation-defined format**
- uintptr이란?
    
    포인터의 비트 패턴을 할당할만한 크기의 자료형
    
    주로 **포인터의 주소를 할당할 때 사용**
    
- 16진수 변환시 주의사항
    
    16진수는 unsigned int로 받기때문에 만약 -값이 나오면 오버플로가 일어난다고 치고 해당 값을 리턴한다
    
    예를 보고 이해해보자
    
    ```c
    i = -1;
      printf("%X\n", i);
      // 출력 결과: FFFFFFFF
    
    i = -2;
      printf("%X\n", i);
      // 출력 결과: FFFFFFFE
    
    ui = 4294967295; // unsigned int의 최대값
      printf("%X\n", ui);
      // 출력 결과: FFFFFFFF
    
    i = 2147483647; // int 의 최대값
      printf("%X\n", i);
      // 출력 결과: 7FFFFFFF
    ```
    
- arg_char 에서 int형으로 읽는 이유?
    
    Because that's what the standard says. If you pass an integral value with conversion rank smaller than that of `int` (e. g. `char`, `bool` or `short`) to a function taking a variable number of arguments, it will be converted to `int`. Presumably the reason for this has its roots in performance, where it was (and in fact, often it still is nowadays) better to pass values aligned to a machine word boundary.
    
    code example attempts to read a variadic argument of type `unsigned char` with `va_arg()`. However, when a value of type `unsigned char` is passed to a variadic function, the value undergoes default argument promotions, resulting in a value of type `int` being passed.
    
    example:
    
    ```c
    #include <stdarg.h>
    #include <stddef.h>
     
    void func(size_t num_vargs, ...) {
      va_list ap; 
      va_start(ap, num_vargs);
      if (num_vargs > 0) {
        unsigned char c = va_arg(ap, unsigned char);
        // ...
      }
      va_end(ap);
    }
      
    void f(void) {
      unsigned char c = 0x12;
      func(1, c);
    }
    ```
    
- Apple Silicon M1에서의 문제점
    
    이상하게 M1칩에서는 value argument에 문제가 있다.
    
    일반적으로 구조체로 선언되어, 안에서 linked list node처럼 알아서 다음 인자를 가르키도록 설계되어 va_list ap로 부르고, va_arg(ap, int)처럼 사용을 하게 되면, 알아서 다음 인자를 가르킨다고 보았지만, M1에서는 다른 컴파일러를 사용해서 그런지 자동으로 가리키지 않았다.
    
    어쩔 수 없이 다른 해결법을 찾아보았고, 생각보다 어렵지 않았다. va_list ap를 콜 하고 그 다음 va_arg로 넘겨줄 때에, 그냥 ap값이 아닌 주소값을 보내어 주소값을 수정하게하면 정상적으로 다음 인자를 가르킨다
    
    m1맥에서는 잘 돌아가지만, 같은 코드를 catalina 로 실행 하였을 때 정상적으로 작동 할 지는 모르겠다
    
- 코드 설명
    - ft_printf
        
        ```c
        int	ft_printf(const char *str, ...)
        {
        	va_list	ap;
        	int		ret;
        	int		i;
        
        	va_start(ap, str);
        	i = 0;
        	ret = 0;
        	while (str[i] != '\0')//처음받은 인자를 끝까지 수행
        	{
        		if (str[i] != '%')//%가 아니면 그냥 쓰고 넘어가면 된다
        			ret += write(1, &str[i++], 1);
        		else//%가 나왔다면 이제 어떤건지 알아가야됨
        		{
        			i++;//%다음 character까지 생각해서
        			ret += deal_format(&ap, str[i++]);
        		}
        	}
        	va_end(ap);
        	return (ret);
        }
        ```
        
    - deal_format
        
        ```c
        //Test case에서 서술한 대로 character마다 다른 형태로 수행
        int	deal_format(va_list *ap, char c)
        {
        	int	ret;
        
        	if (c == 'd' || c == 'i')
        		ret = int_form(ap);
        	else if (c == 'u')
        		ret = uns_int_form(ap);
        	else if (c == 'x')
        		ret = small_x_form(ap);
        	else if (c == 'X')
        		ret = big_x_form(ap);
        	else if (c == 'c')
        		ret = char_form(ap);
        	else if (c == 's')
        		ret = str_form(ap);
        	else if (c == 'p')
        		ret = ptr_form(ap);
        	else if (c == '%')//%다음 %가 나오면 그냥 쓰고 넘어가면 된다
        	{
        		write(1, "%", 1);
        		ret = 1;
        	}
        	else
        		return (0);
        	return (ret);//내가 현재 쓴만큼 크기를 return
        }
        ```
        
    - int
        
        ```c
        int	int_form(va_list *ap)
        {
        	int	arg_int;
        	int	ret;
        
        	arg_int = (int)va_arg(*ap, int);//int만큼 읽어보고
        	ft_putnbr_fd(arg_int, 1);//그만큼 일단 쓰고 보자
        	ret = 0;
        	if (arg_int == 0)//0이면 그냥 하나 리턴해주면 된다
        		ret += 1;
        	else if (arg_int < 0)//음수면 * -1 해주고 갯수 count
        	{
        		arg_int *= -1;
        /* 여기서 어??? overflow가 일어나면 어떡하지?? 란 상상을 할 수도 있지만, 의미가 없다
        왜냐하면, 어차피 ft_putnbr_fd에서도 overflow된 만큼 int로 치환을 해서 output을 냈을테니
        여기서도 int 로 바꾼만큼 어차피 바꿔서 출력할 테니 개수는 위에서 write한 만큼 나올것 */
        		ret += 1;
        	}
        	while (arg_int)//10씩 나눠가면서 몫의 개수 -> 출력하는 개수
        	{
        		arg_int /= 10;
        		ret++;
        	}
        	return (ret);
        }
        
        int	uns_int_form(va_list *ap)//unsigned int형 -> 형변환을 제외하고는 동일
        {
        	unsigned int	arg_int;
        	int				ret;
        
        	arg_int = (unsigned int)va_arg(*ap, int);
        	ft_un_putnbr_fd(arg_int, 1);
        	ret = 0;
        	if (arg_int == 0)
        		ret += 1;
        	else if (arg_int < 0)
        	{
        		arg_int *= -1;
        		ret += 1;
        	}
        	while (arg_int)
        	{
        		arg_int /= 10;
        		ret++;
        	}
        	return (ret);
        }
        
        void	un_putnb(unsigned int n, int fd)//unsigned 형태의 putnb
        {
        	if (n >= 10)
        	{
        		un_putnb(n / 10, fd);
        		ft_putchar_fd('0' + (n % 10), fd);
        	}
        	else
        		ft_putchar_fd('0' + n, fd);
        }
        
        void	ft_un_putnbr_fd(unsigned int n, int fd)//unsigned 형태의 putnbr
        {
        	if (fd < 0)
        		return ;
        	un_putnb(n, fd);
        }
        ```
        
    - hex
        
        ```c
        int	small_x_form(va_list *ap)
        {
        	int				len;
        	unsigned int	arg_x;
        //16진수 형태로 전달하므로 unsigned int형태로 받아주어야 변환이 가능하다
        
        	arg_x = (unsigned int)va_arg(*ap, int);
        	len = ft_puthex_fd(arg_x, 0, 1);
        	return (len);
        }
        
        int	big_x_form(va_list *ap)
        {
        	int				len;
        	unsigned int	arg_x;
        
        	arg_x = (unsigned int)va_arg(*ap, int);
        	len = ft_puthex_fd(arg_x, 1, 1);
        	return (len);
        }
        
        int	ft_puthex_fd(unsigned int nbr, int if_capital, int fd)
        {//if_captial에서 대문자로 처리할 지 소문자로 처리할 지 check
        	int	ret;
        
        	ret = 0;
        	if (nbr >= 16)
        		ret += ft_puthex_fd(nbr / 16, if_capital, fd);
        	if (if_capital)
        	{
        		ft_putchar_fd("0123456789ABCDEF"[nbr % 16], fd);//한글자씩 나머지값으로 읽음
        		ret++;
        	}
        	else
        	{
        		ft_putchar_fd("0123456789abcdef"[nbr % 16], fd);
        		ret++;
        	}
        	return (ret);
        }
        ```
        
    - char/str
        
        ```c
        int	char_form(va_list *ap)//그냥 하나씩 읽으면 된다
        {
        	int	arg_char;
        	int	ret;
        
        	arg_char = (char)va_arg(*ap, int);//int형으로 읽음에 주의
        	write(1, &arg_char, 1);
        	ret = 1;
        	return (ret);
        }
        
        int	str_form(va_list *ap)
        {
        	char	*str;
        	int		ret;
        
        	str = (char *)va_arg(*ap, char *);//동적할당 아님!! ->주소값 pass
        	ret = 0;
        	if (str == NULL)
        	{
        		ft_putstr_fd("(null)", 1);//아무것도 없으면 6자리로 null 보내줌
        		return (6);
        	}
        	while (str[ret])
        	{
        		ft_putchar_fd(str[ret], 1);//하나씩 읽으면서 읽을 때 마다 +1
        		ret++;
        	}
        	return (ret);
        }
        ```
        
    - ptr
        
        ```c
        int	ptr_form(va_list *ap)
        {
        	int			len;
        	uintptr_t	ptr;
        
        	len = 0;
        	ptr = (uintptr_t)va_arg(*ap, void *);//unitptr꼴로 읽어준다
        	write(1, "0x", 2);
        	len += 2;//주소값은 16진수로 0x로 시작함에 주의
        	if (ptr == 0)
        	{
        		ft_putchar_fd('0', 1);//아무것도 없으면 그냥 0x0
        		len++;
        	}
        	else
        		len += ft_put_ptr(ptr);
        	return (len);
        }
        
        int	ft_put_ptr(uintptr_t nbr)
        {
        	int	ret;
        
        	ret = 0;
        	if (nbr >= 16)
        	{
        		ret += ft_put_ptr (nbr / 16);
        		ret += ft_put_ptr (nbr % 16);
        	}
        	else
        	{
        		ft_putchar_fd("0123456789abcdef"[nbr % 16], 1);//16진수 치환과 동일
        		ret++;
        	}
        	return (ret);
        }
        ```
