# 二叉搜索树项目结构

## 目录结构

```
Binary_search_tree/
├── bin/ # 可执行文件目录
├── inc/ # 头文件目录
│ └── BSTree.h # 二叉搜索树头文件
└── src/ # 源代码目录
├── BSTree.c # 二叉搜索树实现
└── main.c # 主程序文件
```

## 文件说明

### 头文件 `inc/BSTree.h`
```c
#ifndef BSTREE_H
#define BSTREE_H

typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode, *BSTree;

// 函数声明
BSTree insert_bstree(BSTree root, int value);
BSTree delete_bstree(BSTree root, int value);
// 其他函数声明...

#endif
```

### 源文件 `src/BSTree.c`

```
#include "BSTree.h"
#include <stdlib.h>

BSTree insert_bstree(BSTree root, int value) {
    // 插入实现
}

BSTree delete_bstree(BSTree root, int value) {
    // 删除实现
}
// 其他函数实现...
```

### 主程序 `src/main.c`

```
#define _CRT_SECURE_NO_WARNINGS
#include "../inc/BSTree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // 主程序代码...
    return 0;
}
```

## 编译说明

### Linux/macOS

```
mkdir -p bin
gcc -I./inc src/main.c src/BSTree.c -o bin/bst_program
```

### Windows (MinGW)

```
mkdir bin
gcc -Iinc src\main.c src\BSTree.c -o bin\bst_program.exe
```

## 运行程序

```
./bin/bst_program   # Linux/macOS
bin\bst_program.exe # Windows
```

## 补充说明

1. 确保编译时通过`-I`参数指定头文件路径
2. 可执行文件将生成在`bin`目录
3. 建议使用`Makefile`管理编译流程

