#include <iostream>
#include <vector>
#include <deque>
//Максимум в скользящем окне

int main() {
	int i;
	int ret;
	int n;
	int m;
	int tmp;
	
//	std::cin >> n;
	n = 8;
	std::vector <int> a(n);
	std::deque<int> q;
/*	i = -1;
	while (++i < n)
		std::cin >> a[i];
	std::cin >> m;
*/
	a[0] = 2;
	a[1] = 7;
	a[2] = 3;
	a[3] = 1;
	a[4] = 5;
	a[5] = 2;
	a[6] = 6;
	a[7] = 2;
	m = 4;

	std::vector <int> result(n - m + 1);
	i = -1;
	while (++i < n)
	{
		if (0 == i)
			q.push_back(i);
		if (q[0] < i - m + 1)
		{
			q.pop_front();
			q.push_back(i);
		}
		if (a[i] == a[q[0]])
			q[0] = i;
		else if (a[i] > a[q[0]])
		{
			q.clear();
			q.push_back(i);
		}
		else 
		{
			while (a[q.back()] <= a[i])
				q.pop_back();
			q.push_back(i);
		}
		if (i + 1 >= m)
			result[i + 1 - m] = a[q[0]];
	}
	tmp = result.size();
	i = -1;
	while (++i < tmp)
		std::cout << result[i] << " ";
    return 0;
}