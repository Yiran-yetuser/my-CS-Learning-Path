<!-- problem:start -->

# [1582. 二进制矩阵中的特殊位置](https://leetcode.cn/problems/special-positions-in-a-binary-matrix)


## 题目描述

<!-- description:start -->

<p>给定一个 <code>m x n</code> 的二进制矩阵 <code>mat</code>，返回矩阵 <code>mat</code> 中特殊位置的数量。</p>

<p>如果位置 <code>(i, j)</code> 满足 <code>mat[i][j] == 1</code> 并且行 <code>i</code> 与列 <code>j</code> 中的所有其他元素都是 <code>0</code>（行和列的下标从 <strong>0 </strong>开始计数），那么它被称为<strong> 特殊 </strong>位置。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1582.Special%20Positions%20in%20a%20Binary%20Matrix/images/special1.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>mat = [[1,0,0],[0,0,1],[1,0,0]]
<strong>输出：</strong>1
<strong>解释：</strong>位置 (1, 2) 是一个特殊位置，因为 mat[1][2] == 1 且第 1 行和第 2 列的其他所有元素都是 0。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1582.Special%20Positions%20in%20a%20Binary%20Matrix/images/special-grid.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>mat = [[1,0,0],[0,1,0],[0,0,1]]
<strong>输出：</strong>3
<strong>解释：</strong>位置 (0, 0)，(1, 1) 和 (2, 2) 都是特殊位置。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>mat[i][j]</code> 是 <code>0</code> 或 <code>1</code>。</li>
</ul>

<!-- description:end -->
<p><strong>个人看法：</strong></p>
啊啊啊啊每日一题忘记写了。  

感觉是简单题中比较复杂的了，也想了一小会才写出来。  

个人感觉算middle偏下的题了。  

不过也不是特别复杂，思路确定后按照思路直接写遍历就行。
