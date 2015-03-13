#
#	File Name: makefile
#	Description: 
#

CC := ${CROSS_COMPILE}gcc
AR := ${CROSS_COMPILE}ar
CFLAG := -O2 -Wall
CFLAGS := -fPIC

static_lib_name := libspackage.a
dynamic_lib_name := libspackage.so

objs += ./application/HashTable.o
objs += ./application/crc32.o
objs += ./application/utf8-to-unicode.o
objs += ./application/sha-1.o
objs += ./io/package_io.o
objs += ./io/package_log.o
objs += ./malloc/mem_malloc.o
objs += ./thread/package_thread.o
objs += ./socket/package_socket.o

all:dynamic_lib static_lib

static_lib:${objs}
	${AR} rcs ${static_lib_name} $^

dynamic_lib:${objs}
	${CC} ${CFLAG} -fPIC -shared -o ${dynamic_lib_name} $^
#.c.o:
#	${CC} -c -fPIC -shared -o $@ $^

./io/package_io.o ./io/package_log.o : ./io/package_io.h ./io/package_log.h
./application/HashTable.o : ./application/HashTable.h
./application/crc32.o : ./application/crc32.h
./application/utf8-to-unicode.o : ./application/utf8-to-unicode.h
./malloc/mem_malloc.o : ./malloc/mem_malloc.h
./socket/package_socket.o : ./socket/package_socket.h
./application/sha-1.o : ./application/sha-1.h

clean:
	rm -f ${dynamic_lib_name} ${static_lib_name}
	rm -f `find ./ -name "*.o"`

.PHONY:clean
