#include<stdio.h> 
#include<time.h>
#define N 4

void ran(int *a) /*ȡ���������������λ��*/
{
	int i,j; 
	int run=1,runtime=0;//run�����Ƿ����ȡ�����runtime��ʾ����˶��ٴ� 
	srand(time(NULL));//ʹ�õ�ǰϵͳʱ����Ϊ��������� 
	while(run==1)
	{
		run=0;
		runtime++;
		for(i=0;i<N;i++)//ȡ������λ�� 
		{
			a[i]=rand()%10;
		}
	
		printf("���ڳ��Ի�ȡһ����λ��...����%d�Σ�\n",runtime);
		
		if(a[0]==0)run=1;//�����һλ�Ƿ�Ϊ�� 
		
		for(i=0;i<N-1;i++)//�������λ���Ƿ�����ͬ���� 
		{
			for(j=i+1;j<N;j++)
			{
				if(a[i]==a[j])run=1;
			}
		} 
    }	
}

void input(int *guess)/*���û�����һ����λ��*/  
{
	int i;
	
	for(i=0;i<N;i++)
	{
		scanf("%1d",&guess[i]);
	}
}

int compare(int *random, int *guess)/*�Ƚ���������Ȼ���ӡ����λ����ͬ��������ͬ������������ͬ��λ�ò�ͬ����Ԫ�صĸ���*/ 
{
	int i,j,a=0,b=0,result=0;
	
	for(i=0;i<4;i++)//�ҳ�λ����ͬ��������ͬ���� 
	{
		if(random[i]==guess[i])a++;
		
	}
	
	for(i=0;i<4;i++)// �ҳ�������ͬ��λ�ò�ͬ���� 
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
	
	ran(random); 										//ȡ������������λ����� 
	
	printf("���ˣ������и���λ�����²¿���\n");		
	
	while(guessright==0)
	{
		guesstime++;
		input(guess);									//�û����� 
		guessright=compare(random,guess); 				//�ж��Ƿ���У������A��B 
		
		if(guessright==1)								//���г��� 
		{
			printf("��̫���ˣ�������־���%d%d%d%d��",random[0],random[1],random[2],random[3]);
			return 1;
		}
		
		
		printf("��һ������%d��Ŷ��\n",guesstime);
		
		
		while(guesstime==8)								//�ڰ˴����� 
		{
			printf("���Ѿ�����8���ˣ���Ҫ������(1:����/0:�˳�)");
			scanf("%d",&go);
			if(go==0)return 8;
			else if(go==1)break;
			else printf("\n����Ƿ������������룺");	//��ʮ��δ����� 
		}
		
		while(guesstime==15)
		{
			printf("���Ѿ�����15�������ǲ��Ƿ������԰�����Ϣһ��������ɣ�");
			return 15;
		}
	}
	

	
	

	return 0;
}
