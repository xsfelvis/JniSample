/**
 * Author: xushangfei
 * Time: created at 2017/1/22.
 * Description:传入String key之后生成加密后唯一的key值
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "easy_encrypt.h"
#include "../util/android_log_print.h"

char* generateKeyRSA(char* name){
    //安全性检查
    if(NULL==name || strlen(name)>KEY_NAME_SIZE){
        LOGD("function generateKey must have a ok name!\n");
        return NULL;
    }
    int index = 0;
    int loop = 0;
    char temp[KEY_SIZE] = {"\0"};
    //清空数组
    memset(temp,0, sizeof(temp));
    //将传入进来的name拷贝到临时空间
    strcpy(temp,name);
    //进行通过name转化生成的key的逻辑
    for (int index = 0; index <KEY_SIZE-1 ; index++) {
        temp[index] = rand()%20+80;
        LOGD("---------------temp[%d]=%c", index, temp[index]);

    }

    return temp;

}



