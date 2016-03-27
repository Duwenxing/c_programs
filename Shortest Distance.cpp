#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int dis[N],a[N];//a[i]存放i到i+1号顶点的距离
int main()
{
	int n,left,right;
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];//累加sum
		dis[i]=sum;//预处理dis数组
	}
	int query;//query个查询
	scanf("%d",&query);
	for(int i=0;i<query;i++)
	{
		scanf("%d%d",&left,&right);
		if(left>right) swap(left,right);
		int temp=dis[right-1]-dis[left-1];
		printf("%d\n",min(temp,sum-temp));
	}
	return 0;
	
}
