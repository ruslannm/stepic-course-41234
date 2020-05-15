#include <iostream>
#include <vector>
#include <queue>
//Высота дерева

int main() {
	int i;
	int ret;
	int n;
	int start;
	int v;
	int level;
	int level_max;
	
	std::cin >> n;
	std::vector <std::vector <int> > graf(n + 1);
	i = -1;
	while (++i < n)
	{
		std::cin >> ret;
		if (-1 == ret)
			start = i;
		else
			graf[ret].push_back(i);
	}
	std::queue <int> q;
	std::vector <int> used(n, 0);
	level = 1;
	level_max = 1;
	used[start] = level;
	q.push(start);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (auto u: graf[v])
		{
			if (used[u])
				continue ;
			used[u] = used[v] + 1;
			if (used[u] > level_max)
				level_max = used[u];
			q.push(u);
		}
	}
	std::cout << level_max;
    return 0;
}