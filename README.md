plugins_system_example1
=======================

to show how to build application can load plugins

系统包括三部分, 我们常看到的(1)在运行的.exe, (2)某个可以被加载的plugin, 还有底下可能不容易察觉的(3)被前两者所共用的，起到连接关系的dll. 三者的结构类似于:  
  ...................  
  AppTest | PluginDLL  
  ...................  
    	CommonDLL	
  ...................  

在实现中遇到的questions: 
- 怎么export一个dll A里面的信息到外面，让别的dll B能够使用? 
- C++编译的时候，会涉及一个managling name的问题. 这时候就要回到extern "C"

Reference: Using Dynamic Link Libraries (DLL) to Create Plug-Ins, by Jeremiah van Oosten. 
http://3dgep.com/?p=1759  