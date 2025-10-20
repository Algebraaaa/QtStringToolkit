## 项目简介（Project Overview）

**QtStringToolkit** 是一个基于 **Qt 5/6** 框架开发的字符串操作演示工具。
该项目通过图形界面直观展示了 **QString** 的常用函数及其效果，适合 Qt 学习者和 C++ 初学者参考。用户可以通过界面控件快速测试字符串操作，而无需手动写大量测试代码。

---

## 功能特点（Features）

* **清空文本**：清空显示区内容
* **section()**：按照指定分隔符截取子字符串
* **front() / back()**：获取字符串首尾字符
* **left() / right()**：获取字符串左侧或右侧指定长度字符
* **first() / last()**：获取字符串从开头或结尾指定长度的子串
* **isNull() / isEmpty()**：判断字符串是否为空或未初始化
* **resize()**：改变字符串长度
* **size() / length()**：获取字符串长度
* **fill()**：填充字符串为指定字符
* **indexOf() / lastIndexOf()**：查找子字符串位置
* **contains()**：判断字符串是否包含某子串（大小写敏感/不敏感）
* **endsWith() / startsWith()**：判断字符串结尾或开头是否匹配
* **count()**：统计子字符串出现次数
* **trimmed() / simplified()**：去除字符串两端空格或简化连续空格
* **insert() / remove() / replace()**：插入、删除或替换子字符串

---

## 界面说明（UI Description）

* **ComboBox1**：主字符串输入，默认演示数据 `"学生姓名,男,2003-6-15,汉族,山东"`
* **ComboBox2**：辅助字符串输入，用于比较或分隔
* **SpinBox**：指定索引或长度
* **PlainTextEdit**：显示操作结果
* **Buttons**：每个 QPushButton 对应一个 QString 函数测试

---

## 技术栈（Tech Stack）

* C++ 98及以上
* Qt 5/6
* QWidget 界面开发
* 信号与槽机制实现交互

---

## 适用人群（Target Audience）

* Qt 学习者
* C++ 初学者
* 想快速理解 QString 各种操作的开发者

---

## 示例截图（Screenshot）

<img width="946" height="744" alt="image" src="https://github.com/user-attachments/assets/3f13fe91-29ab-447a-a63f-b641a5b5da75" />


---

