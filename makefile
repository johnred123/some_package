#
#	File Name: makefile
#	Description: 
#

CC := ${CROSS_COMPILE}gcc
AR := ${CROSS_COMPILE}ar
CFLAG := -g -Wall

static_lib_name := libspackage.a
dynamic_lib_name := libspackage.so

objs += ./application/HashTable.o
objs += ./application/crc32.o
objs += ./application/utf8-to-unicode.o
objs += ./application/sha-1.o
objs += ./io/package_cfg/cfg.o
objs += ./io/package_io.o
objs += ./io/package_log.o
objs += ./malloc/mem_malloc.o
objs += ./thread/package_thread.o
objs += ./socket/package_socket.o

all:dynamic_lib

dynamic_lib:${objs}
	${CC} ${CFLAG} -fPIC -shared -o ${dynamic_lib_name} $^
.c.o:
	${CC} -c -fPIC -shared -o $@ $^
clean:
	rm -f ${dynamic_lib_name} ${static_lib_name}
	rm -f `find ./ -name "*.o"`

.PHONY:clean
