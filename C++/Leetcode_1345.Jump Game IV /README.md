---
comments: true
difficulty: 困难
edit_url: https://github.com/doocs/leetcode/edit/main/solution/1300-1399/1345.Jump%20Game%20IV/README.md
rating: 1809
source: 第 19 场双周赛 Q4
tags:
    - 广度优先搜索
    - 数组
    - 哈希表
---

<!-- problem:start -->

# [1345. 跳跃游戏 IV](https://leetcode.cn/problems/jump-game-iv)

[English Version](/solution/1300-1399/1345.Jump%20Game%20IV/README_EN.md)

## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code>&nbsp;，你一开始在数组的第一个元素处（下标为 0）。</p>

<p>每一步，你可以从下标&nbsp;<code>i</code>&nbsp;跳到下标&nbsp;<code>i + 1</code> 、<code>i - 1</code> 或者 <code>j</code> ：</p>

<ul>
	<li><code>i + 1</code> 需满足：<code>i + 1 &lt; arr.length</code></li>
	<li><code>i - 1</code>&nbsp;需满足：<code>i - 1 &gt;= 0</code></li>
	<li><code>j</code>&nbsp;需满足：<code>arr[i] == arr[j]</code>&nbsp;且&nbsp;<code>i != j</code></li>
</ul>

<p>请你返回到达数组最后一个元素的下标处所需的&nbsp;<strong>最少操作次数</strong>&nbsp;。</p>

<p>注意：任何时候你都不能跳到数组外面。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [100,-23,-23,404,100,23,23,23,3,404]
<strong>输出：</strong>3
<strong>解释：</strong>那你需要跳跃 3 次，下标依次为 0 --&gt; 4 --&gt; 3 --&gt; 9 。下标 9 为数组的最后一个元素的下标。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [7]
<strong>输出：</strong>0
<strong>解释：</strong>一开始就在最后一个元素处，所以你不需要跳跃。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [7,6,9,6,9,6,9,7]
<strong>输出：</strong>1
<strong>解释：</strong>你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>8</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->

<p><strong>个人看法：</strong></p>
一道简单的BFS，和前面做过的跳跃游戏异曲同工，都需要一个visited数组记录已经访问过的位置。不同的是这题不但需要记录下标，还需要记录该位置的值，因为跳转可以到值相同的下标位置。七海Qiaqia7mi的解法非常厉害，值得学习。
