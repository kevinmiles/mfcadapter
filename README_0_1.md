当前版本为0.1版，功能有限，不可用于生产环境，仅在Linux和Cygwin下测试编译通过，在Windows环境下，不建议使用<br>
<br>
编译过程（Linux or Cygwin 并确保cmake已经安装的前提下）:<br>
您可以先运行测试<br>
tar xvf MFCAdapter-0.1.tar.gz<br>
cd MFCAdapter/<br>
cmake .<br>
make test<br>
cd src/test<br>
./TestRunner<br>
<br>
或者直接编译库，不测试<br>
tar xvf MFCAdapter-0.1.tar.gz<br>
cd MFCAdapter/<br>
cmake .<br>
make<br>
库文件就在src目录下,MFCAdapter.a<br>