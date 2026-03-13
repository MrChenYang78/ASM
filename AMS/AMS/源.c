#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int numsel=-1; //numsel用户输入的数字
	printf("计费管理系统\n");
	do
	{
		menu(); //调用菜单函数
		scanf("%d", &numsel); //用户输入数字选择菜单功能)
		switch (numsel)
		{
			case 1:
			add(); //调用添加卡函数
			break;

			case 2:
			query(); //调用查询卡函数
			break;
		}
	} while (numsel != 0); //当用户输入0时退出系统


	return 0;
}