#include <iostream>
#include <stack>
#define MAXN	100001
//Расстановка скобок в коде

int main() {
    char s[MAXN];
	int i;
	std::stack <char> brascets;
	int ret;
	
	std::cin >> s;
	ret = 0;
	i = -1;
	while (s[++i])
	{
		if ('{' == s[i] || '[' == s[i] || '(' == s[i])
			brascets.push(s[i]);
		else if ('}' == s[i] || ']' == s[i] || ')' == s[i])
		{
			if (brascets.empty())
			{
				ret = 0;
				break ;
			}
		}
	}

	
	// put your code here
    return 0;
}