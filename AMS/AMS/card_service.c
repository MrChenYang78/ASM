#include "model.h"
#include <string.h>
#include "global.h"

Card acard[50]; //定义一个Card类型的数组
int ncount = 0; //记录当前卡的数量

int addcard(Card card)
{
	if(ncount >= 50)
	{
		printf("卡的数量已达上限，无法添加更多卡！\n");
		return -1;
	}
	acard[ncount] = card; //将新卡添加到数组中
	ncount++; //增加卡的数量
	return TRUE; //返回成功
}

Card* querycard(const char* aname)
{
	int i;
	for(i = 0; i < ncount; i++)
	{
		if(strcmp(acard[i].aname, aname) == 0)
		{
			return &acard[i]; //找到卡，返回指向该卡的指针
		}
	}
	return NULL; //未找到卡，返回NULL
}
