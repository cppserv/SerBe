# #Common
# export TMPDIR=/tmp/

# #C/C++
# export CC=gcc
# export CXX=g++
# export FLAGS=-fPIC -I include/ -I dependencies/repos/hptimelib/include -Wall -Wextra -g -lpthread -pthread -O3 -Werror -pipe -flto
# export SSLCFLAGS= -I dependencies/compiled/libressl/usr/local/include
# export CFLAGS=$(FLAGS) $(SSLCFLAGS) -std=gnu11
# export CXXFLAGS=$(FLAGS) $(SSLCFLAGS) -std=gnu++11
# #export SSLLDFLAGS=-lssl -lcrypto
# #export SSLLDFLAGS= -Ldependencies/libressl/compiled/usr/local/lib/ -static -lssl -lcrypto #-Wl,-Bdynamic
# export SSLLDFLAGS= dependencies/compiled/libressl/usr/local/lib/libtls.a dependencies/compiled/libressl/usr/local/lib/libssl.a dependencies/compiled/libressl/usr/local/lib/libcrypto.a

# export LDFLAGS=-fPIC -ldl -lpthread -lstdc++

# export CPPINCLUDES := $(wildcard include/*.h include/*.hpp)
# export SRCS := $(wildcard src/*.c src/*.cpp)

# all: bin/handbeserver

# handbeserver: Dependencies $(SRCS) $(CPPINCLUDES)

# bin/handbeserver: handbeserver | $(SRCS)
# 	mkdir -p bin
# 	$(CXX) $(CXXFLAGS) $| $(SSLLDFLAGS) $(LDFLAGS) -o $@

# clean:
# 	rm -rf bin

# Dependencies: dependencies/compiled/libressl

# dependencies/compiled:
# 	git submodule update --init --recursive
# 	mkdir -p dependencies/compiled

# export LIBSSLCFLAGS='-O3 -fPIC'
# export CURRDIR=$(shell pwd)
# dependencies/compiled/libressl: .gitmodules | dependencies/compiled
# 	cd dependencies; ln -s ../libressl-dep repos/libressl/openbsd || true
# 	cd dependencies/repos/libressl; ./autogen.sh
# 	cd dependencies/repos/libressl; ./configure CFLAGS=$(LIBSSLCFLAGS)
# 	cd dependencies/repos/libressl; $(MAKE) $(MFLAGS) install DESTDIR=$(CURRDIR)/dependencies/compiled/libressl

all: compile run

run: | compile
	@echo starting plain-serbe using dummy-example.org
	@./build/bin/serBe websites/example.org/

compile: $(wildcard src/*c src/*cpp include/*h include/*hpp) | build 
	cd build && cmake ..
	cd build && ${MAKE} --no-print-directory

build:
	mkdir -p build