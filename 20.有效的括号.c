/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (42.03%)
 * Likes:    1728
 * Dislikes: 0
 * Total Accepted:    340.6K
 * Total Submissions: 809.8K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 *
 *
 * 注意空字符串可被认为是有效字符串。
 *
 * 示例 1:
 *
 * 输入: "()"
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: "()[]{}"
 * 输出: true
 *
 *
 * 示例 3:
 *
 * 输入: "(]"
 * 输出: false
 *
 *
 * 示例 4:
 *
 * 输入: "([)]"
 * 输出: false
 *
 *
 * 示例 5:
 *
 * 输入: "{[]}"
 * 输出: true
 *
 */

// @lc code=start
struct list
{
    char c;
    struct list* next;
};
struct list* root = NULL;

void push(char c)
{
    struct list* t = malloc(sizeof(struct list));
    t->c = c;
    t->next = root;
    root = t;
}

char pop()
{
    char c = root->c;
    if(root->next)
    {
        struct list* t = root;
        root = root->next;
        free(t);
    }
    return c;
}

bool isValid(char * s)
{
    char t;
    root = malloc(sizeof(struct list));
    root->c = 0;
    root->next = NULL;
    while(t = *(s++))
    {
        switch (t)
        {
            case ')':
                if(root->c!='(')
                    return 0;
                else
                    pop();
                break;
            case ']':
                if(root->c!='[')
                    return 0;
                else
                    pop();
                break;
            case '}':
                if(root->c!='{')
                    return 0;
                else
                    pop();
                break;
            case '(':
            case '[':
            case '{':
                push(t);
                break;
            default:
                break;
        }
    }
    return !root->next;
}


// @lc code=end

