//
// Created by xsf on 2017/1/20.
//

#include "xsf_jnidemo_NDKUtils.h"

JNIEXPORT jstring JNICALL Java_xsf_jnidemo_NDKUtils_getVipString
  (JNIEnv *env, jobject obj){
     return (*env)->NewStringUTF(env,"This just a test for Android Studio NDK JNI developer!");
  }