#include<cstdio>
const int N=55;//排数 
int start[N],end[N],next[N];//next数组存放每个位置上的牌在操作后的位置 
char mp[5]={'S','H','C','D','J'};//拍的编号与花色的对应关系 
int main()
{
	int k;
	scanf("%d",&k);
	for(int i=1;i<N;i++)
	{
		start[i]=i;//初始化牌的编号 
	}
	for(int i=1;i<N;i++)
	{
		scanf("%d",&next[i]);//输入每个位置上的牌在操作后的位置 
	}
	for(int step=1;step<=k;step++)//执行k次操作 
	{
		for(int i=1;i<N;i++)
		{
			end[next[i]]=start[i];//把第i个位置的牌的编号存于位置next[i]上 
			 
		}
		for(int i=1;i<N;i++)
		{
			start[i]=end[i];//把end数组赋值给start 数组以供下次操作使用 
		}
	}
	for(int i=1;i<N;i++)
	{
		if(i!=1) printf(" ");
		start[i]--;//若不减1，S13会得到H1 
		printf("%c%d",mp[start[i]/13],start[i]%13+1); 
	}
	return 0;
}
