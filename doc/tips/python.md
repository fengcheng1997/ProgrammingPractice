# Python

## 在sublime中用anaconda编译python
先安装package control,百度解决

在build new system中
```{
"cmd": ["/usr/bin/python3.5", "-u", "$file"],
"path":"/home/lsc/anaconda3",
"file_regex": "^[ ]*File \"(...*?)\", line ([0-9]*)",
"selector": "source.python"
}```

### 解决python3.5里面没有tk包的问题
sudo apt-get install python3.5-tk #要加上python3.5，要不然不能安装到python3.5里

## pycharm和anaconda配置
http://blog.roxanne.work/blog/2018/03/18/ubuntu16-04pycharmanaconda%E9%85%8D%E7%BD%AE/

## python tensorflow
python 里面tensorflow只能安装在3.5和3.6(2018.11.8)里面， 用3.7安装可能找不到包，用conda新建一个3.5环境激活后再安装
假设新建的环境名称叫做tensorflow，则在sublime中Buildsystem/New build system中加入
{
"cmd": ["/home/lsc/anaconda3/envs/tensorflow/bin/python3.5", "-u", "$file"],
"path":"/home/lsc/anaconda3",
"file_regex": "^[ ]*File \"(...*?)\", line ([0-9]*)",
"selector": "source.python"
}




