#Common
export TMPDIR=/tmp/

#C/C++
export CC=gcc
export CXX=g++
export FLAGS=-fPIC -I include/ -I dependencies/repos/hptimelib/include -Wall -Wextra -g -lpthread -pthread -O3 -Werror
export SSLCFLAGS= -I dependencies/compiled/libressl/usr/local/include
export CFLAGS=$(FLAGS) $(SSLCFLAGS) -std=gnu11
export CXXFLAGS=$(FLAGS) $(SSLCFLAGS) -std=gnu++11
#export SSLLDFLAGS=-lssl -lcrypto
#export SSLLDFLAGS= -Ldependencies/libressl/compiled/usr/local/lib/ -static -lssl -lcrypto #-Wl,-Bdynamic
export SSLLDFLAGS= dependencies/compiled/libressl/usr/local/lib/libtls.a dependencies/compiled/libressl/usr/local/lib/libssl.a dependencies/compiled/libressl/usr/local/lib/libcrypto.a

export LDFLAGS=-fPIC -ldl -lpthread -lstdc++

clean:
	rm -rf obj lib bin
	cd $(JAVAPATH); rm -rf $(CLASSFILES)
	./tools/cleanorigs.bash
	cd dependencies; $(MAKE) $(MFLAGS) clean
	git submodule foreach git clean -fdX
	git clean -fdx

