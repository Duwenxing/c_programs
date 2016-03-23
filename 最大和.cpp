#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<int>array;
	int n;
	char flag=48;
	while(flag!=10&&flag!=13)
	{
		scanf("%d",&n);
		flag=getchar();
		array.push_back(n);
	}
	int dp[array.size()];
	dp[0]=array[0];
	for(int i=1;i<array.size();i++)
	{
		dp[i]=max(array[i],dp[i-1]+array[i]);
	}
	int k=0;
	for(int i=0;i<array.size();i++)
	{
		if(dp[i]>dp[k])
		{
			k=i;
		}
	}
	printf("%d",dp[k]);
	return 0;
}
