#include <cstdio>

int n, m, k;
long long a[4000001];

void update(int n,int s,int e,int p,long long v)
{
	if (s > p || e < p) return;
	else if (s == e) a[n] = v;
	else
	{
		update(n * 2,s,(s+e)/2, p, v);
		update(n * 2+1,(s+e)/2+1,e, p, v);
		a[n] = a[n * 2] + a[n * 2 + 1];
	}
}
long long sum(int n, int s, int e, int l, int r)
{
	if (s > r || e < l) return 0;
	else if (l <= s && e <= r) return a[n];
	else return sum(n * 2, s, (s+e)/2, l, r) + sum(n * 2 + 1, (s+e)/2+1, e, l, r);
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i = 1;i <= n;i++)
	{
		long long x;
		scanf("%lld",&x);
		update(1, 1, n, i, x);
	}
	for (int i = 0;i < m + k;i++)
	{
		long long q, x, y;
		scanf("%lld %lld %lld",&q,&x,&y);
		if (q == 1) update(1, 1, n, x, y);
		else printf("%lld\n",sum(1,1,n,x,y));
	}
	return 0;
}