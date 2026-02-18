<!-- problem:start -->

# [693. 交替位二进制数](https://leetcode.cn/problems/binary-number-with-alternating-bits)


## 题目描述

<!-- description:start -->

<p>给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>true
<strong>解释：</strong>5 的二进制表示是：101
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 7
<strong>输出：</strong>false
<strong>解释：</strong>7 的二进制表示是：111.</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 11
<strong>输出：</strong>false
<strong>解释：</strong>11 的二进制表示是：1011.</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
<p><strong>个人看法：</strong></p>
位运算练习题。<br>
我先想到的做法是逐位检查，做了一个时间复杂度O(logn)的做法<br>
然后稍微简化一下代码，用 last 变量记录上一个数字，让代码变简短一些。<br>
异或法真的没想到。
