# VINS-ON-ANDROID
This is a Project deploying VINS on android platform, and it can run in realtime.
Hope This can help others to learn VINS.

## Thanks to the reference program：

###[HKUST-Aerial-Robotics/VINS-Mono](https://github.com/HKUST-Aerial-Robotics/VINS-Mono)

###[Android-VINS](https://github.com/heguixiang/Android-VINS)


**Demo Videos:** 
###[https://www.youtube.com/watch?v=WaCW7uFLzro](https://www.youtube.com/watch?v=WaCW7uFLzro)


## How to run
* Open project in android studio above version 3.0.1, build and install apk.
* in your android device create path "sdcard/VINS/", and push the files under sdcard/VINS/ to your android device.
* don't forget to enable the sdcard and camera permission.

# Build ceres
## Download ceres-solver-1.14.0.tar.gz
## Modify build config
Application.mk
```
APP_BUILD_SCRIPT := $(call my-dir)/Android.mk
APP_PROJECT_PATH := $(call my-dir)

#APP_CPPFLAGS += -fno-exceptions
APP_CPPFLAGS += -fexceptions
#APP_CPPFLAGS += -fno-rtti
APP_CPPFLAGS += -frtti
APP_CPPFLAGS += -std=c++0x
APP_OPTIM := release

# Use libc++ from LLVM. It is a modern BSD licensed implementation of
# the standard C++ library.
APP_STL := c++_static
#APP_STL := c++_shared
#APP_ABI := armeabi-v7a arm64-v8a
APP_ABI := arm64-v8a

```
Android.mk
```
LOCAL_CFLAGS := $(CERES_EXTRA_DEFINES) \
                -DCERES_NO_LAPACK \
                -DCERES_NO_SUITESPARSE \
                -DCERES_NO_CXSPARSE \
                -DCERES_STD_UNORDERED_MAP \
                                -DCERES_RESTRICT_SCHUR_SPECIALIZATION \
                                -DBUILD_ANDROID=ON \
                                -DSUITESPARSE=OFF \
                                -DGFLAGS=OFF \
                                -DCXSPARSE=OFF \
                                -DPROTOBUF=OFF \
                                -DCERES_USE_OPENMP \
                                -DCERES_HAVE_PTHREAD

+
                      $(CERES_SRC_PATH)/thread_token_provider.cc \

```

## build with following command
```
EIGEN_PATH=~/src/eigen-git-mirror ~/android-ndk/android-ndk-r20/ndk-build -j
```
