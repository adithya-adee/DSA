#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end - 1];
        arr[end - 1] = temp;
        start++;
        end--;
    }
}

void rotateArraybyK(vector<int> &arr, int k)
{
    size_t length{arr.size()};
    if (length <= 1)
    {
        return;
    }

    k = k % length;
    if (k == 0)
    {
        return; // No rotation required
    }

    reverse(arr, 0, length);
    reverse(arr, 0, k);
    reverse(arr, k, length);
}

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        int num, k;
        cin >> num; // Reading input from STDIN
        cin >> k;

        vector<int> arr;
        for (size_t i = 0; i < num; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        rotateArraybyK(arr, k);

        for (int val : arr)
        {
            cout << val << " ";
        }
        cout << endl;

        n--;
    }

    return 0;
}
