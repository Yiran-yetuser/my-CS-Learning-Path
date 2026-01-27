# [28. 找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string)


## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>haystack</code> 和 <code>needle</code> ，请你在 <code>haystack</code> 字符串中找出 <code>needle</code> 字符串的第一个匹配项的下标（下标从 0 开始）。如果&nbsp;<code>needle</code> 不是 <code>haystack</code> 的一部分，则返回&nbsp; <code>-1</code><strong> </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>haystack = "sadbutsad", needle = "sad"
<strong>输出：</strong>0
<strong>解释：</strong>"sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>haystack = "leetcode", needle = "leeto"
<strong>输出：</strong>-1
<strong>解释：</strong>"leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= haystack.length, needle.length &lt;= 10<sup>4</sup></code></li>
	<li><code>haystack</code> 和 <code>needle</code> 仅由小写英文字符组成</li>
</ul>

<p><strong>个人看法：</strong></p>
<p>如果用最简单的想法：暴力匹配，那确实是简单题</p>
<p>时间复杂度 O(mn)，有点太大了</p>
<p>好的做法是kmp算法，只能现学了，但是真的很厉害，在b站上看到一个很好的视频解释kmp</p>
https://www.bilibili.com/video/BV18k4y1m7Ar/?share_source=copy_web&vd_source=ee5b78cdced6129da2cd7a598a7089b2




