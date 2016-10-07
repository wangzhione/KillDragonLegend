C = gcc
DEBUG = -ggdb3 -Wall -D_DEBUG
#指定pthread线程库
LIB = -lpthread -lm
#指定一些目录
DIR = -I./module/schead/include -I./module/struct/include \
	  -I./module/service/include -I./main/body/include 
#具体运行函数
RUN = $(CC) $(DEBUG) -o $@ $^ $(LIB) $(DIR)
RUNO = $(CC) $(DEBUG) -c -o $@ $^ $(DIR)

# 主要生成的产品
all:KillDragonLegend.exe

#挨个生产的产品
KillDragonLegend.exe:main.o simplec.o cfgdata.o bravedragon.o \
					 scalloc.o scconf.o schead.o scjson.o sclog.o sctime.o\
					 array.o list.o tree.o tstr.o
	$(RUN)
					 
#生产游戏入口需要的机器码
main.o:./main/main.c
	$(RUNO)
simplec.o:./main/simplec.c
	$(RUNO)
cfgdata.o:./main/body/cfgdata.c
	$(RUNO)
bravedragon.o:./main/body/bravedragon.c
	$(RUNO)
	
#工具集机器码,待别人链接
scalloc.o:./module/schead/scalloc.c
	$(RUNO)
scconf.o:./module/schead/scconf.c
	$(RUNO)
sccsv.o:./module/schead/sccsv.c
	$(RUNO)
schead.o:./module/schead/schead.c
	$(RUNO)
scjson.o:./module/schead/scjson.c
	$(RUNO)
sclog.o:./module/schead/sclog.c
	$(RUNO)
scrwlock.o:./module/schead/scrwlock.c
	$(RUNO)
sctime.o:./module/schead/sctime.c
	$(RUNO)

sctimer.o:./module/service/sctimer.c
	$(RUNO)
scpthread.o:./module/service/scpthread.c
	$(RUNO)

array.o:./module/struct/array.c
	$(RUNO)
list.o:./module/struct/list.c
	$(RUNO)
rbtree.o:./module/struct/rbtree.c
	$(RUNO)
tree.o:./module/struct/tree.c
	$(RUNO)
tstr.o:./module/struct/tstr.c
	$(RUNO)

#删除命令
clean:
	rm -rf *.i *.s *.o *.out __* logs *~; ls -hl
.PHONY:clean
