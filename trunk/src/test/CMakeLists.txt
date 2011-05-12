#设置测试用例文件集合
set(TestRunnerSRCS
	CStringTest.cpp
	CTimeTest.cpp
	CTimeSpanTest.cpp
	Main.cpp
	)

#生成测试用例可执行文件
add_executable(TestRunner ${TestRunnerSRCS})

#添加编译目标test
add_custom_target(test DEPENDS TestRunner)

#设置link选项
set(CMAKE_EXE_LINKER_FLAGS -lpthread)

#链接静态库,cygwin中libgtest.a在/usr/local/lib中
#并没有被添加为系统库文件，所以将该库文件copy到/usr/lib中即可
target_link_libraries(TestRunner MFCAdapter)
target_link_libraries(TestRunner libgtest.a)