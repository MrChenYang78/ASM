#include "menu.h"
#include "model.h"
#include <stdio.h>
#include "card_service.h"
#include "tool.h"

int getsize(const char* str);
void query();
Card* querycard(const char* aname);


void menu()
{
	printf("--------菜单--------\n");
	printf("1.添加卡\n");
	printf("2.查询卡\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.查询统计\n");
	printf("8.注销卡\n");
	printf("0.退出\n");
    
	printf("请输入数字选择菜单功能：");
	
}

void add()
{
	Card card;
	char aname[32] = {'\0'};
	char apwd[20] = { '\0' };
	printf("添加卡\n");
	printf("请输入卡号：");
	scanf("%s", aname);
	printf("请输入密码：");
	scanf("%s", apwd);

	int namesize = getsize(aname);
	int pwsize = getsize(apwd);
	if(namesize > 18 || pwsize > 8)
	{
		printf("输入的卡号或密码长度超过限制，请重新输入！\n");
		return;
	}

	strcpy(card.aname, aname);
	strcpy(card.apwd, apwd);

	printf("请输入开卡金额：");
	scanf("%f", &card.fbalance);
	card.nstatus = 0;
	card.ftotaluse = 0.0f;
	card.usecount = 0;
	card.ndel = 0;
	card.tstart = 0;
	card.tend = 0;
	card.tlasttime = time(NULL);

	addcard(card);

	printf("卡添加成功!信息如下\n");
	printf("卡号：%s\n", card.aname);
	printf("密码：%s\n", card.apwd);
	printf("余额：%.2f\n", card.fbalance);
	printf("上机状态：%s\n", card.nstatus == 0 ? "未上机" : "上机");
}
int getsize(const char* str)
{
	int size = 0;
	while (*str != '\0')
	{
		size++;
		str++;
	}
	return size;
}

void query()
{
	char aname[18] = { '\0' };
	char atime[20] = { '\0' };
	Card* pcard = NULL;
	printf("请输入查询的卡号\n");
	scanf("%s", aname);
	pcard = querycard(aname);
	//查询到卡，显示信息

	


	printf("查询结果：\n");
	if(pcard != NULL)
	{
		timetostrong(pcard->tlasttime, atime);
		printf("卡号：%s\n", pcard->aname);
		printf("余额：%.2f\n", pcard->fbalance);
		printf("上机状态：%s\n", pcard->nstatus == 0 ? "未上机" : "上机");
		printf("累计金额：%.2f\n", pcard->ftotaluse);
		printf("使用次数：%d\n", pcard->usecount);
		printf("上次使用时间：%s\n", atime);
	}
	else
	{
		printf("未找到该卡！\n");
	}
}



