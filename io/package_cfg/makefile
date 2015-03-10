CC=gcc
CFLAG=
LDFLAG=

all:test_config

config: cfg_flex.l cfg_bison.y
	flex cfg_flex.l
	bison -d cfg_bison.y
test_config:config
	${CC} ${CFLAG} cfg.c cfg_bison.tab.c lex.yy.c -o cfg_test
clean:
	rm -f lex.yy.c cfg_test cfg_bison.tab.c cfg_bison.tab.h
