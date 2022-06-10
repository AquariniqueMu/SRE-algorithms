# 字节跳动面试题

## 计算机网络

### OSI七层参考模型

#### 	OSI与TCP/IP的区别？

#### 	OSI为什么衍生出四层？

### ICMP协议主要功能

### Ping属于什么协议

### ARP协议功能及解析地址用到的报文

### TCP/IP协议

#### 	TCP/IP有哪四层？

#### 	三次握手和四次挥手的过程，如果出错怎么解决？

#### 	SERver给Client发送ACK、FIN消息时，TCP处于什么状态

#### 	CLOSE_WAIT和Time_wait是什么

#### 	TCP可靠机制有哪些

#### 	TCP和UDP的区别

#### 	tcp协议结构？tcp的首部字段？ip首部字段？

#### 	检验和的功能？

#### 	TCP滑动窗口是什么？

#### 	TCP首部的flag是什么？

#### 	TCP出现丢包时的机制？

#### 	TCP面向字节流的含义？tcp在字节流怎么确认数据包的开始和结束？

#### 	tcp除了拥塞控制和流量控制还有什么机制？

#### 	TCP拥塞算法机制？

#### 	cwnd突然降为1会造成卡顿，为什么仍然要这么做？针对这个问题，业界如何解决？

#### 	给出IP地址如何求子网个数？

### 什么是长连接和短连接？

### 什么是软连接和硬连接？有哪些具体应用？

### HTTP协议

#### 	http的报头，TCP在三层、四层的报头？

#### 	http的状态码？

#### 	http1.0 1.1 2.0区别？

#### 	https握手过程？

#### 	http与https的区别？

### 什么时候会出现TW，怎么解决？

### 输入网址后发生了什么？

### 深入到接入层讲一讲（LVS的DR模型）

### QQ两个用户发消息，中间用到了什么协议？

### UDP用到什么场景？

### QUIC简述？

### CSRF协议简述？

### 跨域是什么？

### cookie和session区别？

### get和post的区别？

### 404是什么意思？

### DNS递归查询和迭代查询简述？

### UNIQ协议的特点？

### 视频传输使用什么协议？

### SSL协议简述？

## 编程（C++）

### 多态是什么意思？

### 重载和重写的区别是什么？

### 什么是虚函数？

### 能不能在构造函数和析构函数中用虚函数？

### 二叉树锯齿形层序遍历？( https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

### 红黑树的原理？

### 存在重复元素？( https://leetcode-cn.com/problems/contains-duplicate/)

### 斐波那契数列最优解？( https://leetcode-cn.com/problems/qJnOS7/)

### 二维数组中的查找？( https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

### B+树的原理？

## 操作系统

### 进程、线程、协程的区别？

### 孤儿进程和僵尸进程的区别？怎么解决？

### 如何监听某个端口的进程？

### 进程之间的通信方式？

### 虚拟内存有什么用？

### 死锁产生的条件？

### 堆和栈的区别？

### 什么时候会发生页表置换？

## LINUX基础知识

### select、poll、epoll区别

### df和du的区别

### buffer和cache的区别

### load怎么用？是什么队列？

### puppet和ansible的区别？

### awk命令？

### sed命令？和awk的区别？

### top命令可以看到什么信息？

### LVS和nginx简述？如果有四台服务器，用LVS的DR结构设计路由策略？

### 权限控制？

### 如何获取文件的10-20行？

### passwd命令？

### crontab命令？

### 怎么看文档？

### 如何查看占用端口的进程？

### linux各目录的作用？

### 怎么看CPU的负载？

### cache是什么意思？

### swap是什么意思？

### shell命令 删除给定目录下的已“.log” 为结尾的文件，要求只能用一条指令？

### shell命令 统计特定状态的tcp网络状态？

### tcpdump指令抓指定的包？



## 算法

### 给出几个数字，输出所有可能的数字组合，要求组成的数字不能重复，例如给1 2 3 可能的结果有123 132 213 231 312 321 

### 兔子吃萝卜，一个兔子每天吃当前一半多一个的萝卜，10天后还剩1个，求原先有多少个

### [二分查找](https://www.nowcoder.com/jump/super-jump/word?word=二分查找)

### 阶乘（考虑溢出）

### 给定一个数组和一个数，找出距离该数最近的数字

### 不用/和%实现求余数和商

### 两数相加 ( https://leetcode-cn.com/problems/add-two-numbers/)

### [最长公共子序列](https://ac.nowcoder.com/jump/super-jump/word?word=最长公共子序列) （ https://leetcode-cn.com/problems/qJnOS7/）

### [归并排序](https://ac.nowcoder.com/jump/super-jump/word?word=排序)

### [二叉树](https://ac.nowcoder.com/jump/super-jump/word?word=二叉树)

### 二叉树的层序遍历变形（ https://leetcode-cn.com/problems/hPov7L/）

### [斐波那契数列](https://ac.nowcoder.com/jump/super-jump/word?word=斐波那契数列)最优解 ( https://leetcode-cn.com/problems/qJnOS7/)

### 二维数组中的查找 ( https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

### 存在重复元素( https://leetcode-cn.com/problems/contains-duplicate/)

### [二叉树](https://ac.nowcoder.com/jump/super-jump/word?word=二叉树)的锯齿形层序遍历( https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

### **非递归前序遍历[二叉树](https://www.nowcoder.com/jump/super-jump/word?word=二叉树)（[leetcode](https://www.nowcoder.com/jump/super-jump/word?word=leetcode)144）**

### 讲一下快排、归并、选择[排序](https://www.nowcoder.com/jump/super-jump/word?word=排序)

### 在无序数组里面，找到第一个出现的只出现过一次的数字

### 最长回文字串 [leetcode](https://www.nowcoder.com/jump/super-jump/word?word=leetcode)5 

### 写一个快排

### 约瑟夫环

### [反转链表](https://www.nowcoder.com/jump/super-jump/word?word=反转链表)

### 查找字符串中是否含有重复字符，找到后实现字符串去重，基于数组

