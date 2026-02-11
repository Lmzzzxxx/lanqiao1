result = []
func backtrack(选择列表,路径):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(选择列表,路径)
        撤销选择
          

//example
//输入的数组是nums
vector<vector<int>> res;
vector<vector<int>> subsets(vector<int>& nums) {
    if(nums.empty()) return res;
    // 记录走过的路径
    vector<int> temp;
    backTrace(nums, 0, temp);
    return res;
}

void backTrace(vector<int>& nums, int start, vector<int>& temp){
    res.push_back(temp);

    for(int i = start; i < nums.size(); i++){
        temp.push_back(nums[i]); // 做选择
        backTrace(nums, i + 1, temp); //回溯
        temp.pop_back(); //删除最后一个
    }
}
