#include <jni.h>
#include "include/first.h"

JNIEXPORT jint JNICALL Java_com_ndk_priyank_ndkexample_MainActivity_add(JNIEnv *env, jobject thisobject, jint num1, jint num2)
{
    return num1 + num2;
}

JNIEXPORT jstring JNICALL Java_com_ndk_priyank_ndkexample_MainActivity_message(JNIEnv *env, jobject thisobject, jstring jsString)
{
    const char* bla;
    duk_context *ctx = NULL;
    ctx = duk_create_heap_default();
    if(!ctx) {
        bla = "Failed to create a Duktape heap.\n";
        exit(1);
    }

    jstring jstr = (*env)->NewStringUTF(env, "This comes from jni.");
    jclass clazz = (*env)->FindClass(env, "com/ndk/priyank/ndkexample/MainActivity");
    jmethodID messageMe = (*env)->GetMethodID(env, clazz, "log", "(Ljava/lang/String;)Ljava/lang/String;");
    jobject result = (*env)->CallObjectMethod(env, thisobject, messageMe, jstr);


    jstr = (*env)->NewStringUTF(env, "booooooooooooo");
    (*env)->CallObjectMethod(env, thisobject, messageMe, jstr);

    const char *stringscript = (*env)->GetStringUTFChars(env, jsString, 0);

        jstr = (*env)->NewStringUTF(env, "11111111111");
        (*env)->CallObjectMethod(env, thisobject, messageMe, jstr);
      duk_push_string(ctx, stringscript);
      jstr = (*env)->NewStringUTF(env, "2222222222222");
              (*env)->CallObjectMethod(env, thisobject, messageMe, jstr);
      if(duk_peval(ctx) != 0) {
        jstr = (*env)->NewStringUTF(env, "333333333333");
              (*env)->CallObjectMethod(env, thisobject, messageMe, jstr);
        bla = "Error: %s\n", duk_safe_to_string(ctx, -1);
        duk_destroy_heap(ctx);
        exit(0);
      }
        jstr = (*env)->NewStringUTF(env, "444444444444");
        (*env)->CallObjectMethod(env, thisobject, messageMe, jstr);

      duk_pop(ctx);

        jstr = (*env)->NewStringUTF(env, "555555555555");
        (*env)->CallObjectMethod(env, thisobject, messageMe, jstr);

      duk_push_global_object(ctx);

      jstr = (*env)->NewStringUTF(env, "6666666666666");
              (*env)->CallObjectMethod(env, thisobject, messageMe, jstr);


      duk_get_prop_string(ctx, -1, "processLine2");

          jstr = (*env)->NewStringUTF(env, "777777777777");
                    (*env)->CallObjectMethod(env, thisobject, messageMe, jstr);


      if(duk_pcall(ctx, 0) != 0) {
          bla = "Error: %s\n", duk_safe_to_string(ctx, -1);
      } else {
          bla = duk_safe_to_string(ctx, -1);
      }

      duk_pop(ctx);

      duk_destroy_heap(ctx);
      (*env)->ReleaseStringUTFChars(env, jsString, stringscript);
    return (*env)->NewStringUTF(env, bla);
}