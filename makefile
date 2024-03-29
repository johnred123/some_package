#	Description: 
#

CC := ${CROSS_COMPILE}gcc
AR := ${CROSS_COMPILE}ar
CFLAG :=
CFLAGS := -fPIC -Wall -O2 -pipe

static_lib_name := libspackage.a
dynamic_lib_name := libspackage.so

objs += ./application/HashTable.o
objs += ./application/crc32.o
objs += ./application/aes.o
objs += ./application/myrand.o
objs += ./application/utf8-to-unicode.o
objs += ./application/sha-1.o
objs += ./application/sha2.o
objs += ./io/package_io.o
objs += ./io/package_log.o
objs += ./malloc/mem_malloc.o
objs += ./thread/package_thread.o
objs += ./socket/package_socket.o
objs += ./data_struct/link_list/package_link_list.o

all:dynamic_lib static_lib

static_lib:${objs}
	${AR} rcs ${static_lib_name} $^

dynamic_lib:${objs}
	${CC} ${CFLAG} -fPIC -shared -o ${dynamic_lib_name} $^

./io/package_io.o ./io/package_log.o : ./io/package_io.h ./io/package_log.h
./application/HashTable.o : ./application/HashTable.h
./application/crc32.o : ./application/crc32.h
./application/aes.o : ./application/aes.h
./application/myrand.o : ./application/myrand.h
./application/utf8-to-unicode.o : ./application/utf8-to-unicode.h
./malloc/mem_malloc.o : ./malloc/mem_malloc.h
./socket/package_socket.o : ./socket/package_socket.h
./application/sha-1.o : ./application/sha-1.h
./application/sha2.o : ./application/sha2.h
./thread/package_thread.o : ./thread/package_thread.h
./data_struct/link_list/package_link_list.o : ./data_struct/link_list/package_link_list.h

clean:
	rm -f ${dynamic_lib_name} ${static_lib_name}
	rm -f ${objs}

.PHONY:clean
