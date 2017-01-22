//
// Created by xsf on 2017/1/22.
//
#include <jni.h>
#include <string.h>
#include "localJni/easy_encrypt.h"
#include "xsf_jnidemo_NDKUtils.h"



/*
 * Class:     xsf_jnidemo_NDKUtils
 * Method:    getVipString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_xsf_jnidemo_NDKUtils_getVipString
        (JNIEnv *env, jobject obj){
    return (*env)->NewStringUTF(env,"This just a test for Android Studio NDK JNI developer!");
}

/*
 * Class:     xsf_jnidemo_NDKUtils
 * Method:    generateKey
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_xsf_jnidemo_NDKUtils_generateKey
        (JNIEnv *env, jobject obj, jstring name){
    char key[KEY_SIZE] = {0};
    //使用前清空数组
    memset(key,0, sizeof(key));
    char temp[KEY_NAME_SIZE] = {0};
    //将java传入的name转换为本地utf的char*
    const char* pName = (*env)->GetStringUTFChars(env,name,NULL);
    if(NULL!=pName){
        strcpy(temp,pName);
        strcpy(key,generateKeyRSA(temp));
        //java的name对象不需要再使用,通知虚拟机回收name
        (*env)->ReleaseStringUTFChars(env,name,pName);
    }

    return (*env)->NewStringUTF(env,key);
}
