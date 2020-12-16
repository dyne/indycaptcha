#!/bin/bash

if [ "$1" == "gd" -o "$1" == "" ]; then
    cd gd
    cmake . -DBUILD_STATIC_LIBS=ON -DBUILD_SHARED_LIBS=OFF \
          -DCMAKE_C_FLAGS="-fPIC" -DVERBOSE=1 \
          -DENABLE_PNG=1 -DENABLE_LIQ=0 -DENABLE_JPEG=0 -DENABLE_TIFF=0 \
          -DENABLE_ICONV=1 -DENABLE_XPM=0 -DENABLE_WEBP=0 \
          -DENABLE_FREETYPE=1 -DENABLE_FONTCONFIG=0 \
          -DFREETYPE_INCLUDE_DIRS=/usr/include/freetype2
    make gd_static
    cd -
fi

if [ "$1" == "freetype" -o "$1" == "" ]; then
	cd freetype
	cmake -E make_directory build
	cmake -E chdir build cmake .. \
 		  -DBUILD_SHARED_LIBS=ON -DCMAKE_C_FLAGS="-fPIC" \
		  -DMAKE_DISABLE_FIND_PACKAGE_HarfBuzz=TRUE \
		  -DCMAKE_DISABLE_FIND_PACKAGE_BZip2=TRUE \
		  -DCMAKE_DISABLE_FIND_PACKAGE_Png=TRUE \
		  -DCMAKE_DISABLE_FIND_PACKAGE_ZLib=TRUE
	make -C build
	cd -
fi
