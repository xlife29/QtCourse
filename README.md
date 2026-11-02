# 简单文本编辑器（Qt Designer 版）

本项目使用 Qt Designer 的 `.ui` 文件实现实验步骤 1 至 12：主窗口、关于对话框、查找对话框和替换对话框均由 Designer 设计；`CodeEditor` 自定义控件通过“提升为”方式使用并绘制行号栏。

## 打开和构建

1. 使用 Qt Creator 打开 `SimpleTextEditor_Designer.pro`。
2. 选择本机已安装的 Qt Widgets 桌面套件（支持 Qt 5.12.11 和 Qt 6）。
3. 构建并运行。qmake 会自动调用 uic，根据 `mainwindow.ui` 生成界面代码。

也可以在 Qt 命令行执行：

```text
qmake SimpleTextEditor_Designer.pro
mingw32-make
```

## 功能

- 新建、打开、保存、另存为，使用 UTF-8 读写文本
- 关闭或打开文件前提示保存未保存内容
- 撤销、重做、剪切、复制、粘贴、全选
- 查找、全文替换、跳转到指定行
- 字体、文字颜色和背景颜色设置
- 行号显示、自动换行开关、光标行列显示
- 已命名文件每分钟自动保存一次；未命名文件关闭时提示保存
- 关于窗口、查找窗口、替换窗口均为独立 Designer 对话框
- 视图菜单可显示或隐藏工具栏和状态栏

此版本的窗口布局、菜单、工具栏、状态栏和 Action 定义在 `mainwindow.ui` 中；功能逻辑在 C++ 源文件中。
