#include<stdio.h> 
#include<time.h>
#define N 4

void ran(int *a) /*取满足条件的随机四位数*/
{
	int i,j; 
	int run=1,runtime=0;//run决定是否继续取随机，runtime表示随机了多少次 
	srand(time(NULL));//使用当前系统时间作为随机数种子 
	while(run==1)
	{
		run=0;
		runtime++;
		for(i=0;i<N;i++)//取任意四位数 
		{
			a[i]=rand()%10;
		}
	
		printf("正在尝试获取一个四位数...（第%d次）\n",runtime);
		
		if(a[0]==0)run=1;//检验第一位是否为零 
		
		for(i=0;i<N-1;i++)//检验该四位数是否有相同数字 
		{
			for(j=i+1;j<N;j++)
			{
				if(a[i]==a[j])run=1;
			}
		} 
    }	
}

void input(int *guess)/*让用户输入一个四位数*/  
{
	int i;
	
	for(i=0;i<N;i++)
	{
		scanf("%1d",&guess[i]);
	}
}

int compare(int *random, int *guess)/*比较两组数，然后打印出（位置相同且数字相同）、（数字相同但位置不同）的元素的个数*/ 
{
	int i,j,a=0,b=0,result=0;
	
	for(i=0;i<4;i++)//找出位置相同且数字相同的数 
	{
		if(random[i]==guess[i])a++;
		
	}
	
	for(i=0;i<4;i++)// 找出数字相同但位置不同的数 
	{
		for(j=0;j<4;j++)
		{
			if(j==i)continue;
			
			if(random[i]==guess[j])b++;
		
		}
	}
	printf("A=%d B=%d	",a,b);
	if(a==4&&b==0)
	result=1;
	return result;
}

int main()
{
	int i=0,j=0,run=1,runtime=0,guesstime=0,guessright=0,go=1;
														 
	
	int guess[N],random[N];
	
	ran(random); 										//取满足条件的四位随机数 
	
	printf("好了，这里有个四位数，猜猜看：\n");		
	
	while(guessright==0)
	{
		guesstime++;
		input(guess);									//用户猜数 
		guessright=compare(random,guess); 				//判定是否猜中，并输出A和B 
		
		if(guessright==1)								//猜中出口 
		{
			printf("你太棒了，这个数字就是%d%d%d%d，",random[0],random[1],random[2],random[3]);
			return 1;
		}
		
		
		printf("你一共猜了%d次哦！\n",guesstime);
		
		
		while(guesstime==8)								//第八次提醒 
		{
			printf("你已经猜了8次了，还要继续吗？(1:继续/0:退出)");
			scanf("%d",&go);
			if(go==0)return 8;
			else if(go==1)break;
			else printf("\n输入非法，请重新输入：");	//第十五次次提醒 
		}
		
		while(guesstime==15)
		{
			printf("你已经猜了15次啦，是不是方法不对啊？休息一会再来玩吧！");
			return 15;
		}
	}
	

	
	

	return 0;
}
