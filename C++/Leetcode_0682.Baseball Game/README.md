<!-- problem:start -->

# [682. 棒球比赛](https://leetcode.cn/problems/baseball-game)


## 题目描述

<!-- description:start -->

<p>你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。</p>

<p>比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 <code>ops</code>，其中 <code>ops[i]</code> 是你需要记录的第 <code>i</code> 项操作，<code>ops</code> 遵循下述规则：</p>

<ol>
	<li>整数 <code>x</code> - 表示本回合新获得分数 <code>x</code></li>
	<li><code>"+"</code> - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。</li>
	<li><code>"D"</code> - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。</li>
	<li><code>"C"</code> - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。</li>
</ol>

<p>请你返回记录中所有得分的总和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>ops = ["5","2","C","D","+"]
<strong>输出：</strong>30
<strong>解释：</strong>
"5" - 记录加 5 ，记录现在是 [5]
"2" - 记录加 2 ，记录现在是 [5, 2]
"C" - 使前一次得分的记录无效并将其移除，记录现在是 [5].
"D" - 记录加 2 * 5 = 10 ，记录现在是 [5, 10].
"+" - 记录加 5 + 10 = 15 ，记录现在是 [5, 10, 15].
所有得分的总和 5 + 10 + 15 = 30
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>ops = ["5","-2","4","C","D","9","+","+"]
<strong>输出：</strong>27
<strong>解释：</strong>
"5" - 记录加 5 ，记录现在是 [5]
"-2" - 记录加 -2 ，记录现在是 [5, -2]
"4" - 记录加 4 ，记录现在是 [5, -2, 4]
"C" - 使前一次得分的记录无效并将其移除，记录现在是 [5, -2]
"D" - 记录加 2 * -2 = -4 ，记录现在是 [5, -2, -4]
"9" - 记录加 9 ，记录现在是 [5, -2, -4, 9]
"+" - 记录加 -4 + 9 = 5 ，记录现在是 [5, -2, -4, 9, 5]
"+" - 记录加 9 + 5 = 14 ，记录现在是 [5, -2, -4, 9, 5, 14]
所有得分的总和 5 + -2 + -4 + 9 + 5 + 14 = 27
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>ops = ["1"]
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= ops.length <= 1000</code></li>
	<li><code>ops[i]</code> 为 <code>"C"</code>、<code>"D"</code>、<code>"+"</code>，或者一个表示整数的字符串。整数范围是 <code>[-3 * 10<sup>4</sup>, 3 * 10<sup>4</sup>]</code></li>
	<li>对于 <code>"+"</code> 操作，题目数据保证记录此操作时前面总是存在两个有效的分数</li>
	<li>对于 <code>"C"</code> 和 <code>"D"</code> 操作，题目数据保证记录此操作时前面总是存在一个有效的分数</li>
</ul>

<!-- description:end -->

<p><strong>个人看法：</strong></p>
要读懂题目意思。卡在了switch语句，因为我没意识到直接用operation[i]作为switch的表达式会引起一些异常<br>
尤其是类型异常。<br>
然后偷偷看题解，发现可以用 auto 来遍历数组。<br>
第二个卡点是对函数的不熟悉，不知道怎么转换string为int<br>
std::stoi或cstdlib中的std::atoi
