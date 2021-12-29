# get-next-line
function that reads and returns next line

- 의문점
    - OPEN_MAX
        
        u_limit -a 명령어를 통해 한 process 당 file descriptor를 할당 할 수 있는 크기를 보여준다 → 사용 Mac 은 일반적으로 256의 fd를 읽어 올 수 있다
        
        실제 limits.h 에서 OPEN_MAX를 받아오기에, 변경시에 함수에 바로 적용이 된다
        
        [참고](https://pubs.opengroup.org/onlinepubs/009696899/basedefs/limits.h.html)
        
- → GNL 의 main
  - 읽은 txt의 한 줄을 읽어온다

  - 가변의 buffersize를 이용하여, 얼마나 읽을 지 알 수 없고, 다음에 같은 함수를 호출 하였을 때, 읽은 만큼을 처리해 주기 위해 static 변수를 get_next_line 함수에 포함시켜, 다음에 읽을 경우에도 사용 할 수 있게 설정하였다. 

  - 한줄 + buffer size가 커서 더 읽는 만큼을 저장하는 read_line 과 더 읽은 만큼을 잘라주는 extract 함수를 이용하여 구현하였다.

  - bonus같은 경우는 읽는 static인 backup을 2차원 배열로 할당하여, 각 file descriptor 마다 해당하는 backup[fd]에 할당되게 저장을 하였다. OPEN_MAX (from limits.h)로 fd의 크기를 관리하며, 만약 최대 들어 올 수 있는 fd를 넘어가게 된다면 오류라고 판단하였다.
    
   
    ```c
    #include "get_next_line.h"
    
    static char	*read_line(int fd, char *buf, char *backup)
    {
    	int		cnt;
    	char	*tmp;
    
    	cnt = 1;
    	while (cnt)
    	{
    		cnt = read(fd, buf, BUFFER_SIZE);//BUFFSIZE만큼 읽기 시작
    		if (cnt == -1)//읽기 실패
    			return (0);
    		else if (cnt == 0)//다 읽었을 경우 즉 null
    			break ;
    		buf[cnt] = '\0';//string 형으로 치환
    		if (!backup)//처음 읽을 시에 backup이 비어있으므로 배열로 만들어주고
    			backup = ft_strdup("");
    		tmp = backup;//tmp에 일단 저장
    		backup = ft_strjoin(tmp, buf);//읽은것과 backup같은곳에 저장
    		if (!backup)//실패시 널가드
    			return (NULL);
    		free(tmp);//이제 필요없음
    		if (ft_strchr(buf, '\n'))//\n오면 끝내야된다 한줄 읽었으니까
    			break ;
    	}
    	return (backup);
    }
    
    static char	*extract(char *line)
    {
    	int		i;
    	char	*ret;
    
    	i = 0;
    	while (line[i] != '\n' && line[i] != '\0')//\n or null까지 앞으로
    		i++;//그만큼 앞으로 가준다
    	if (line[i] == '\0')//EOF
    		return (0);
    	ret = ft_substr(line, i + 1, ft_strlen(line) - i);//사용한 부분만 잘라서 backup
    	if (!ret)
    		return (NULL);
    	if (ret[0] == '\0')//backup없는경우 -> EOF라고 판단
    	{
    		free(ret);
    		return (NULL);
    	}
    	line[i + 1] = '\0';//\n바로뒤에 null로 잘라준다
    	return (ret);
    }
    
    char	*get_next_line(int fd)
    {
    	char		*line;
    	char		*buf;
    	static char	*backup;
    
    	if (fd < 0 || BUFFER_SIZE <= 0)//읽을 수 없는 예외처리
    		return (0);
    	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    	if (!buf)
    		return (0);
    	line = read_line(fd, buf, backup);
    	free(buf);
    	if (!line)
    		return (NULL);
    	backup = extract(line);
    	return (line);
    }
    ```
    
    
    - → GNL 의 utility
    
    
    ```c
    #include "get_next_line.h"
    
    char	*ft_substr(char const *s, unsigned int start, size_t len)//s의 배열을 start부터 자르기 시작해서 len만큼 잘라서 return
    {
    	size_t	i;
    	size_t	j;
    	char	*s_cpy;
    
    	i = -1;
    	j = 0;
    	if (!s)
    		return (NULL);
    	s_cpy = malloc(len + 1);
    	if (!s_cpy)
    		return (NULL);
    	while (s[++i] != '\0')
    		if (i >= start && j < len)
    			s_cpy[j++] = s[i];
    	s_cpy[j] = '\0';
    	return (s_cpy);
    }
    
    int	ft_strlen(const char *str)//배열의 크기
    {
    	int	i;
    
    	i = 0;
    	while (str[i] != '\0')
    		i++;
    	return (i);
    }
    
    char	*ft_strchr(const char *str, int c)//string에서 c의 위치를 반납 -> 없다며 0
    {
    	char	*pointer;
    
    	pointer = (char *)str;
    	while (*pointer)
    	{
    		if (*pointer == c)
    			return (pointer);
    		else
    			pointer++;
    	}
    	if (*pointer == c)
    		return (pointer);
    	return (0);
    }
    
    char	*ft_strdup(const char *s1)//s1고 동일한 배열을 할당 후 반납
    {
    	int		len_s1;
    	char	*ret;
    	int		i;
    
    	len_s1 = 0;
    	i = 0;
    	while (s1[i++] != '\0')
    		len_s1++;
    	ret = malloc(sizeof(char) * (len_s1 + 1));
    	if (!ret)
    		return (NULL);
    	i = 0;
    	while (i < len_s1)
    	{
    		ret[i] = s1[i];
    		i++;
    	}
    	ret[i] = '\0';
    	return (ret);
    }
    
    char	*ft_strjoin(char const *s1, char const *s2)//s1과 s2를 합친 후 그 배열을 반납
    {
    	int		i;
    	int		j;
    	char	*str;
    
    	i = 0;
    	j = 0;
    	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    	if (!str)
    		return (NULL);
    	while (s1[i] != '\0')
    	{
    		str[i] = s1[i];
    		i++;
    	}
    	while (s2[j] != '\0')
    	{
    		str[i + j] = s2[j];
    		j++;
    	}
    	str[i + j] = '\0';
    	return (str);
    }
    ```
    
    
    
    
    
