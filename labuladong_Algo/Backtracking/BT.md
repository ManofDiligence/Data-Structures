**回溯算法是什麼？解決回溯算法相關的問題有什麼技巧？如何學習回溯算法？回溯算法代碼是否有規律可循？**

1. 其實回溯算法和我們常說的 DFS 算法非常類似，本質上就是一種暴力窮舉算法。
2. 回溯算法和 DFS 算法的細微差別是：回溯算法是在遍歷「樹枝」，DFS 算法是在遍歷「節點」

**回溯算法框架**
_1. 路徑：也就是已經做出的選擇。_
**This is what edges we already traversed**
**記錄你已經做過的選擇 (current path) **

_2. 選擇列表：也就是你當前可以做的選擇。_
**This is what edges we can traverse to in current situation**

_3. 結束條件：也就是到達決策樹底層，無法再做選擇的條件。_
**This is When the program touch the leaf node (base case)**
**「結束條件」就是遍歷到樹的底層葉子節點** 4. code:
result = []
def backtrack(路徑, 選擇列表):
if 滿足結束條件:
{
result.add(路徑)
return
}
for 選擇 in 選擇列表:
{
做選擇
backtrack(路徑, 選擇列表)
撤銷選擇
}

_其核心就是 for 循環裡面的遞歸，在遞歸調用之前「做選擇」，在遞歸調用之後「撤銷選擇」_

The property of each node have its current traversed path and selection list(containing traversable edge )

**N-ary Tree's traversal**

void traverse(TreeNode\* root){

for(TreeNode\* child: root->children)
{
// preorder (前序遍歷的代碼在進入某一個節點之前的那個時間點執行)
traverse(child);
// postorder (後序遍歷代碼在離開某個節點之後的那個時間點執行)
}

}

**Summary**
_「路徑」和「選擇」是每個節點的屬性，函數在樹上游走要正確處理節點的屬性，那麼就要在這兩個特殊時間點搞點動作_

**回溯算法的核心框架**

1. for 選擇 in 選擇列表:
   # 做選擇
   將該選擇從選擇列表移除
   路徑.add(選擇)
   backtrack(路徑, 選擇列表)
   # 撤銷選擇
   路徑.remove(選擇)
   將該選擇再加入選擇列表
