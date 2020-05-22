#include <stdio.h>
#define MAXN 100005
//Автоматический анализ программ

int a[MAXN];

int find_i(int i)
{
	int tmp;

	if (i != a[i])
	{
		tmp = find_i(a[i]);
		a[i] = tmp;
	}
	return a[i];
}

int main() {
	int i;
	int n;
	int e;
	int d;
	int dst;
	int src;
	int d_p;
	int s_p;

	scanf("%d %d %d", &n, &e, &d);
//	n = 6; e = 5; d = 3;
	i = 0;
	while (++i <= n)
		a[i] = i;
//	int te[5][2] = {{2,3},{1,5},{2,5},{3,4},{4,2}};
//	int td[3][2] = {{6,1},{4,6},{4,5}};
	i = -1;
	while (++i < e)
	{
		scanf("%d %d", &dst, &src);
		//dst = te[i][0]; src = te[i][1];
		if (dst == src)
			continue ;
		d_p = find_i(dst);
		s_p = find_i(src);
		if (d_p == s_p)
			continue ;
		a[s_p] = d_p;
	}
	i = -1;
	while (++i < d)
	{
		scanf("%d %d", &dst, &src);
//		dst = td[i][0]; src = td[i][1];
		if (dst == src)
		{
			printf("0\n");
			return 0;
		}
		d_p = find_i(dst);
		s_p = find_i(src);
		if (d_p == s_p)
		{
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");
    return 0;
}
