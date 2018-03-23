### 一、项目目标

msvcrt项目是完全以vs2008提供的crt源码基础，通过从源码开始编译运行库，来研究visual  studio的编译原理，以及runtime的编码方法，特别是基于IDE本身特性，编译出可执行文件和动态库的启动方式。

这个研究的最终目的是为了更好的实现一个运行在windows环境下的posix libc库，而且能够直接在visual studio中使用。

### 二、使用方法

1、拷贝crt/src下所有的文件到一个新创建的目录，比如crt_source。之所以如此，因为文件数量太多，github不能提交全部，而且也没有必要。

2、git clone 本项目到另外一个目录，将本目录下所有文件拷贝到crt_source下，并覆盖原来的文件。

3、打开visual studio 2008的命令提示行，如果直接使用cmd，则需要调用vsvars32.bat来配置环境。

4、执行nmake后，在build目录下，可以看到生成的结果，以_sample打头的文件。

