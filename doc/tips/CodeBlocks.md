# CodeBlocks

## 安装与配置
```
sudo apt-get update
sudo apt-get install codeblocks codeblocks-dev
sudo apt-get install codeblocks-contrib //插件
```

## 汉化

https://blog.csdn.net/aniuge008/article/details/73195297

## 解决终端不能输入中文问题

编辑器`encoding settings`选择utf-8

编译器`Other compiler optios`加入下列代码
```
-finput-charset=utf-8
-fexec-charset=utf-8
```

## 其他
在编译器里讲`Autolaunch after typing # letter`调到2，自动补全的提示会在只有两个字母时显示，加快编程速度
