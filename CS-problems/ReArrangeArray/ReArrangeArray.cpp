// ReArrangeArray.cpp
// Given an array of integers and a specified mode,
// rearrange the values in the array, orrding to the 
// specified mode.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class reArrangeArray
{
public:
    typedef enum {
        ODD_ON_LEFT,
        EVEN_ON_LEFT
    }ReArrangeMode;

    void Swap(int nums[], int n, int left, int right)
    {
        int leftTemp = nums[left];
        nums[left] = nums[right];
        nums[right] = leftTemp;
    }

    void ReArrange(int nums[], int n, ReArrangeMode mode)
    {
        if (n <= 0)
            return;

        switch (mode)
        {
            case ODD_ON_LEFT:
            {
                int left = 0;
                int right = n - 1;
                while (left < right)
                {
                    // if the left is even and the right is odd, switch them and 
                    // decrement both indicies
                    if (nums[left] % 2 == 0 && nums[right] % 2 != 0)
                    {
                        Swap(nums, n, left, right);
                        left++;
                        right--;
                    }

                    // if both the left and the right are odd, don't make changes
                    // but increment the left index
                    else if (nums[left] % 2 != 0 && nums[right] % 2 != 0)
                    {
                        left++;
                    }

                    // if both the left and the right are even, don't make any
                    // changes, but decrement the right index
                    else if (nums[left] % 2 == 0 && nums[right] % 2 == 0)
                    {
                        right--;
                    }

                    // if the left is already odd and the right is even, simply
                    // update the indicies
                    else {
                        left++;
                        right--;
                    }
                }

                break;
            }
            case EVEN_ON_LEFT:
            {
                int left = 0;
                int right = n - 1;
                while (left < right)
                {
                    // if the left is odd and the right is even, switch them and 
                    // decrement both indicies
                    if (nums[left] % 2 != 0 && nums[right] % 2 == 0)
                    {
                        Swap(nums, n, left, right);
                        left++;
                        right--;
                    }

                    // if both the left and the right are even, don't make changes
                    // but increment the left index
                    else if (nums[left] % 2 == 0 && nums[right] % 2 == 0)
                    {
                        left++;
                    }

                    // if both the left and the right are odd, don't make any
                    // changes, but decrement the right index
                    else if (nums[left] % 2 != 0 && nums[right] % 2 != 0)
                    {
                        right--;
                    }

                    // if the left is already even and the right is odd, simply
                    // update the indicies
                    else {
                        left++;
                        right--;
                    }
                }
                break;
            }
        }
    }

    void PrintArray(int nums[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << nums[i] << ",";
        cout << endl << endl;
    }

    void test(int nums[], int n, ReArrangeMode mode)
    {

        cout << "Mode: ";

        // output the mode
        switch (mode)
        {
        case ODD_ON_LEFT:
            cout << "Odd numbers on the left" << endl;
            break;
        case EVEN_ON_LEFT:
            cout << "Even numbers on the left" << endl;
        }
    
        cout << endl;

        cout << "Array before re-ordering:" << endl;
        PrintArray(nums, n);
        ReArrange(nums, n, mode);
        cout << "Array after re-ordering:" << endl;
        PrintArray(nums, n);

        cout << "---------------------------" << endl << endl;
    }
};

int main()
{
    int nums[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    reArrangeArray *test = new reArrangeArray();
    test->test(nums, size(nums), reArrangeArray::ReArrangeMode::ODD_ON_LEFT);

    int nums2[] = { 2, 1 };
    test->test(nums2, size(nums2), reArrangeArray::ReArrangeMode::ODD_ON_LEFT);

    int nums3[] = { -1, 0, 1 };
    test->test(nums3, size(nums3), reArrangeArray::ReArrangeMode::ODD_ON_LEFT);

    int nums4[] = { -21,17,0,-12,12,223,5,9,7,0,0,12,13,-5 };
    test->test(nums4, size(nums4), reArrangeArray::ReArrangeMode::EVEN_ON_LEFT);

    test->test(nullptr, 0, reArrangeArray::ReArrangeMode::EVEN_ON_LEFT);

    string exit;
    cout << "Press enter to exit..." << endl;
    getline(cin, exit);

    free(test);
    return 0;
}

