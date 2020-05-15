#include <iostream>
#include <vector>
#include <stack>
#include <string>
//Стек с поддержкой максимума

int main() {
	int i;
	int ret;
	int n;
	int value;
	int tmp;
	std::string command;
	
	std::cin >> n;
	std::vector <int> result;
	std::stack <int> stack_tmp;
	std::stack <int> max;
	i = 0;
	while (++i <= n)
	{
		std::cin >> command;
		if (command == "push")
		{
			std::cin >> value;
			stack_tmp.push(value);
			if (!max.empty())
			{
				tmp = max.top(); 
				if (value < tmp)
					value = tmp;
			}
			max.push(value);
		}
		else if (command == "pop")
		{
			stack_tmp.pop();
			max.pop();
		}
		else
		{
			tmp = max.top();
			result.push_back(tmp);
		}
	}
	tmp = result.size();
	i = -1;
	while (++i < tmp)
		std::cout << result[i] << "\n";
    return 0;
}