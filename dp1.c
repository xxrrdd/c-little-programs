#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
int hps[4]={12000,8000,9000,5000};
int hjs[4]={50,30,50,60};
int cnum;
int cmenu;
int cbullet;
int clenth;
bool conti=false;
void menu();
void damage(int damage);
void cstatus(void);
void realdam(void);
void cal(void);
int load(int iLoad);

int main(void)
{
	//ȫ���������� 
	int a,b,c,r,s,t,u,i,l,s1,s2,s3;
	int m;
	a=0,b=0,c=0;
	
	//��½ 
	l=load(l);
	if(l==1)
 {
	menu();
	while((scanf("%d",&m))!=0)
	{
	    switch (m)
	   {
		case 1:
		    printf("OK!\n");
		    break;
		case 2:
			cbullet=select2();
			break;
		case 3:
			clenth=select3();
			break;
		case 4:
			cnum=select4();
			break;
		case 5:
			while(hps[cnum-1]>0)
			{
				printf("%d %d %d",cbullet,clenth,cnum);
				cal();
			    cstatus();
			    system("pause");
			}
			printf("%d������",cnum);
			break;
	   }
	fflush(stdin);
	menu();
	
   }
   return 0;
}

}


void menu()
{
	system("cls");
	printf("========================hx��������v3.1.2=========================\n");
	printf("----------------------------���˵�-------------------------------\n");
	printf("|                --------------------                             |\n");
	printf("|                |  1�����ڳ�ʼ��    |                            |\n");
	printf("                 --------------------                             |\n");
	printf("|                |  2���ڵ�ѡ��      |                            |\n");
	printf("                 --------------------                             |\n");
	printf("|                |  3���ھ�ѡ��      |                            |\n");
	printf("                 --------------------                             |\n");
	printf("|                |  4������ѡ��      |                            |\n");
	printf("                 --------------------                             |\n");
	printf("|                |  5����ɷ���      |                            |\n");
	printf("                 --------------------                             |\n");
	printf("               ������ѡ��1-5     0���˳�                          |\n");
}

int load(int iLoad)
{/*
	char user[15]={"handapao"};
	char password[15]={"zhouxiaojie"};
	char ustr[15],pstr[15];
	int i=0;
	
	while(i<3)
	{
		system("cls");
		printf("=================hx��������v2.5.3===============\n");
		printf("|||||||||||||||||||��½|||||||||||||||||||||||\n");
		printf("�������û���\n");
		gets(ustr);
		printf("����������\n");
		gets(pstr);
		if(strcmp(user,ustr))
		{
			printf("�û���������\n");
		}
        if(strcmp(password,pstr))
		{
			printf("�����������ʣ��%d�λ���\n",2-i);
			getch();
		}
		else
		{
			printf("��ӭʹ�ã�\n");
			iLoad=1;
			break;
		}
		i++;
	}
	if(i==3)
	{
		printf("�������Σ�\n");
		iLoad=0;
	}
	return iLoad;*/
	return 1;
}



void cal(void)
{
	float per;
	int dam;
	float boom;
	switch(clenth)
	{
		case 1:per=0.8;break;
		case 2:per=0.6;break;
		case 3:per=0.4;break;
	}
	
	switch(cbullet)
	{
		case 1:conti=true;
		       damage(300);
		       break;
		case 2:printf("\nstart\n");
		       srand(time(NULL));
		       boom=rand()%100;
		       boom/=100;
		       printf("boom...%f\n",boom+1);
		       damage((boom+1)*200);
		       break;
		case 3:damage(150);
		       realdam();
		       break;
		case 4:hjs[cnum-1]*=0.5;
		       damage(400);
	}
	if(cnum==2)
	      hps[1]*=1.02;
}

//	printf("\n");
void damage(int dam)
{
	float hj=hjs[cnum-1];
	float damr=1-hj/(hj+100);
	float hpsub=dam*damr;
	hps[cnum-1]-=(int)hpsub;
	printf("\n%f,,,,%d\n",damr,(int)hpsub);
	if(conti)
	     hps[cnum-1]-=50;
    hjs[0]+=5;
}
void realdam(void)
{
	hps[cnum-1]*=(1-0.14);
}
//
void cstatus(void)
{
	printf("NPC:%d �ĵ�ǰѪ��Ϊ%d\n",cnum,hps[cnum-1]);
	printf("��ǰ����Ϊ%d\n",hjs[cnum-1]);
}

int select2(void)
{
	int a;

	printf("   1��������������   \n");
	printf("     �˺�300����������Ч����ʹ�˸�Ⱦˢ���ħ֢\n");
	printf("   2����һ��������   \n");
	printf("     �˺�200����������Ч��\n");
	printf("   3��ҹ��С����   \n");
	printf("     �˺�150�������ٷֱ��˺�\n");
	printf("   4��Ѧ������С����\n");
	printf("     �˺�400���������״�͸Ч��\n");
	fflush(stdin);
	scanf("%d",&a);
	return a;
}


int select3(void)
{
	int a;
	printf("1��100mm-----����80%\n");
	printf("2��200mm-----����60%\n");
	printf("3��300mm-----����40%\n");
	fflush(stdin);
	scanf("%d",&a);
	return a;
}


int select4(void)
{
	int a;
	printf("     1���Ź�ϣ(��������)\n");
	printf("     2�����|�t(���һָ�)\n");
	printf("     3����Сƽ(�˺�����)\n");
	printf("     4��������(����)  \n");
	fflush(stdin);
	scanf("%d",&a);
	return a;
}









