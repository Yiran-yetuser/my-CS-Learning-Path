<!-- problem:start -->

# [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs)


## 题目描述

<!-- description:start -->

<p>假设你正在爬楼梯。需要 <code>n</code>&nbsp;阶你才能到达楼顶。</p>

<p>每次你可以爬 <code>1</code> 或 <code>2</code> 个台阶。你有多少种不同的方法可以爬到楼顶呢？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>2
<strong>解释：</strong>有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>3
<strong>解释：</strong>有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 45</code></li>
</ul>

<!-- description:end -->
<p><strong>个人看法：</strong></p>
动态规划基础题。我似乎在高中的某一次月考做过这道题，好像是压轴的数列题。<br>
其实就是Fibonacci数列，不过不能用递归（必超时），直接用for循环迭代即可。<br>
好像还有一些降时间复杂度的方法。
