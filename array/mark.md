1. 一般来说，双指针的题目：
1）若需要快慢指针（一个在前，一个在后+1），则定义可能只需定义慢指针，一般循环为遍历数组的元素，即 for(const auto& num : nums)
2）若为左右指针，则一般要定义左右指针，一般循环为比较两个指针，即 while(left < right)

2. 题目若要求复杂度为O(logn)，一般为二分查找类题目
left = 0, right = nums.size() - 1;
while (left <= right) {
    const auto mid = (left + right) >> 1;
    if (nums[mid] >= target)    // lower_bound
            or
    if (nums[mid] > target) // upper_bound
        right = mid - 1;
    else
        left = mid + 1;
    
    return left;
}

3. 回溯算法（back tracking）
result = {}；
void backtrack(路径, 选择列表) {
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        (剪枝)
        做选择
        backtrack(路径, 选择列表)
        撤销选择
}
    