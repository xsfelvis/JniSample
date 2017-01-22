//
// Created by xsf on 2017/1/22.
//
#include <jni.h>
#include <string.h>
#include <assert.h>
#include "localJni/easy_encrypt.h"
#include "xsf_jnidemo_NDKUtils.h"
#include "util/android_log_print.h"



/*
 * Class:     xsf_jnidemo_NDKUtils
 * Method:    getVipString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_xsf_jnidemo_NDKUtils_getVipString
        (JNIEnv *env, jobject obj){
    return (*env)->NewStringUTF(env, "Hello Android Studio NDK JNI developer!");
}

/*
 * Class:     xsf_jnidemo_NDKUtils
 * Method:    generateKey
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_xsf_jnidemo_NDKUtils_generateKey
        (JNIEnv *env, jobject obj, jstring name) {
    char key[KEY_SIZE] = {0};
    //使用前清空数组
    memset(key, 0, sizeof(key));
    char temp[KEY_NAME_SIZE] = {0};
    //将java传入的name转换为本地utf的char*
    const char *pName = (*env)->GetStringUTFChars(env, name, NULL);
    if (NULL != pName) {
        strcpy(temp, pName);
        strcpy(key, generateKeyRSA(temp));
        //java的name对象不需要再使用,通知虚拟机回收name
        (*env)->ReleaseStringUTFChars(env, name, pName);
    }

    return (*env)->NewStringUTF(env, key);
}

//====动态加载Jni======
//动态加载Jni
JNIEXPORT jstring JNICALL native_dynamic_key
        (JNIEnv *env, jobject obj, jstring name) {
    char key[KEY_SIZE] = {0};
    //使用前清空数组
    memset(key, 0, sizeof(key));
    char temp[KEY_NAME_SIZE] = {0};
    //将java传入的name转换为本地utf的char*
    const char *pName = (*env)->GetStringUTFChars(env, name, NULL);
    if (NULL != pName) {
        strcpy(temp, pName);
        strcpy(key, generateKeyRSA(temp));
        //java的name对象不需要再使用,通知虚拟机回收name
        (*env)->ReleaseStringUTFChars(env, name, pName);
    }

    return (*env)->NewStringUTF(env, key);

}

//参数映射表

//参数映射表
static JNINativeMethod methods[] = {
        {"dynamicGenerateKey", "(Ljava/lang/String;)Ljava/lang/String;", (void *) native_dynamic_key},
        //这里可以有很多其他映射函数
};

//为某一个类注册本地方法，调用Jni注册
static int registerNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *gMethods,
                                 int numMethods) {
    jclass clazz;
    clazz = (*env)->FindClass(env, className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }

    if ((*env)->RegisterNatives(env, clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

//注册Native
static int registerNatives(JNIEnv *env) {
    const char *className = "xsf/jnidemo/NDKUtils"; //指定注册的类
    return registerNativeMethods(env, className, methods, sizeof(methods) / sizeof(methods[0]));
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
    LOGD("-------------JNI_OnLoad into.--------\n");
    JNIEnv* env = NULL;
    jint result = -1;

    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK)
    {
        return -1;
    }
    assert(env != NULL);

    //动态注册，自定义函数
    if (!registerNatives(env))
    {
        return -1;
    }

    return JNI_VERSION_1_4;
}

