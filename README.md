# Gluttonous-Snake贪吃蛇的实现

### 简介：

    共于贪吃蛇的实现，由一个窗口（window），一个蛇（snake），多个座标点（Position）以及他们的功能（成员函数）组成

![1651508593346.png](https://file+.vscode-resource.vscode-webview.net/home/cx/Desktop/Gluttonous-Snake/image/README/1651508593346.png)

### 如何运行：

环境：ArchLinux

- 打开终端（Terminal）用cd命令到src文件夹下 	如： `[cx@cx Gluttonous-Snake]$ cd src `
- 法一（用makefile编译）						如：`[cx@cx src]$ make`
- 法二（用shell脚本）		如：
  1. 切换至root用户     		`[cx@cx src]$ su`
  2. 输入自己的密码
  3. 设置do.sh的运行权限	`[root@cx src]# chmod 777 do.sh `
  4. 运行脚本				./do.sh

### 不足：

1. 关于贪吃蛇的控制问题

    - 只支持w、a、s、d、W、A、S、D  4个键，个人能力和精力有限，期待

2. ~~食物是在墙内随机出现问题~~

   - ~~可能出现食物生成在蛇身体上，这并不是应该出现的情况~~
3. 没有欢迎界面
4. 没有设置难度界面

   - 其实Class Screen，是有set_freq()函数的，可以通过这来调节蛇的速度，但还没弄
5. 没有积分系统
6. 没有排行榜功能
7. 没有图形化 	呜呜呜！
8. ~~这个随机不随机！！！！！！！！！！！！！！~~
9. 游戏退出后，终端的输入依然没有回显
