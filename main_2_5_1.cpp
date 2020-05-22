#include <iostream>
#include <vector>
#include <string>
#define MAXN 10000005
//Телефонная книга

int main() {
	int i;
	int n;
	std::string command;
	std::string new_name;

	std::vector<int> phone(MAXN, 0);
	std::vector<std::string> name(MAXN);
	scanf("%d", &n);
	std::vector<std::string> result;
	while (n-- > 0)
	{
		std::cin >> command >> i;
		if (command == "add")
		{
			std::cin >> new_name;
			if (!phone[i])
				phone[i] = 1;
			name[i] = new_name;
		}
		else if (command == "del")
			phone[i] = 0;
		else
		{
			 if (phone[i])
				result.push_back(name[i]);
			else
				result.push_back("not found");
		}
	}
    n = result.size();
	i = -1;
	while (++i < n)
		std::cout << result[i] << "\n";
	return 0;
}
