#include <iostream>
#include <vector>
#include <list>
#include <string>
#define MAXN	10000005
#define MOD		1000000007
#define X		263

//Хеширование цепочками

int hash(std::string s, int m)
{
	int i;
	int s_size;
	long long ret;
	long long monom;

	ret = 0;
	monom = 1;
	i = -1;
	s_size = s.size();
	while (++i < s_size)
	{
		ret = (ret + (s[i] * monom) % MOD) % MOD;
		monom = (monom * X) % MOD;
	}
	return (ret % m);
}



int main() {
	int i;
	int l_sise;
	int n;
	int m;
	int exists;
	std::string command;
	std::string new_name;

	scanf("%d", &m);
	std::vector<std::list<std::string>> v(m);
	scanf("%d", &n);
	while (n-- > 0)
	{
		std::cin >> command;
		if (command == "check")
		{
			std::cin >> i;
			l_sise =v[i].size();
			if (v[i].empty())
				std::cout << "\n";
			else
			{
				for (auto j : v[i])
					std::cout << j << " ";
				std::cout << "\n";
			}

		}
		else
		{
			std::cin >> new_name;
			i = hash(new_name, m);
			if (command == "add")
			{
				exists = 0;
				for (auto j : v[i])
				{
					if (j == new_name)
					{
						exists = 1;
						break ;
					}
				}
				if (!exists)
					v[i].push_front(new_name);
			}
			else if (command == "find")
			{
				exists = 0;
				for (auto j : v[i])
				{
					if (j == new_name)
					{
						exists = 1;
						break ;
					}
				}
				std::cout << (exists ? "yes" : "no") << "\n";
			}
			else if (command == "del")
				v[i].remove(new_name);
		}
	}
	return 0;
}
