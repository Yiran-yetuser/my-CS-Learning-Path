---
comments: true
difficulty: 简单
edit_url: https://github.com/doocs/leetcode/edit/main/solution/1800-1899/1886.Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/README.md
rating: 1407
source: 第 244 场周赛 Q1
tags:
    - 数组
    - 矩阵
---

<!-- problem:start -->

# [1886. 判断矩阵经轮转后是否一致](https://leetcode.cn/problems/determine-whether-matrix-can-be-obtained-by-rotation)

[English Version](/solution/1800-1899/1886.Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/README_EN.md)

## 题目描述

<!-- description:start -->

<p>给你两个大小为 <code>n x n</code> 的二进制矩阵 <code>mat</code> 和 <code>target</code> 。现<strong> 以 90 度顺时针轮转 </strong>矩阵 <code>mat</code> 中的元素 <strong>若干次</strong> ，如果能够使 <code>mat</code> 与 <code>target</code> 一致，返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> 。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1886.Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/images/grid3.png" style="width: 301px; height: 121px;" />
<pre>
<strong>输入：</strong>mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
<strong>输出：</strong>true
<strong>解释：</strong>顺时针轮转 90 度一次可以使 mat 和 target 一致。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1886.Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/images/grid4.png" style="width: 301px; height: 121px;" />
<pre>
<strong>输入：</strong>mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
<strong>输出：</strong>false
<strong>解释：</strong>无法通过轮转矩阵中的元素使 equal 与 target 一致。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1886.Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/images/grid4.png" style="width: 661px; height: 184px;" />
<pre>
<strong>输入：</strong>mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
<strong>输出：</strong>true
<strong>解释：</strong>顺时针轮转 90 度两次可以使 mat 和 target 一致。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == mat.length == target.length</code></li>
	<li><code>n == mat[i].length == target[i].length</code></li>
	<li><code>1 <= n <= 10</code></li>
	<li><code>mat[i][j]</code> 和 <code>target[i][j]</code> 不是 <code>0</code> 就是 <code>1</code></li>
</ul>

<!-- description:end -->

<p><strong>个人看法：</strong></p>
简单题，暴力旋转即可。
