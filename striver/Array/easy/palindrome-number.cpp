
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int a{x}, store{}, mod{};
        while (a != 0)
        {
            mod = a % 10;
            a = a / 10;
            store = store * 10 + mod;
        }
        return x == store;
    }
};

/* Brute Force Approach

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string num = std::to_string(x);
        int i{}, j = num.length() - 1;
        while (i <= j)
        {
            if (num[i] != num[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
}; */