#include <time.h>

void timetostrong(time_t t, char* pbuf)
{
	struct tm* ptm = localtime(&t);
	strftime(pbuf, 20, "%Y-%m-%d %H:%M:%S", ptm);
}