#include <stdio.h>
#define MAXN 10005
//Построение кучи

int main() {
	int i;
	int j;
	int n;
	int tmp;
	int l;
	int r;
	int i_max;
	int i_result;
	int result[MAXN][2];
	int a[MAXN];
	
	scanf("%d", &n);
//	n = 6;
	i = -1;
	while (++i < n)
		scanf("%d", &a[i]);
///7 6 5 4 3 2
/*	a[0] = 7;
	a[1] = 6;
	a[2] = 5;
	a[3] = 4;
	a[4] = 3;
	a[5] = 2;
*/
	i_result = 0;
	i = n / 2;
	while (--i >= 0)
	{
		j = i;
		while (j < n)
		{
			i_max= j;
			l = 2 * j  + 1;
			if (l < n && a[l] < a[i_max])
				i_max = l;
			r = 2 * j  + 2;
			if (r < n && a[r] < a[i_max])
				i_max = r;
			if (j != i_max)
			{
				result[i_result][0] = j;
				result[i_result++][1] = i_max;
				tmp = a[i_max];
				a[i_max] = a[j];
				a[j] = tmp;
				j = i_max;
			}
			else
				++j;
		}
	}
//	tmp = result.size();
	printf("%d\n", i_result);
	i = -1;
	while (++i < i_result)
		printf("%d %d\n", result[i][0], result[i][1]);
    return 0;
}