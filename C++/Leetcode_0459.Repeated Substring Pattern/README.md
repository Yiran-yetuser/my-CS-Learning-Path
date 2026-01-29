# [459. 重复的子字符串](https://leetcode.cn/problems/repeated-substring-pattern)


## 题目描述

<!-- description:start -->

<p>给定一个非空的字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;，检查是否可以通过由它的一个子串重复多次构成。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "abab"
<strong>输出:</strong> true
<strong>解释:</strong> 可由子串 "ab" 重复两次构成。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "aba"
<strong>输出:</strong> false
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> s = "abcabcabcabc"
<strong>输出:</strong> true
<strong>解释:</strong> 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp;由小写英文字母组成</li>
</ul>

<!-- description:end -->

<p><strong>个人看法：</strong></p>
“简单”题<p></p>
不过还好我前面做了kmp相关题，思路还是有的<p>
这题实际上更像一道数学题，难点在于思考“重复子字符串”在数学上的充要条件。<br>
我的做法是直接套用kmp的函数来判断两个字符串连在一起怎么样。<br>
Leetcode官方给了一个更短的做法，把kmp函数改造了一下。<br>
总体算难的吧，起码对我这种数学一窍不通的人：*(
