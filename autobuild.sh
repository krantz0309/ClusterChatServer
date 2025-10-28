#!/bin/bash
set -euo pipefail

# 配置
BUILD_DIR="build"
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 平台检测
detect_platform() {
    case "$(uname -s)" in
        Linux*)     echo "linux" ;;
        Darwin*)    echo "macos" ;;
        MINGW*|CYGWIN*) echo "windows" ;;
        *)          echo "unknown" ;;
    esac
}

# 安全检查
safe_clean() {
    local target="$1"
    if [ -z "$target" ]; then
        echo "错误：目录参数为空"
        exit 1
    fi
    if [ "$target" = "/" ] || [ "$target" = "." ] || [ "$target" = ".." ]; then
        echo "错误：禁止删除系统目录"
        exit 1
    fi
    rm -rf "$target"
}

# 依赖检查
check_dependencies() {
    local deps=("cmake" "make")
    for dep in "${deps[@]}"; do
        if ! command -v "$dep" >/dev/null 2>&1; then
            echo "错误：未找到 $dep"
            exit 1
        fi
    done
}

# 构建流程
main() {
    local platform=$(detect_platform)
    echo "构建平台: $platform"
    
    check_dependencies
    
    # 清理构建目录
    safe_clean "$BUILD_DIR"
    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"
    
    # 配置
    cmake .. -DCMAKE_BUILD_TYPE=Release
    
    # 编译
    if [ "$platform" = "windows" ]; then
        cmake --build . --config Release
    else
        make -j$(nproc 2>/dev/null || echo 4)
    fi
    
    echo "构建完成"
}

main "$@"