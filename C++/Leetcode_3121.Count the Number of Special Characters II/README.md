---
comments: true
difficulty: 中等
edit_url: https://github.com/doocs/leetcode/edit/main/solution/3100-3199/3121.Count%20the%20Number%20of%20Special%20Characters%20II/README.md
rating: 1411
source: 第 394 场周赛 Q2
tags:
    - 哈希表
    - 字符串
---

<!-- problem:start -->

# [3121. 统计特殊字母的数量 II](https://leetcode.cn/problems/count-the-number-of-special-characters-ii)

## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>word</code>。如果 <code>word</code> 中同时出现某个字母 <code>c</code> 的小写形式和大写形式，并且<strong> 每个 </strong>小写形式的 <code>c</code> 都出现在第一个大写形式的 <code>c</code> 之前，则称字母 <code>c</code> 是一个 <strong>特殊字母</strong> 。</p>

<p>返回 <code>word</code> 中 <strong>特殊字母</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "aaAbcBC"</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>特殊字母是 <code>'a'</code>、<code>'b'</code> 和 <code>'c'</code>。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "abc"</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中不存在特殊字母。</p>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "AbBCab"</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中不存在特殊字母。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>word</code> 仅由小写和大写英文字母组成。</li>
</ul>

<!-- description:end -->
<p><strong>个人看法：</strong></p>
这道题实际上做法很容易，难点在于如何选择更快的方法。<br>
<strong>大小写字母的ASCII规律：</strong>
1. 对于大写英文字母：二进制从右往左第 6 个比特一定是 0。<br>
2. 对于小写英文字母：二进制从右往左第 6 个比特一定是 1。<br>
3. 对于任何英文字母：小写字母的二进制低 5 位，等于其大写字母的二进制低 5 位。<br>
实际实现中一般采用位运算处理该类题目，并且可以采用整数代替数组记录字母状态（因为数据个数有限）
