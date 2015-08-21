# android_native_bench

How to use?

1) Set up path to the NDK in mk.py(ROOT="/media/chrono/Other/android-ndk-r10d"). Correct NDK_PLATFORM_VER and other paths if needed.

2) execute: 

`./mk.py`

`./mk.py push`

Latest command will push binary via adb to /data/usr.

3) measure execution time of program(see sources for details):

`/data/usr/test 4 5`

`logcat | grep bench`
