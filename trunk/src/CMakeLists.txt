#设置构件文件集合
set(CompSRCS
	CString.cpp
	CTime.cpp
	CTimeSpan.cpp
	)

#将构件编译成静态库
add_library(comp ${CompSRCS})

#包含子目录，并设置该目录不会在all目标中被编译
add_subdirectory(test EXCLUDE_FROM_ALL)