#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

typedef	struct Card
{
	char aname[18];//卡号
	char apwd[8];//密码

	int nstatus; //上机状态，0为未上机，1为上机
	float ftotaluse;//累计金额
	int usecount;//使用次数
	float fbalance;//余额
	int ndel;//注销状态，0为未注销，1为已注销

	time_t tstart;//上机时间
	time_t tend;//下机时间
	time_t tlasttime;//上次使用时间

}Card;

typedef struct Billing
{
	char aname[18];//卡号
	time_t tstart;//上机时间
	time_t tend;//下机时间
	float ftotaluse;//本次使用金额
	int nstatus; //上机状态，0为未结算，1为已结算
	int ndel;//注销状态，0为未注销，1为已注销
}Billing;

typedef struct LogonInfo
{
	char aname[18];//卡号
	time_t tLogon;//上机时间
	float fbalance;//上机时的余额

}LogonInfo;

typedef struct SettleInfo
{
	char aname[18];//卡号
	time_t tstart;//上机时间
	time_t tend;//下机时间
	float famout;//本次使用金额
	float fbalance;//结算后的余额
}SettleInfo;

typedef struct Money
{
	char aname[18];//卡号
	time_t ttime;//充值退费的时间
	int nstatus;//状态，0为充值，1为退费
	float fmoney;//金额
	int ndel;//注销状态，0为未注销，1为已注销
}Money;