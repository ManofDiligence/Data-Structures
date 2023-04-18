**動態規劃是什麼？**
首先，動態規劃問題的一般形式就是求最值。動態規劃其實是運籌學的一種最優化方法，
只不過在計算機問題上應用比較多，比如說讓你求最長遞增子序列呀，最小編輯距離呀等等。
既然是要求最值，核心問題是什麼呢？求解動態規劃的核心問題是窮舉。
因為要求最值，肯定要把所有可行的答案窮舉出來，然後在其中找最值唄。

// Three main points for dynamic programming

1. 雖然動態規劃的核心思想就是窮舉求最值，但是問題可以千變萬化，窮舉所有可行解其實並不是一件容易的事，
   需要你熟練掌握遞歸思維，只有列出正確的「狀態轉移方程」，才能正確地窮舉。
2. 你需要判斷算法問題是否具備「最優子結構」，是否能夠通過子問題的最值得到原問題的最值。
3. 動態規劃問題存在「重疊子問題」，如果暴力窮舉的話效率會很低，
   所以需要你使用「備忘錄」或者「DP table」來優化窮舉過程，避免不必要的計算。

//

# 總之

**Dynamic programming**
**1. 明確 base case。**
**2. 明確「狀態」，也就是原問題和子問題中會變化的變量。**
**3. 明確「選擇」，也就是導致「狀態」產生變化的行為。**
**4. 定義 dp 數組/函數的含義。**

# 1. 自頂向下遞歸的動態規劃

# 遞歸 = recursion

# 自頂向下 = 1: solve the problem from subproblems -> base case.

# 2: when the problem trigger the base case -> return each value of the subproblems.

# 3: combining this value of subproblems to solve the problem

1. def dp(狀態 1, 狀態 2, ...):
   for choice in all possible choice: # 此時的狀態已經因為做了選擇而改變
   result = 求最值(result, dp(狀態 1, 狀態 2, ...)) # max() or min()
   return result

# 2. 自底向上迭代的動態規劃

# 迭代 = loop

# 自底向上 = 1: solve the problem from the base case to the problem itself

# 2: form the up the solution from the previous result

# 初始化 base case

2. dp[0][0][...] = base case
   for 狀態 1 in 狀態 1 的所有取值： # 進行狀態轉移
   for 狀態 2 in 狀態 2 的所有取值：
   for ...
   dp[狀態 1][狀態2][...] = 求最值(選擇 1，選擇 2...)

Question for learning dynamic programming

# fib.cpp

- contains all the method returning the nth term fibonacci number
- from brute force to Dynamic Programming

# coinChange.cpp

- contains all the method returning the minimum number of coin required
- from brute force to Dynamic Programming
- flow for the problem
  - 1. 明確 base case -> when the amount = 0 -> return 0
  - 2. 明確「狀態」 -> we just have to "move" the current amount to be 0 (trigger the base case) -> 所以唯一的「狀態」就是目標金額 amount。
  - 3. 明確「選擇」 -> how the 目標金額 amount change ? 目標金額為什麼變化呢 ?
       因為你在選擇硬幣，你每選擇一枚硬幣，就相當於減少了目標金額。
       所以說所有硬幣的面值(the given coins array)，就是你的「選擇」。
  - 4. 定義 dp 數組/函數的含義 -> dp(n) 表示，输入一个目标金额 n，返回凑出目标金额 n 所需的最少硬币数量。

# 最後總結

1. 第一個斐波那契數列的問題，解釋瞭如何通過「備忘錄」或者「dp table」的方法來優化遞歸樹，並且明確了這兩種方法本質上是一樣的，只是自頂向下和自底向上的不同而已。

2. 第二個湊零錢的問題，展示瞭如何流程化確定「狀態轉移方程」，只要通過狀態轉移方程寫出暴力遞歸解，剩下的也就是優化遞歸樹，消除重疊子問題而已。

**列出狀態轉移方程，就是在解決“如何窮舉”的問題。之所以說它難，一是因為很多窮舉需要遞歸實現，二是因為有的問題本身的解空間複雜，不那麼容易窮舉完整。備忘錄、DP table 就是在追求“如何聰明地窮舉”。用空間換時間的思路，是降低時間複雜度的不二法門，除此之外，試問，還能玩出啥花活？**
