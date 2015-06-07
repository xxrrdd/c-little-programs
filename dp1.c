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
	//全局数据区域 
	int a,b,c,r,s,t,u,i,l,s1,s2,s3;
	int m;
	a=0,b=0,c=0;
	
	//登陆 
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
			printf("%d已死亡",cnum);
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
	printf("========================hx大炮助手v3.1.2=========================\n");
	printf("----------------------------主菜单-------------------------------\n");
	printf("|                --------------------                             |\n");
	printf("|                |  1、大炮初始化    |                            |\n");
	printf("                 --------------------                             |\n");
	printf("|                |  2、炮弹选择      |                            |\n");
	printf("                 --------------------                             |\n");
	printf("|                |  3、口径选择      |                            |\n");
	printf("                 --------------------                             |\n");
	printf("|                |  4、队友选择      |                            |\n");
	printf("                 --------------------                             |\n");
	printf("|                |  5、完成发射      |                            |\n");
	printf("                 --------------------                             |\n");
	printf("               请依次选择1-5     0键退出                          |\n");
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
		printf("=================hx大炮助手v2.5.3===============\n");
		printf("|||||||||||||||||||登陆|||||||||||||||||||||||\n");
		printf("请输入用户名\n");
		gets(ustr);
		printf("请输入密码\n");
		gets(pstr);
		if(strcmp(user,ustr))
		{
			printf("用户名不存在\n");
		}
        if(strcmp(password,pstr))
		{
			printf("密码错误，您还剩余%d次机会\n",2-i);
			getch();
		}
		else
		{
			printf("欢迎使用！\n");
			iLoad=1;
			break;
		}
		i++;
	}
	if(i==3)
	{
		printf("错误三次！\n");
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
	printf("NPC:%d 的当前血量为%d\n",cnum,hps[cnum-1]);
	printf("当前护甲为%d\n",hjs[cnum-1]);
}

int select2(void)
{
	int a;

	printf("   1、王后雄牌榴弹炮   \n");
	printf("     伤害300，附带毒性效果，使人感染刷题狂魔症\n");
	printf("   2、曲一线牌榴弹炮   \n");
	printf("     伤害200，附带暴击效果\n");
	printf("   3、夜光小钢炮   \n");
	printf("     伤害150，附带百分比伤害\n");
	printf("   4、薛金星牌小钢炮\n");
	printf("     伤害400，附带护甲穿透效果\n");
	fflush(stdin);
	scanf("%d",&a);
	return a;
}


int select3(void)
{
	int a;
	printf("1、100mm-----命中80%\n");
	printf("2、200mm-----命中60%\n");
	printf("3、300mm-----命中40%\n");
	fflush(stdin);
	scanf("%d",&a);
	return a;
}


int select4(void)
{
	int a;
	printf("     1、张冠希(超级护甲)\n");
	printf("     2、王珅祎(自我恢复)\n");
	printf("     3、吴小平(伤害反弹)\n");
	printf("     4、王云鹏(随便打)  \n");
	fflush(stdin);
	scanf("%d",&a);
	return a;
}









