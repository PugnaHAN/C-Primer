# 行为模式

## Template 模式
### 适用问题
和C++的模板类似，某些算法的实现框架是一样的，只有一些的细节实现有所区别。 Templlate模式提供了一个这种问题的实现框架

### 例子
煮咖啡和泡茶： \
煮咖啡： 1. 把水煮沸； 2. 用沸水冲泡咖啡； 3. 把咖啡倒进杯子； 4. 加糖和牛奶 \
泡茶： 1. 把水煮沸； 2. 用沸水泡茶； 3. 把茶倒进杯子； 4. 加蜂蜜或牛奶。

## Responsibility of Chain（责任链）模式
[责任链模式介绍](https://sourcemaking.com/design_patterns/chain_of_responsibility)
### 意图
避免请求发送者与接收者耦合在一起，让多个对象都有可能接受请求，将这些对象连接成一条链，并且沿着这条链传递请求，直到有对象处理为止。

### 何时使用
在处理消息的时候以过滤很多道

### 应用实例
1. Android的UI按键处理； 2. 击鼓传花； 3. ATM取款。

## Command(命令) 模式
[命令模式介绍](http://www.tracefact.net/Design-Pattern/Command.aspx)
### 意图
将一个请求封装为一个对象，从而可用不同的请求对客户进行参数化；对请求排队或记录请求日志，以及支持可取消的操作。命令模式把发出命令的责任和执行命令的责任分割开，委派给不同的对象。将请求的接收者（处理者）放到Command的具体子类ConcreteCommand中

### 何时使用

### 应用实例
遥控器：发送一个操作给具体的接收者，命令中必须包含执行者
1. 空调 
2. 电视 
3. 电灯 

## Interpreter 模式
[解释器模式](http://blog.csdn.net/fanyun_01/article/details/51862242)
### 意图
Interpreter(解释器)模式是一种特殊的设计模式，它建立一个解释器（Interpreter），对于特定的计算机程序设计语言，用来解释预先定义的文法。简单地说，Interpreter模式是一种简单的语法解释器构架。解释器模式属于行为模式，给定一个语言，定义它的文法的一种表示，并定义一个解释器，这个解释器使用该表示来解释语言中的句子。

### 何时使用
正如其名，此模式大多用来解释一些(自定义的)独特语法。

### 应用实例
例如某些游戏开发引擎中读取XML文件，或是WindowsPhone开发中的XAML文件，都是使用此模式来进行的。与其说是一种模式，不如说是一种具有通用规范的行为更为准确。 