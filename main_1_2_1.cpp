#include <iostream>
#include <stack>
#include <string>
#include <string.h>
#define MAXN	10001
//Расстановка скобок в коде

int main() {
    char s1[MAXN];
	std::string s;
	int i;
	std::stack <std::pair <char, int>> brascets;
	int ret;
	std::pair<char, int> top;
	
	std::getline(std::cin, s);
//	ret = str.length();
//		strcpy(s, str.c_str());
	ret = 0;
	i = -1;
	while (s[++i])
	{
		if ('{' == s[i] || '[' == s[i] || '(' == s[i])
			brascets.push(std::make_pair(s[i], i));
		else if ('}' == s[i] || ']' == s[i] || ')' == s[i])
		{
			if (brascets.empty())
			{
				std::cout << i + 1 << "\n";
				return 0;
			}
			top = brascets.top();
			brascets.pop();
			if (('}' == s[i] && '{' != top.first) || (']' == s[i] && '[' != top.first) || (')' == s[i] && '(' != top.first))
			{
				ret = i;
				break ;
			}
		}
	}
	if (brascets.empty() && 0 == ret)
		std::cout << "Success\n";
	else if (ret)
		std::cout << ret + 1 << "\n";
	else 
	{
		while (!brascets.empty())
		{
			top = brascets.top();
			brascets.pop();
		}
		std::cout << top.second + 1 << "\n";
	}
    return 0;
}