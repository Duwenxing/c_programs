#include<cstdio>
int change(char c)//B为0，C为1，J为2，恰好时循环相克顺序，且字典序递增 
{
	if(c=='B') return 0;
	if(c=='C') return 1;
	if(c=='J') return 2;
 } 
 int main()
 {
 	char tm[3]={'B','C','J'};
 	int n;
 	char c1,c2;
 	int k1,k2;
 	int times_A[3]={0},times_B[3]={0};//times_A[]记录甲的胜负平次数，times_B记录乙的胜负平次数 
 	int hand_A[3]={0},hand_B[3]={0};//按BCJ的顺序分别记录甲乙三种手势的获胜次数 
 	scanf("%d",&n);
 	for(int i=0;i<n;i++)//甲乙的手势 
 	{
 		getchar();//吸收换行键 
 		scanf("%c %c",&c1,&c2);
 		k1=change(c1);
 		k2=change(c2);
 		if((k1+1)%3==k2)//甲获胜的情况 
 		{
 			times_A[0]++;
 			times_B[2]++;
 			hand_A[k1]++;
		 }
		 else if(k1==k2)//甲乙平局的情况 
		 {
		 	times_A[1]++;
		 	times_B[1]++;
		 }
		 else if((k2+1)%3==k1)//乙获胜的情况 
		 {
		 	times_A[2]++;
		 	times_B[0]++;
		 	hand_B[k2]++;
		 }
	 }
	 printf("%d %d %d\n",times_A[0],times_A[1],times_A[2]);
	 printf("%d %d %d\n",times_B[0],times_B[1],times_B[2]);
	 int id1=0,id2=0;
	 for(int i=0;i<3;i++)//找出甲乙获胜次数最多的手势 
	 {
	 	if(hand_A[i]>hand_A[id1]) id1=i;
	 	if(hand_B[i]>hand_B[id2]) id2=i;
	 }
	 printf("%c %c\n",tm[id1],tm[id2]);//转变会BJC 
	 return 0;
 }
