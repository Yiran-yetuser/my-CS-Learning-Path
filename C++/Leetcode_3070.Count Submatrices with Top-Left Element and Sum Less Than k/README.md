---
comments: true
difficulty: 中等
edit_url: https://github.com/doocs/leetcode/edit/main/solution/3000-3099/3070.Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/README.md
rating: 1498
source: 第 387 场周赛 Q2
tags:
    - 数组
    - 矩阵
    - 前缀和
---

<!-- problem:start -->

# [3070. 元素和小于等于 k 的子矩阵的数目](https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k)


## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数矩阵 <code>grid</code> 和一个整数 <code>k</code>。</p>

<p>返回包含 <code>grid</code> 左上角元素、元素和小于或等于 <code>k</code> 的 <strong><span data-keyword="submatrix">子矩阵</span></strong>的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3070.Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/images/example1.png" style="padding: 10px; background: #fff; border-radius: .5rem;" />
<pre>
<strong>输入：</strong>grid = [[7,6,3],[6,6,1]], k = 18
<strong>输出：</strong>4
<strong>解释：</strong>如上图所示，只有 4 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 18 。</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3070.Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/images/example21.png" style="padding: 10px; background: #fff; border-radius: .5rem;" />
<pre>
<strong>输入：</strong>grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
<strong>输出：</strong>6
<strong>解释：</strong>如上图所示，只有 6 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 20 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length </code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 1000 </code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->

<p><strong>个人看法：</strong></p>
依旧是前缀和系列，不过这题比前几天的都简单一些。<br>
其实思路是挺好找的，只需要在原grid上原地记录前缀和即可，不过由于我刚开始想的和写的时候想的不太一致导致代码有点长......不过让ai给我整一下美观多了，我将永远追随三元表达式大人！
