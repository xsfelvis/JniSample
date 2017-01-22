/**
 * Author: xushangfei
 * Time: created at 2017/1/22.
 * Description:JNI打印宏
 */

//

#ifndef JNI_ANDROID_LOG_PRINT_H
#define JNI_ANDROID_LOG_PRINT_H

#include <android/log.h>

#define IS_DEBUG

#ifdef IS_DEBUG

#define LOG_TAG ("CUSTOMER_NDK_JNI")

#define LOGV(...) ((void)__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__))

#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG  , LOG_TAG, __VA_ARGS__))

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO   , LOG_TAG, __VA_ARGS__))

#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN   , LOG_TAG, __VA_ARGS__))

#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR  , LOG_TAG, __VA_ARGS__))

#else

#define LOGV(LOG_TAG, ...) NULL

#define LOGD(LOG_TAG, ...) NULL

#define LOGI(LOG_TAG, ...) NULL

#define LOGW(LOG_TAG, ...) NULL

#define LOGE(LOG_TAG, ...) NULL

#endif

#endif //JNI_ANDROID_LOG_PRINT_H
