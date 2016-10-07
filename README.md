# KillDragonLegend
  演示simplec框架进行c逻辑相关代码开发, 可以跑在Visual Studio 2015和 gcc 5.4上.
这里做的灭龙传说V2.0非常简陋(业务代码写不下去....), 主要通过框架对业务开发中一个要点进行了演示和构建.
关于灭龙传说游戏, 更加详细玩法请参照 -> 原版V1.5 : http://bbs.pediy.com/showthread.php?p=1436361 

# Window 10 + Visual Studio 2015
  当你具备这个环境, 那么只要打开 sc_template.sln 就能看见通过 simplec 部分演示重构的 灭龙传说V2.0 的代码.
如果你想详细知道, simple c 在 vs 搭建环境, 需要阅读 KillDragonLegend/sc_console_template/readme/helper.txt

# Ubuntu 16.04 + GCC 5.4
  当你在这个环境下阅读代码, 你需要进入 KillDragonLegend/linux_branch/  这个linux 分支下面去尝试.
编译通过 Makefile. 
 
# simplec 框架介绍
  simplec 框架还是很简单, 特别适合那些基础好一点, 喜欢c的在校生学习. 
也特别适合, 想找一个很傻瓜简单的c框架练手的老鸟批判.:) 
1. 目前是v1.1.1 版本, 宗旨是c跨平台小型开发框架
2. 内置pthread线程库, window 内置了其x86和x64版本
3. 其它具体模块介绍
├── Makefile                            -- linux上编译文件
├── main                                -- 程序入口某块
│   ├── body                            -- 灭龙传说配置解析, 业务运行代码
│   │   ├── bravedragon.c
│   │   ├── cfgdata.c
│   │   └── include
│   │       ├── bravedragon.h
│   │       └── cfgdata.h
│   ├── config
│   │   ├── config.ini                  -- main 模块下使用的全局配置
│   │   ├── goods.json                  -- 灭龙传说使用的物品配置json表
│   │   ├── maps.json
│   │   ├── monsters.json
│   │   └── skills.json
│   ├── main.c                          -- 程序总main入口
│   └── simplec.c                       -- simplec 框架入口
└── module                              -- 总模块文件
    ├── logic                           -- 其它非框架必须业务代码文件
    │   └── include
    ├── schead
    │   ├── include
    │   │   ├── scalloc.h               -- 全局内存注入管理接口
    │   │   ├── scatom.h                -- 原子锁接口
    │   │   ├── scconf.h                -- 配置文件处理接口
    │   │   ├── sccsv.h                 -- csv文件解析接口
    │   │   ├── schead.h                -- simplec 统一头文件帮助接口
    │   │   ├── scjson.h                -- json解析接口(写的比csjon好) 
    │   │   ├── sclog.h                 -- 多用户日志接口
    │   │   ├── scrwlock.h              -- 读写锁接口
    │   │   └── sctime.h                -- 时间业务操作接口
    │   ├── scalloc.c
    │   ├── scconf.c
    │   ├── sccsv.c
    │   ├── schead.c
    │   ├── scjson.c
    │   ├── sclog.c
    │   ├── scrwlock.c
    │   └── sctime.c
    ├── service
    │   ├── include
    │   │   ├── scpthread.h             -- 高级线程池接口(解决了惊群现象)
    │   │   └── sctimer.h               -- 定时器接口
    │   ├── scpthread.c
    │   └── sctimer.c
    └── struct
        ├── array.c
        ├── include
        │   ├── array.h                 --  通用动态数组接口
        │   ├── list.h                  --  通用链表接口
        │   ├── rbtree.h                --  通用红黑树接口
        │   ├── tree.h                  --  通用二叉有序树接口
        │   └── tstr.h                  --  普通c字符串接口
        ├── list.c
        ├── rbtree.c
        ├── tree.c
        └── tstr.c

# simplec 展望
  有问题,欢迎发邮件交流 -> wangzhione@163.com
 预计下一个目标就是, 内置一个优质的网络库. :) 错误是难免, 欢迎一块提高

