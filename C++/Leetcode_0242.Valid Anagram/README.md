<!-- problem:start -->

# [242. 有效的字母异位词](https://leetcode.cn/problems/valid-anagram)

[English Version](/solution/0200-0299/0242.Valid%20Anagram/README_EN.md)

## 题目描述

<!-- description:start -->

<p>给定两个字符串 <code>s</code> 和 <code>t</code> ，编写一个函数来判断 <code>t</code> 是否是 <code>s</code> 的 <span data-keyword="anagram">字母异位词</span>。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> s = "anagram", t = "nagaram"
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "rat", t = "car"
<strong>输出: </strong>false</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> 和 <code>t</code>&nbsp;仅包含小写字母</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶:&nbsp;</strong>如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？</p>

<!-- description:end -->
<p><strong>个人看法：</strong></p>
简单题，额外创建数组即可（高级的名字加哈希表？）<p></p>
要兼容unicode字符的进阶我还不会做。似乎要用map容器？留给以后回来看看
