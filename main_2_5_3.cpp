#include <iostream>
#include <vector>
#include <string>
#define MOD		1000000007
#define X		263

//Поиск образца в тексте

long long hash(std::string s, int start, int length, std::vector<long long> pow)
{
	long long ret;
	int i;

	ret = 0;
	i = 0;
	while (i < length)
	{
		ret = (ret + (s[start + i] * pow[i]) % MOD) % MOD;
		i++;
	}
	return (ret);
}

int str_equal(std::string text, int start, int length, std::string pattern)
{
	int i;

	i = 0;
	while (start + i < length)
	{
		if (text[start + i] != pattern[i])
			return 0;
		i++;
	}
	return 1;
}

int main() {
	int i;
	int p;
	int t;
	long long h_p;
	std::string pattern;
	std::string text;

	//std::cin >> pattern;
	//std::cin >> text;
	pattern = "Test";
	text = "testTesttesT";
	p = pattern.size();
	t = text.size();
	std::vector<long long> pow(p);
	i = 0;
	pow[i] = 1;
	while (++i < p)
		pow[i] = (pow[i - 1] * X) % MOD;
	std::vector<long long> h_map(t - p + 1);
	std::vector<int> result;
	h_p = hash(pattern, 0, p, pow);
	i = t - p;
	h_map[i] = hash(text, i, p, pow);
	if (h_p == h_map[i])
	{
		if (str_equal(text, i, p, pattern))
			result.push_back(i);
	}
	while (--i >= 0)
	{
		h_map[i] = ((((h_map[i + 1] - (text[i + p] * pow[p - 1]) % MOD + MOD) % MOD) * X) % MOD + text[i]) % MOD;
		if (h_p == h_map[i])
		{
			if (str_equal(text, i, p, pattern))
				result.push_back(i);
		}
	}
	i = result.size();
	while (--i >= 0)
		printf("%d ", result[i]);
	return 0;
}
