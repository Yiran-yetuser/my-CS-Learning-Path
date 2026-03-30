---
comments: true
difficulty: 中等
edit_url: https://github.com/doocs/leetcode/edit/main/solution/2800-2899/2840.Check%20if%20Strings%20Can%20be%20Made%20Equal%20With%20Operations%20II/README.md
rating: 1486
source: 第 112 场双周赛 Q2
tags:
    - 哈希表
    - 字符串
    - 排序
---

<!-- problem:start -->

# [2840. 判断通过操作能否让字符串相等 II](https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii)


## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>s1</code>&nbsp;和&nbsp;<code>s2</code>&nbsp;，两个字符串长度都为&nbsp;<code>n</code>&nbsp;，且只包含&nbsp;<strong>小写&nbsp;</strong>英文字母。</p>

<p>你可以对两个字符串中的 <strong>任意一个</strong>&nbsp;执行以下操作 <strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>选择两个下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;，满足 <code>i &lt; j</code>&nbsp;且 <code>j - i</code>&nbsp;是 <strong>偶数</strong>，然后 <strong>交换</strong> 这个字符串中两个下标对应的字符。</li>
</ul>

<p>&nbsp;</p>

<p>如果你可以让字符串<em>&nbsp;</em><code>s1</code><em> </em>和<em>&nbsp;</em><code>s2</code>&nbsp;相等，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s1 = "abcdba", s2 = "cabdab"
<b>输出：</b>true
<b>解释：</b>我们可以对 s1 执行以下操作：
- 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbadba" 。
- 选择下标 i = 2 ，j = 4 ，得到字符串 s1 = "cbbdaa" 。
- 选择下标 i = 1 ，j = 5 ，得到字符串 s1 = "cabdab" = s2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s1 = "abe", s2 = "bea"
<b>输出：</b>false
<b>解释：</b>无法让两个字符串相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == s1.length == s2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>s1</code> 和&nbsp;<code>s2</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
<p><strong>个人看法：</p></strong>
昨天的升级版，但是不算难。不过优化运行时间很有意思!<br>
<p><strong>C++ 性能优化：四大核心点详解</p></strong>

## 1. 参数传递优化 (Parameter Passing)
- **优化前**: `bool check(string s1, string s2)`
- **优化后**: `bool check(const string& s1, const string& s2)`
- **原理深度解析**: 
  - `string` 是管理堆内存的对象。值传递会调用**复制构造函数**，重新分配内存并拷贝所有字符。
  - 引用传递仅传递对象的地址（指针），不涉及内存拷贝。
  - `const` 修饰符防止函数内修改数据，同时允许绑定临时对象。
- **性能收益**: 
  - 时间复杂度从 **O(N)** (拷贝长度) 降为 **O(1)** (指针赋值)。
  - 避免了一次堆内存分配 (malloc) 和释放 (free)。

## 2. 容器与内存分配 (Memory Allocation)
- **优化前**: `vector<array<int, 2>> a(26)`
- **优化后**: `int cnt[52] = {}`
- **原理深度解析**: 
  - `vector` 是动态数组，数据存储在**堆 (Heap)** 上，访问需要间接寻址，且分配涉及系统调用开销。
  - 原生数组存储在**栈 (Stack)** 上，通过移动栈指针分配，速度极快。
  - 展平为一维数组 (`52`) 比二维数组内存更连续，利于 **CPU 缓存行 (Cache Line)** 预取。
- **性能收益**: 
  - 消除动态内存管理开销。
  - 提高缓存命中率 (Cache Hit Rate)，减少 CPU 等待内存的时间。

## 3. 位运算替代取模 (Bitwise Optimization)
- **优化前**: `i % 2`
- **优化后**: `i & 1`
- **原理深度解析**: 
  - 取模运算 `%` 底层通常涉及**除法指令**，除法是 CPU 中较慢的运算之一。
  - 位与运算 `&` 直接操作二进制位，只需一个时钟周期。
  - 虽然现代编译器 (`-O2/O3`) 常会自动优化 `% 2` 为 `& 1`，但显式编写能确保逻辑意图明确且不依赖编译器优化等级。
- **性能收益**: 
  - 减少 CPU 指令周期数。
  - 在循环次数极多时，累积效果显著。

## 4. 内存比较优化 (Memory Comparison)
- **优化前**: 
  ```cpp
  for (auto& v : a) if (v[0] || v[1]) return false;
- **优化后**: 
  ```cpp
  memcmp(cnt, zero, sizeof(cnt)) == 0;
