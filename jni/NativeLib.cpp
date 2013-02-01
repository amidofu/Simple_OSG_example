#include "nativeFunction_NativeLib.h"
#include "osgMain.h"
osgMain osgmain;
JNIEXPORT void JNICALL Java_nativeFunction_NativeLib_OSGRun
  (JNIEnv *, jclass)
{
	osgmain.draw();
}

JNIEXPORT void JNICALL Java_nativeFunction_NativeLib_initOSG
  (JNIEnv *, jclass, jint width, jint height)
{
	osgmain.initOSG(width, height);
}
