# [1523. 在区间范围内统计奇数数目](https://leetcode.cn/problems/count-odd-numbers-in-an-interval-range)


## 题目描述

<!-- description:start -->

<p>给你两个非负整数&nbsp;<code>low</code> 和&nbsp;<code>high</code>&nbsp;。请你返回<em>&nbsp;</em><code>low</code><em> </em>和<em>&nbsp;</em><code>high</code><em>&nbsp;</em>之间（包括二者）奇数的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>low = 3, high = 7
<strong>输出：</strong>3
<strong>解释：</strong>3 到 7 之间奇数数字为 [3,5,7] 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>low = 8, high = 10
<strong>输出：</strong>1
<strong>解释：</strong>8 到 10 之间奇数数字为 [9] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= low &lt;= high&nbsp;&lt;= 10^9</code></li>
</ul>

<!-- description:end -->

<p>&nbsp;</p>

<p><strong>个人看法：</strong></p>

应该算比较简单的题目。\
如果使用递归会导致时间过长，因此考虑通过 high 和 low 两数直接得出答案：\
考虑两数奇偶性以及两数之差即可。\
更短的解法是利用 / 的整数相除性质，只需要一个 return 即可，没想到。

