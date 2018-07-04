#include <emscripten.h>
#include <string.h>
#include <stdlib.h>

int EMSCRIPTEN_KEEPALIVE fibo(int n)
{
  int first = 0, second = 1;

  int tmp;
  while (n--) {
    tmp = first+second;
    first = second;
    second = tmp;
  }

  return first;
}

char* EMSCRIPTEN_KEEPALIVE play_with_memory()
{
	char* str = malloc(2);
	str[0] = 'a';
	str[1] = '\0';
	for (size_t i = 0; i < 10000000; i++)
	{
		str = realloc(str, strlen(str) + 1);
		str[strlen(str) - 1] = (i % 128) + '0';
		str[strlen(str)] = '\0';
	}
	return str;
}

/*int EMSCRIPTEN_KEEPALIVE ackermann(int m, int n)
{
    std::stack<int> s;
    s.push(m);
    while (!s.empty()) {
	m = s.top();
	s.pop();
	if (m == 0 || n == 0)
		n += m + 1;
        else {
		s.push(m - 1);
	        s.push(m);
                n--;
        }
    }
    return n;
}*/
