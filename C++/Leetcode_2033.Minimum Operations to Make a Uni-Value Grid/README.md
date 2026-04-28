---
comments: true
difficulty: 中等
edit_url: https://github.com/doocs/leetcode/edit/main/solution/2000-2099/2033.Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/README.md
rating: 1671
source: 第 262 场周赛 Q2
tags:
    - 数组
    - 数学
    - 矩阵
    - 排序
---

<!-- problem:start -->

# [2033. 获取单值网格的最小操作数](https://leetcode.cn/problems/minimum-operations-to-make-a-uni-value-grid)


## 题目描述

<!-- description:start -->

<p>给你一个大小为&nbsp;<code>m x n</code> 的二维整数网格 <code>grid</code> 和一个整数 <code>x</code> 。每一次操作，你可以对 <code>grid</code> 中的任一元素 <strong>加</strong> <code>x</code> 或 <strong>减</strong> <code>x</code> 。</p>

<p><strong>单值网格</strong> 是全部元素都相等的网格。</p>

<p>返回使网格化为单值网格所需的 <strong>最小</strong> 操作数。如果不能，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2033.Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/images/gridtxt.png" style="width: 164px; height: 165px;" /></p>

<pre>
<strong>输入：</strong>grid = [[2,4],[6,8]], x = 2
<strong>输出：</strong>4
<strong>解释：</strong>可以执行下述操作使所有元素都等于 4 ： 
- 2 加 x 一次。
- 6 减 x 一次。
- 8 减 x 两次。
共计 4 次操作。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2033.Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/images/gridtxt-1.png" style="width: 164px; height: 165px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,5],[2,3]], x = 1
<strong>输出：</strong>5
<strong>解释：</strong>可以使所有元素都等于 3 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2033.Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/images/gridtxt-2.png" style="width: 164px; height: 165px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,2],[3,4]], x = 2
<strong>输出：</strong>-1
<strong>解释：</strong>无法使所有元素相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, grid[i][j] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
<p><strong>个人看法：</strong></p>
由初等数学易证明，取中位数距离最短（详见七年级数学：绝对值）。然后只需要找中位数并统计总操作次数即可。<br>
但是我还是能错索引hhh
