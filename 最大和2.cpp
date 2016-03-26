#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;
#define MAX 1010
LL max(LL a, LL b)//求a和b的最大值
{
	int h;
	a >= b ? h = a : h = b;
	return h;
}
LL maxsum(vector<LL> &a, int &index)//求可变数值a中的最大子数组之和
{
	int dp[MAX];
	dp[0] = a[0];

	/*
	*最大连续序列之和只有两种情况，分别是：
	* 1.最大和的连续序列只有一个元素，即以array[i]开始，以array[i]结束，此时最大和就是array[i]本身
	* 2.最大和的连续序列有多个元素，即从前面的某处的array[p]开始（p<i）,一直到array[i]结尾 ，此时最大和为array[i]+dp[i-1];
	*/
	for (int i = 1; i<a.size(); i++)
	{
		dp[i] = max(a[i], dp[i - 1] + a[i]);
	}
	int k = 0;
	for (int i = 0; i<a.size(); i++)
	{
		if (dp[i]>dp[k])
		{
			k = i;
		}
	}
	index = k;
	return dp[k];//返回最大值
}
void reverse(vector<LL> &a)//使可变数组中的数值变为其相反数
{
	for (int i = 0; i<a.size(); i++)
	{
		a[i] = -a[i];
	}
}
int index(vector<LL>&a, LL sum, int i)//求最大连续子数组开始出的下标
{
	while (sum)
	{
		sum -= a[i--];
	}
	i++;
	return i;
}
int main()
{
	vector<LL> arrays;
	LL n;
	char flag = 48;
	while (flag != 10 && flag != 13)
	{
		cin >> n;
		flag = getchar();
		arrays.push_back(n);
	}
	int index1 = 0, index2 = 0;
	/*
	*最大连续子段有两种情况:
	*1.正常数组中间的某一段和最大。
    *2.此数组首尾相接的某一段和最大。这种情况是由于数组中间某段和为负值且绝对值很大导致的，此时可以先把原数组的和求出（记为ans），
    *  再把原数组取反然后求其最大子数组之和（记为ans2），此时原数组最大字数之和就是ans+ans2
	*/
	int ans1 = maxsum(arrays, index1);
	int index3 = index(arrays, ans1, index1);
	int sum=0;
	for(int i=0;i<arrays.size();i++)
	{
	sum+=arrays[i];
	}
	reverse(arrays);
	int ans2=maxsum(arrays,index2);
	int index4 = index(arrays, ans2, index2);
	int ans=max(ans1,sum+ans2);
	cout << "最大子数组之和为:" << ans << endl;
	cout << "最大子数组为:";
	if (ans == ans1)
	{
		for (int i = index3; i != index1+1; i++)
		{
			cout << -arrays[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = index2 + 1; i < arrays.size(); i++)
		{
			cout << -arrays[i] << " ";
		}
		for (int i = 0; i < index4; i++)
		{
			cout << -arrays[i] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}