#include <iostream>
#include <vector>
#include <queue>
//Обработка сетевых пакетов

int main() {
	int i;
	int ret;
	int n;
	int size;
	int arrival;
	int duration;
	std::pair<int, int> packet;
	
	std::cin >> size >> n;
//	size = 2; n = 3;
	std::queue <std::pair<int, int>> q;
	std::vector <int> result;

	ret = 0;
	i = 0;
	while (++i <= n)
	{
		std::cin >> arrival >> duration;
//		arrival = (i < 3? 0 : i - 1) ; 
//		duration = (i == 1 ? 2 : 0);
//		arrival = 0; duration = 0;
		if (q.size() < size)
		{
			if (arrival > ret)
				ret = arrival;
			q.push(std::make_pair(ret, duration));
			result.push_back(ret);
			ret += duration;
		}
		else
		{
			packet = q.front();
			if ((packet.first + packet.second) <= arrival)
			{
				if (arrival > ret)
					ret = arrival;
				q.push(std::make_pair(ret, duration));
				result.push_back(ret);
				ret += duration;
				q.pop();
			}
			else
				result.push_back(-1);
		}
	}
	i = -1;
	while (++i < n)
		std::cout << result[i] << "\n";
    return 0;
}