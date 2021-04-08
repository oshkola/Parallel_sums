#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isEqual(int arr[], int length)
{
    int leftSum{0};
    int rightSum{0};
    int firstEl = 0;
    
    for(int i = length/2; i < length; i++)
    {
        leftSum += arr[firstEl];
        rightSum += arr[i];
        firstEl++;
    }
    return leftSum == rightSum;
}

void rotateArr(int arr[], int length)
{
    int tmp = arr[0];
    
    for(int i = 0; i < length - 1; i++)
        arr[i] = arr[i + 1];
    
    arr[length - 1] = tmp;
}

void printRes(int arr[], int length)
{
    int half_length = length/2;
    int midPoint = half_length;
    vector<int> leftArr(half_length),
                rightArr(half_length);
    
    for(int i = 0; i < half_length; i++)
    {
        leftArr[i] = arr[i];
        rightArr[i] = arr[midPoint];
        midPoint++;
    }
    sort(leftArr.begin(), leftArr.end());
    sort(rightArr.begin(), rightArr.end());
    
    vector<int> result;
    
    if(leftArr[0] < rightArr[0] || leftArr[0] == rightArr[0])
    {
        result = leftArr;
        result.insert(result.end(), rightArr.begin(), rightArr.end());
    }
    else
    {
        result = rightArr;
        result.insert(result.end(), leftArr.begin(), leftArr.end());
    }
    
    for(int i = 0; i < length - 1; i++)
        cout << result[i] << ",";
    cout << result[length -1];
}

int doRoutine(int arr[], int length)
{
    if(isEqual(arr, length))
    {
        printRes(arr, length);
        return 0;
    }
    else
    {
        while(true)
        {
            rotateArr(arr, length);
            if(isEqual(arr, length))
            {
                printRes(arr,length);
                return 0;
            }
        }
    }
    return -1;
}

int main()
{
   int arr[] = {1,2,3,4};
   int length = sizeof(arr)/sizeof(int);
   doRoutine(arr, length);
  
}
