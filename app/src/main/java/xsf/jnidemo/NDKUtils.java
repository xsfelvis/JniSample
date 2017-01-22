package xsf.jnidemo;

/**
 * Author: xushangfei
 * Time: created at 2017/1/20.
 * Description:
 */

public class NDKUtils {
    static {
        System.loadLibrary("xsfJni");   //defaultConfig.ndk.moduleName
    }
    //测试静态方法Jni
    public native String  getVipString();
    public native String  generateKey(String name);
    //测试动态方法Jni
    public native String  dynamicGenerateKey(String name);
}
