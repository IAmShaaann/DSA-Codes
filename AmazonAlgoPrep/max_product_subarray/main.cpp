#include <iostream>
#include <vector>
using namespace std;
int bad_brute_force(vector<int> arr)
{
    int prod = 1;
    int maxProd = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            for (int k = j; k < arr.size(); k++)
            {

                prod = prod * arr[k];
                maxProd = max(maxProd, prod);
                if (prod == 0)
                    prod = 1;
            }

            prod = 1;
        }
    }
    return maxProd;
}
int better_brute_force(vector<int> arr)
{
    int prod = 1;
    int maxProd = 1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            prod *= arr[j];
            maxProd = max(prod, maxProd);
            if (prod == 0)
                prod = 1;
        }
        prod = 1;
    }
    return maxProd;
}
int optimal(vector<int> arr)
{
    int prod1 = arr[0];
    int prod2 = arr[0];
    int maxProd = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        // prod1 = max({arr[i], prod1 * arr[i], prod2 * arr[i]});
        // prod2 = min({arr[i], prod1 * arr[i], prod2 * arr[i]});
        maxProd = max(prod1, prod2);
    }
    return maxProd;
}
int solution(vector<int> arr)
{
    int pre = 1;
    int maxProd = 1;
    int suff = 1;
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        if (pre == 0)
            pre = 1;

        if (suff == 0)
            suff = 1;

        pre *= arr[i];
        suff *= arr[n - i - 1];
        maxProd = max(maxProd, max(pre, suff));
    }
    return maxProd;
}

int main()
{
    int arr[] = {1, 2, 0, 3, -4, -5};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    cout << solution(values);
    return 0;
}