
# [50. Pow(x, n)](https://leetcode.cn/problems/powx-n)


## 题目描述

<!-- description:start -->

<p>实现&nbsp;<a href="https://www.cplusplus.com/reference/valarray/pow/" target="_blank">pow(<em>x</em>, <em>n</em>)</a>&nbsp;，即计算 <code>x</code> 的整数&nbsp;<code>n</code> 次幂函数（即，<code>x<sup>n</sup></code><sup><span style="font-size:10.8333px"> </span></sup>）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 2.00000, n = 10
<strong>输出：</strong>1024.00000
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>x = 2.10000, n = 3
<strong>输出：</strong>9.26100
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>x = 2.00000, n = -2
<strong>输出：</strong>0.25000
<strong>解释：</strong>2<sup>-2</sup> = 1/2<sup>2</sup> = 1/4 = 0.25
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-100.0 &lt; x &lt; 100.0</code></li>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup>-1</code></li>
	<li><code>n</code>&nbsp;是一个整数</li>
	<li>要么 <code>x</code> 不为零，要么 <code>n &gt; 0</code> 。</li>
	<li><code>-10<sup>4</sup> &lt;= x<sup>n</sup> &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
<p><strong>个人看法：</strong></p>

<p>对于我已经够复杂了</p>
<p>本质思想是利用快速幂减少运算次数，暴力算法不可取 </p>
<P>难点在于想出快速幂的方法和减少空间复杂度的方法</P>
<p>利用递归的话空间复杂度是 O( logn )，利用迭代只有 O(1)</p>
<p>迭代法比较nb，官方解答用的是二进制的思想，感觉很值得学习</p>
