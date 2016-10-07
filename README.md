# KillDragonLegend
  演示simplec框架进行c逻辑相关代码开发, 可以跑在Visual Studio 2015和 gcc 5.4上.<br />
这里做的灭龙传说V2.0非常简陋(业务代码写不下去....), 主要通过框架对业务开发中一个要点进行了演示和构建.<br />
关于灭龙传说游戏, 更加详细玩法请参照 -> 原版V1.5 : http://bbs.pediy.com/showthread.php?p=1436361 <br />
<br />
# Window 10 + Visual Studio 2015
  当你具备这个环境, 那么只要打开 sc_template.sln 就能看见通过 simplec 部分演示重构的 灭龙传说V2.0 的代码.<br />
如果你想详细知道, simple c 在 vs 搭建环境, 需要阅读 KillDragonLegend/sc_console_template/readme/helper.txt<br />
<br />
# Ubuntu 16.04 + GCC 5.4
  当你在这个环境下阅读代码, 你需要进入 KillDragonLegend/linux_branch/  这个linux 分支下面去尝试.<br />
编译通过 Makefile. <br />
<br /> 
# simplec 框架介绍
  simplec 框架还是很简单, 特别适合那些基础好一点, 喜欢c的在校生学习. <br />
也特别适合, 想找一个很傻瓜简单的c框架练手的老鸟批判.:) <br />
1. 目前是v1.1.1 版本, 宗旨是c跨平台小型开发框架<br />
2. 内置pthread线程库, window 内置了其x86和x64版本<br />
3. 其它具体模块介绍<br />
├── Makefile                            -- linux上编译文件<br />
├── main                                -- 程序入口某块<br />
│   ├── body                            -- 灭龙传说配置解析, 业务运行代码<br />
│   │   ├── bravedragon.c<br />
│   │   ├── cfgdata.c<br />
│   │   └── include<br />
│   │       ├── bravedragon.h<br />
│   │       └── cfgdata.h<br />
│   ├── config<br />
│   │   ├── config.ini                  -- main 模块下使用的全局配置<br />
│   │   ├── goods.json                  -- 灭龙传说使用的物品配置json表<br />
│   │   ├── maps.json<br />
│   │   ├── monsters.json<br />
│   │   └── skills.json<br />
│   ├── main.c                          -- 程序总main入口<br />
│   └── simplec.c                       -- simplec 框架入口<br />
└── module                              -- 总模块文件<br />
    ├── logic                           -- 其它非框架必须业务代码文件<br />
    │   └── include<br />
    ├── schead<br />
    │   ├── include<br />
    │   │   ├── scalloc.h               -- 全局内存注入管理接口<br />
    │   │   ├── scatom.h                -- 原子锁接口<br />
    │   │   ├── scconf.h                -- 配置文件处理接口<br />
    │   │   ├── sccsv.h                 -- csv文件解析接口<br />
    │   │   ├── schead.h                -- simplec 统一头文件帮助接口<br />
    │   │   ├── scjson.h                -- json解析接口(写的比csjon好) <br />
    │   │   ├── sclog.h                 -- 多用户日志接口<br />
    │   │   ├── scrwlock.h              -- 读写锁接口<br />
    │   │   └── sctime.h                -- 时间业务操作接口<br />
    │   ├── scalloc.c<br />
    │   ├── scconf.c<br />
    │   ├── sccsv.c<br />
    │   ├── schead.c<br />
    │   ├── scjson.c<br />
    │   ├── sclog.c<br />
    │   ├── scrwlock.c<br />
    │   └── sctime.c<br />
    ├── service<br />
    │   ├── include<br />
    │   │   ├── scpthread.h             -- 高级线程池接口(解决了惊群现象)<br />
    │   │   └── sctimer.h               -- 定时器接口<br />
    │   ├── scpthread.c<br />
    │   └── sctimer.c<br />
    └── struct<br />
        ├── array.c <br />
        ├── include<br />
        │   ├── array.h                 --  通用动态数组接口<br />
        │   ├── list.h                  --  通用链表接口<br />
        │   ├── rbtree.h                --  通用红黑树接口<br />
        │   ├── tree.h                  --  通用二叉有序树接口<br />
        │   └── tstr.h                  --  普通c字符串接口<br />
        ├── list.c<br />
        ├── rbtree.c<br />
        ├── tree.c<br />
        └── tstr.c<br />
<br />
# simplec 展望
  有问题,欢迎发邮件交流 -> wangzhione@163.com<br />
 预计下一个目标就是, 内置一个优质的网络库. :) 错误是难免, 欢迎一块提高<br />

