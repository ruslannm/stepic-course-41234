#include <stdio.h>
#define MAXN 100005
//Параллельная обработка

int main() {
	int i;
	int j;
	int n;
	int m;
	long tmp[2];
	int l;
	int r;
	int a_max;
	long a[MAXN][2];
	long result[MAXN][2];
	int t;
	
	scanf("%d %d", &n, &m);
//	n = 4; m = 20;
	i = -1;
	while (++i < n)
	{
		a[i][0] = i;
		a[i][1] = 0;
	}
	i = -1;
	while (++i < m)
	{
		scanf("%d", &t);
//		t = 1;
		result[i][0] = a[0][0];
		result[i][1] = a[0][1];
		if (0 == t)
			continue ;
		a[0][1] += t;
		j = 0;
		while (j < n)
		{
			a_max = j;
			l = 2 * j  + 1;
			if (l < n)
			{ 
				if (a[l][1] < a[a_max][1])
					a_max = l;
				else if (a[l][1] == a[a_max][1] && a[l][0] < a[a_max][0])
					a_max = l;
			}
			r = 2 * j  + 2;
			if (r < n)
			{ 
				if (a[r][1] < a[a_max][1])
					a_max = r;
				else if (a[r][1] == a[a_max][1] && a[r][0] < a[a_max][0])
					a_max = r;
			}
			if (j != a_max)
			{
				tmp[0] = a[a_max][0];
				tmp[1] = a[a_max][1];
				a[a_max][0] = a[j][0];
				a[a_max][1] = a[j][1];
				a[j][0] = tmp[0];
				a[j][1] = tmp[1];
				j = a_max;
			}
			else
				j = n;
		}
	}
	i = -1;
	while (++i < m)
		printf("%ld %ld\n", result[i][0], result[i][1]);
    return 0;
}