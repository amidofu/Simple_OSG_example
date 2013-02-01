package nativeFunction;

public class NativeLib {
		static {
			System.loadLibrary("NativeLib");
		}
		public static native void OSGRun();
		public static native void initOSG(int width,int height);
}
