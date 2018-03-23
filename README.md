### 一、项目目标

msvcrt项目是完全以vs2008提供的crt源码基础，通过从源码开始编译运行库，来研究visual  studio的编译原理，以及runtime的编码方法，特别是基于IDE本身特性，编译出可执行文件和动态库的启动方式。

这个研究的最终目的是为了更好的实现一个运行在windows环境下的posix libc库，而且能够直接在visual studio中使用。

### 二、编译方法

1、安装visula studio 2008，找到crt/src目录。

2、 git clone https://github.com/QuarkCloud/msvcrt.git ，从github上下载本项目到本地，默认msvcrt目录。

3、从crt/src下，拷贝cliext、intel、sys三个子目录，分别覆盖msvcrt对应的子目录。

4、进入msvcrt/src，将该子目录下所有文件拷贝到父目录msvcrt中。

5、打开visual studio 2008的命令提示行，如果直接使用cmd，则需要调用vsvars32.bat来配置环境。

6、执行nmake后，在build目录下，可以看到生成的结果，以_sample打头的文件。

### 三、使用方法

1、在visual studio环境中，禁止默认标准库，显式引用编译出来的库。其他的和msvcrt没有区别。

2、需要注意的是，不能显式禁用包含标准头文件路径。主要原因是，src中的头文件和标准头文件是不同的。


### 四、特别说明

1、从github下载后，之所以还有一些特别的操作，而不是直接编译，是因为github只支持1000文件上传，而crt/src源码的数量远超过1000。

2、本版本去掉和posix无关的clr部分的代码和项目。

3、intel目录下，需要保留obj和lib，因为这些obj和lib的生成规则，visual studio没有提供。
