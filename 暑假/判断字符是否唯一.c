/**实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

示例 1：

? 输入: s = "leetcode"? 输出: false

示例 2：

? 输入: s = "abc"? 输出: true**/
bool isUnique(char* astr)
{
    bool array[26] = {};
    for(char *ch = astr; *ch != NULL; ch++ )
    {
        int temp = *ch - 'a';
        if(array[temp])
        {
            return false;
        }
        array[temp] = true;
    }
    return true;
}