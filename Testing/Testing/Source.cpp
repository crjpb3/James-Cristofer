#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int arr[5];
    int arr_size = *(&arr + 1) - arr;

    cout << arr_size << endl;

    return 0;
}