1.安装redis server
下载redid: wget http://download.redis.io/releases/redis-3.0.0.tar.gz
tar zxvf redis-3.0.0.tar.gz
编译时依赖的库
编译redis时 提示make cc Command not found
yum install gcc
yum install tcl
cd redis-3.0.0
taskset -c 1 sudo make MALLOC=libc test
make install
cd src
redis-server &

2.安装hiredis
下载hiredis
https://github.com/redis/hiredis/tree/v0.13.3
hiredis-0.13.3.zip
83.5 KB

解压
unzip hiredis-0.13.3.zip
cd hiredis-0.13.3
执行安装指令
make
make install
安装完毕后执行ldconfig刷新缓存
ldconfig

编译运行时报错
问题：error while loading shared libraries: libhiredis.so.0.13: cannot open shared object file: No such file or directory
解决方案：
确保/etc/ld.so.conf里面有 /usr/local/lib 这一行,没有的话vim编辑在尾行加上
然后:sudo ldconfig
