#include<cstdio>
int main()
{
	int a[110];
	int n,m,count=0;
	scanf("%d%d",&n,&m);
	m=m%n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n-m;i<n;i++)//先输出后m位
	{
		printf("%d",a[i]);
		count++;
		if(count<n) printf(" ");
	}
	for(int i=0;i<n-m;i++)//再输出前n-m位
	{
		printf("%d",a[i]);
		count++;
		if(count<n) printf(" ");
	}
	return 0;
}
