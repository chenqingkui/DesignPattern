cmake_minimum_required(VERSION 3.10)  # 修正拼写：CMAKE_MINIMUM_required → cmake_minimum_required
project(DesignPattern 
    VERSION 0.0.1
    LANGUAGES CXX
)

# 设置C++标准（推荐完整设置）
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 源文件定义（建议显式列出所有源文件）
set(SRC_FILES
    main.cpp
    # 添加其他源文件
    # template_method/template_method.cpp
    # interpreter/interpreter.cpp
)

# 递归添加包含目录的宏
macro(add_subdir_includes root_dir)
    file(GLOB children LIST_DIRECTORIES true RELATIVE ${root_dir} ${root_dir}/*)
    foreach(child ${children})
        set(full_path ${root_dir}/${child})
        if(IS_DIRECTORY ${full_path})
            # 添加为include目录
            target_include_directories(${PROJECT_NAME} PUBLIC ${full_path})
            message(STATUS "Added include directory: ${full_path}")  # 调试信息
            # 递归处理子目录
            add_subdir_includes(${full_path})
        endif()
    endforeach()
endmacro()

# 创建可执行目标
add_executable(${PROJECT_NAME} ${SRC_FILES})

# 添加包含目录（必须在目标创建后调用）
add_subdir_includes(${CMAKE_CURRENT_SOURCE_DIR})
