#include <stdio.h>
#define MAXN 6 //100005
//Объединение таблиц

long a[MAXN][2];

long find_i(int i)
{
	long tmp;

	if (i != a[i][0])
	{
		tmp = find_i(a[i][0]);
		a[i][0] = tmp;
	}
	return a[i][0];
}

int main() {
	int i;
	int n;
	int m;
	long a_max;
	long result[MAXN];
	int d;
	int s;
	int d_p;
	int s_p;


//	scanf("%d %d", &n, &m);
	n = 5; m = 5;
/*	a[0][1] = 10;
	a[1][1] = 0;
	a[2][1] = 5;
	a[3][1] = 0;
	a[4][1] = 3;
	a[5][1] = 3;
*/
	int dest[6][2];
	dest[0][0] = 3; dest[0][1] = 5;
	dest[1][0] = 2; dest[1][1] = 4;
	dest[2][0] = 1; dest[2][1] = 4;
	dest[3][0] = 5; dest[3][1] = 4;
	dest[4][0] = 5; dest[4][1] = 3;

	a_max = 0;
	result[0] = 0;
	i = -1;
	while (++i < n)
	{
		a[i][0] = i;
//		scanf("%ld", &a[i][1]);
		a[i][1] = 1;
		if (a[i][1] > result[0])
		{
			a_max = i;
			result[0] = a[i][1];
		}
	}
	i = -1;
	while (++i < m)
	{
//		scanf("%d %d", &d, &s);
		d=dest[i][0];s=dest[i][1];
		result[i + 1] = result[i];
		if (d == s)
			continue ;
		d_p = find_i(d - 1);
		s_p = find_i(s - 1);
		if (d_p == s_p)
			continue ;
		a[d_p][1] = a[d_p][1] + a[s_p][1];
		a[s_p][0] = d_p;
		if (a[d_p][1] > result[i])
		{
			a_max = d_p;
			result[i + 1] = a[d_p][1];
		}
	}
	i = 0;
	while (++i <= m)
		printf("%ld\n", result[i]);
    return 0;
}