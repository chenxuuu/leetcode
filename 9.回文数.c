/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (58.41%)
 * Likes:    1162
 * Dislikes: 0
 * Total Accepted:    402.9K
 * Total Submissions: 689.9K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 * 示例 1:
 *
 * 输入: 121
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 *
 *
 * 示例 3:
 *
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 *
 *
 * 进阶:
 *
 * 你能不将整数转为字符串来解决这个问题吗？
 *
 */

// @lc code=start


bool isPalindrome(int x){
    if(x<0)
        return 0;
    int r = 0;
    int temp = x;
    int max = 0x7fffffff/10;
    while(x)
    {
        if(r>max)
            return 0;
        r = r*10+(x%10);
        x/=10;
    }
    return r == temp;
}


// @lc code=end

