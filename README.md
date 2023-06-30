# 简易网页编辑与生成系统

## 项目介绍

这是一个基于C++面向对象程序设计的简易网页编辑与生成系统。通过该系统，用户可以创建和编辑网页项目，添加和修改网页组件，生成网页的HTML代码，并保存为文件。系统提供了控制台程序，用户可以通过菜单选项进行操作，实现了一个简易的网页编辑与生成系统。

## 功能特性

- 创建和编辑网页项目，设置项目的名称和路径。
- 添加和修改网页，设置网页的标题、描述、关键字和字符集。
- 添加和修改网页组件，包括标题、段落、图像、表单、输入框、选择框和表格等。
- 生成网页的HTML代码，并保存为文件。
- 提供控制台程序，用户可以通过菜单选项进行操作。

## 系统设计

系统主要由四个模块组成：网页模块、组件模块、项目模块和控制台模块。

- 网页模块：包括页面标题、描述、关键字、字符集、文件名等页面基本属性和对页面组件增删改查的函数。
- 组件模块：包括标题、段落、图像、表单、输入框、选择框、表格等HTML基本组件。
- 项目模块：包括多页面的创建与管理。
- 控制台模块：包括项目菜单，页面菜单，组件菜单等，实现通过控制台添加、修改、删除页面与组件，实现通过控制到保存项目和预览页面。

## 使用方法

1. 运行控制台程序，显示主菜单。
2. 选择创建新项目，输入项目名称和路径。
3. 在项目菜单中，选择添加新页面，输入页面文件名、标题、字符集、描述、关键字。
4. 在页面菜单中，可以编辑页面属性、添加组件、修改组件、移除组件、预览页面。
5. 在组件菜单中，可以添加和编辑各种组件，包括标题、段落、图像、表单、输入框和表格等。
6. 可以在页面菜单中预览页面。
7. 可以在项目菜单中保存项目，将每个网页保存为一个单独的文件。
8. 可以在项目菜单中编辑页面。

## 开发环境

- 语言：![C++ badge](https://img.shields.io/badge/-C++-4fc08d?style=flat-square&logo=cplusplus&logoColor=fff)
- 开发工具：![VS Code badge](https://img.shields.io/badge/-VS_Code-007acc?style=flat-square&logo=visual-studio-code&logoColor=fff)![Visual Studio badge](https://img.shields.io/badge/-Visual_Studio-5c2d91?style=flat-square&logo=visual-studio&logoColor=fff)
- 操作系统：![Windows 11 badge](https://img.shields.io/badge/-Windows_11-2376bc?style=flat-square&logo=windows&logoColor=fff)

## 贡献者

[![OrzMiku](https://img.shields.io/badge/-OrzMiku-5c2d91?style=flat-square&logo=github&logoColor=fff)](https://github.com/OrzMiku) [![fengxinyuan](https://img.shields.io/badge/-fengxinyuan-5c2d91?style=flat-square&logo=github&logoColor=fff)](https://github.com/fengxinyuan)

## 许可证

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## 已知BUG

- 没有对控制台输入校验
- 若组件列表为空，依然可以进入编辑组件界面（页面列表也存在相同问题）。

## 更新日志

- v1.0.5
  - 重写页面预览逻辑，不再依赖Chrome浏览器
- v1.0.4
  - 添加页面预览功能
  - 修复部分菜单的返回逻辑
- v1.0.3
  - 修复控制台无法输入空格的Bug
  - 修复字符集设定Bug
- v1.0.2
  - 删除Demo演示，合并CLI类代码，增加控制台菜单程序
- v1.0.1
  - 修复了保存文件中文乱码的Bug
  - 添加了Form表单与Input框的绑定
  - 添加了部分组件超链接功能的支持
- v1.0.0 初始版本
  - 增加组件类、页面类和项目类的基础功能
  - 提供一个简易的Demo演示函数调用
