# 算法大作业说明

> Date: 2019-6-1
>
> Github: [<https://github.com/AllenOris/CardProblem>](<https://github.com/AllenOris/CardProblem>)

## 目录

```python
目录
|	“支付宝集五福”抽卡概率问题分析.pdf #论文PDF版
|---Code  #代码文件
|	|---Expectation	#问题一：数学期望
|	|	|---MonteCarlo	#蒙特卡洛解法
|	|	|---SameProbality	#卡片相同的特殊情况解法
|	|	|---DynamicProgramming #动态规划解法
|	|---M_Extraction #问题二：限制抽取次数下的概率
|	|	|---MonteCarlo	#蒙特卡洛解法
|	|	|---SameProbality	#卡片相同的特殊情况解法
|	|	|---DynamicProgramming #动态规划解法
|	|	|---FFT	#生成函数相乘的快速傅里叶变换解法
| 	README.md	#markdwon说明文档
```

## 说明

### 题目说明

题目为原创，想关代码均通过测试，题目可见于：

1. 问题一的特殊情况题目：<http://acm.nankai.edu.cn/problem/1069>
2. 问题一的一般情况题目：<http://acm.nankai.edu.cn/problem/1070>
3. 问题二的特殊情况题目：<http://acm.nankai.edu.cn/problem/1071>
4. 问题二的特殊一般题目：<http://acm.nankai.edu.cn/problem/1072>

### 代码说明

* 文件中的`CMakeLists.txt`为Clion工程的Cmake文件。
* 每个文件的`main.cpp`为`C++`解决方案程序，其中`./Code/M_Extraction/FFT/fft.py`是快速傅里叶变换解法的`Python`程序，因为考虑到`Python`对精度的便捷处理。

### 数据说明

本问题拆分为4个问题，一共包含四组问题数据。分别在

* 文件`./Code/Expactation/SameProbability/Data`下
* 文件`./Code/Expactation/DynamicProgramming/Data`下
* 文件`./Code/M_Extraction/SameProbability/Data`下
* 文件`./Code/M_Extraction/DynamicProgramming/Data`下

其中，`*.in`为输入文件，`*.out`为输出文件，`gen.py`为数据生成文件。`SpecialJudge`文件下的`spj.cpp`为程序结果特判文件，判断输出结果的精度问题。

## 问题描述

给定n种互不相同的卡片，与数组$P=\{p_1,p_2,p_3,...p_n\}$，进行若干次抽取实验，对于每次实验，卡片$i$被抽中的概率均为$p_i$。（$0< \sum\limits_{i=1}^{i=n}{p_i}\leq 1$）

求解：

1. 若每种卡片可被无限次抽取，不限制抽取次数，求能够恰好抽取全部种类卡片的抽取次数期望。记为问题一。

\item 若每种卡片可被无限次抽取，不限制抽取次数，求能够恰好抽取全部种类卡片的抽取次数期望。记为问题一。

2. 若每种卡片可被无限次抽取，且限制抽取$m$次，求在m次内（包括m次）全部种类的卡片均被抽到的概率。记为问题二。



## 主要算法

本文应用的主要算法包括蒙特卡洛方法、第二类斯特林数的计算、状态压缩下的动态规划、快速傅里叶变换等。