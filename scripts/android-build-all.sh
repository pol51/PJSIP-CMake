#!/bin/sh

export CPU_COUNT=`nproc`
export JOBS_COUNT=`echo $(($CPU_COUNT*1.5)) | cut -d. -f1`

mkdir -p build-x86
pushd build-x86
cmake \
  -DTARGET_ANDROID=1\
  -DCMAKE_TOOLCHAIN_FILE=../cmake/android.toolchain.cmake\
  -DANDROID_LEVEL=android-14\
  -DANDROID_NATIVE_API_LEVEL=14\
  -DANDROID_ABI=x86\
  -DWITH_RESAMPLE_LIBRESAMPLE=1\
  -DWITH_CODEC_G722=1\
  -DWITH_CODEC_SPEEX=0\
  -DWITH_AUDIODEV_OPENSL=1\
  -DWITH_BUILTIN_OPENSSL=1\
  ..
make -j$JOBS_COUNT
popd

mkdir -p build-armeabi
pushd build-armeabi
cmake \
  -DTARGET_ANDROID=1\
  -DCMAKE_TOOLCHAIN_FILE=../cmake/android.toolchain.cmake\
  -DANDROID_LEVEL=android-14\
  -DANDROID_NATIVE_API_LEVEL=14\
  -DARM_TARGET=armeabi\
  -DFORCE_ARM=true\
  -DWITH_RESAMPLE_LIBRESAMPLE=1\
  -DWITH_CODEC_G722=1\
  -DWITH_CODEC_SPEEX=0\
  -DWITH_AUDIODEV_OPENSL=1\
  -DWITH_BUILTIN_OPENSSL=1\
  ..
make -j$JOBS_COUNT
popd

mkdir -p build-armeabi-v7a
pushd build-armeabi-v7a
cmake \
  -DTARGET_ANDROID=1\
  -DCMAKE_TOOLCHAIN_FILE=../cmake/android.toolchain.cmake\
  -DANDROID_LEVEL=android-14\
  -DANDROID_NATIVE_API_LEVEL=14\
  -DARM_TARGET=armeabi-v7a\
  -DFORCE_ARM=true\
  -DWITH_RESAMPLE_LIBRESAMPLE=1\
  -DWITH_CODEC_G722=1\
  -DWITH_CODEC_SPEEX=0\
  -DWITH_AUDIODEV_OPENSL=1\
  -DWITH_BUILTIN_OPENSSL=1\
  ..
make -j$JOBS_COUNT
popd
