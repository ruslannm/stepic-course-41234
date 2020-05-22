#include <iostream>
#include <vector>
#include <list>
#include <string>
#define MAXN	10000005
#define MOD		1000000007
#define X		263

//Поиск образца в тексте

int hash(std::string s, int start, int length, std::vector<int> pow)
{
	int i;
	long long ret;
	long long monom;

	ret = 0;

	while (start < length)
	{
		ret = (ret + (s[start++] * monom) % MOD) % MOD;
		monom = (monom * X) % MOD;
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
	}
	return 1;
}

int main() {
	int i;
	int l_sise;
	int n;
	int m;
	int exists;
	int p;
	int t;
	int h_p;
	int t;
	std::string pattern;
	std::string text;

	std::cin >> pattern;
	std::cin >> text;
	p = pattern.size();
	t = text.size();
	std::vector<int> pow(p);
	i = 0;
	pow[i] = 1;
	while (++i < p)
		pow[i] = (pow[i - 1] * X) % MOD;
	std::vector<int> h_map(t - p + 1);
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


	}
	return 0;
}
