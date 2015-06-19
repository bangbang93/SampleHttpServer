SimapleHttpServer
=================
一个使用WSAEventSelect的简单Http静态资源服务器

mime-type是从nginx的mime.type里整理出来的

只会处理GET请求，其余请求都会当做GET处理

请求目录时会返回index.html

<del>其实是个期末作业</del>

Usage
=====
工程环境是Visual Studio 2012

程序会工作目录下的www目录作为http服务的根目录，index.html作为默认首页

默认端口8080，新建好目录，放好首页之后就可以运行了，直接使用浏览器访问
<http://localhost:8080>即可