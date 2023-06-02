#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <los_memory.h>

char buf[1024*1024];
void *p[1024];

int main()
{
    int i;
    int num;
    int len;

    srand(time(NULL));
    LOS_MemInit(buf, 1024*1024);

    /* 随机读写测试 */
    for(i=0; i<100000;i++) {
        num = rand() % 1024;
        len = rand() % 1024 + 1;
        if (p[num] == NULL) {
            p[num] = LOS_MemAlloc((void*)buf, len);
            memset(p[num], 0, len);
        }
        else {
            LOS_MemFree((void*)buf, p[num]);
            p[num] = NULL;
        }
    }
    OsMemInfoPrint((void*)buf);
    return 0;
}