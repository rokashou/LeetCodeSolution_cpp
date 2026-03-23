#include "../leetcode.h"

// 1051.Height Checker

class Solution
{
private:
    void bubbleSort(vector<int>& arr){
        int n = arr.size();
        for (int i = 0; i < n - 1;i++){
            for (int j = 0; j < n - i - 1;++j){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Merge Sort

    void merge(vector<int>& arr,int left, int mid, int right, vector<int>& tempArr){
        // Calculate the start and sizes of two halves.
        int start1 = left;
        int start2 = mid + 1;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Copy elements of both halves into a temporary array.
        for (int i = 0; i < n1;++i){
            tempArr[start1 + i] = arr[start1 + i];
        }
        for (int i = 0; i < n2;++i){
            tempArr[start2 + i] = arr[start2 + i];
        }

        // Merge the sub-array in 'tempArr' back into the original array
        // 'arr' in sorted order.
        int i = 0, j = 0, k = left;
        while(i<n2 && j < n2){
            if(tempArr[start1 + i] <= tempArr[start2 + j]){
                arr[k] = tempArr[start1 + i];
                i += 1;
            }else{
                arr[k] = tempArr[start2 + j];
                j += 1;
            }
            k += 1;
        }

        // Copy remaining elements
        while(i<n1){
            arr[k] = tempArr[start1 + i];
            i += 1;
            k += 1;
        }
        while(j < n2){
            arr[k] = tempArr[start2 + j];
            j += 1;
            k += 1;
        }
    }

    void mergeSort(vector<int>& arr, int left, int right, vector<int>& tempArr){
        if(left >= right){
            return;
        }
        int mid = (left + right) / 2;
        // sort first and second halves recursively
        mergeSort(arr, left, mid, tempArr);
        mergeSort(arr, mid + 1, right, tempArr);
        merge(arr, left, mid, right, tempArr);
    }

    void mergeSort(vector<int>& arr){
        vector<int> tempArray(arr.size());
        mergeSort(arr, 0, arr.size() - 1, tempArray);
    }

    // heap sort
    void heapify(vector<int>& arr, int n, int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // if the left child is larger than the root
        if(left < n && arr[left] > arr[largest])
            largest = left;
        
        // if the right child is larger than the largest so far.
        if(right < n && arr[right] > arr[largest])
            largest = right;

        // if largest is not root swap root with the largest element
        // Recursively heapify the affected sub-tree (i.e. move down).
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(vector<int>& arr){
        int n = arr.size();
        // Build heap; heapify all elements except leaf nodes, in bottom-up order.
        for (int i = n / 2 - 1; i >= 0;i--){
            heapify(arr, n, i);
        }

        // Traverse elements one by one, to move the current root to the end, and
        for (int i = n - 1; i >= 0;--i){
            swap(arr[0], arr[i]);
            // call max heapify on the reduced array.
            heapify(arr, i, 0);
        }
    }

    // Counting Sort
    void countingSort(vector<int>& arr){
        // Create the counting hash map
        unordered_map<int, int> counts;
        // Find the mimimum and maximum values in the array.
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        // Update element's count in the hash map
        for(auto& val : arr)
            counts[val]++;

        int index = 0;
        // Place each element in its current position in the array.
        for (int val = minVal; val <= maxVal; ++val){
            // Append all 'val's together if they exist.
            while(counts[val] > 0){
                arr[index] = val;
                index += 1;
                counts[val] -= 1;
            }
        }
    }

    // Radix Sort
    void bucketSort(vector<int>& arr, int placeValue){
        vector<vector<int>> buckets(10, vector<int>());
        // Sort the respective number based on its digit.
        for(int& val : arr){
            int digit = abs(val) / placeValue;
            digit = digit % 10;
            buckets[digit].push_back(val);
        }

        // Overwrite 'arr' in sorted order of current place digits.
        int index = 0;
        for (int digit = 0; digit < 10;++digit){
            for(int& val:buckets[digit]){
                arr[index] = val;
                index++;
            }
        }
    }

    void radixSort(vector<int>& arr){
        // Find the absolute maximum element to find max number of digits.
        int maxElement = arr[0];
        for(int &val : arr){
            maxElement = max(abs(val), maxElement);
        }

        int maxDigits = 0;
        while(maxElement > 0){
            maxDigits += 1;
            maxElement /= 10;
        }

        // Radix sort, least significant digit place to most significant.
        int placeValue = 1;
        for (int digit = 0; digit < maxDigits;++digit){
            bucketSort(arr, placeValue);
            placeValue *= 10;
        }
    }

public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> sortedHeights = heights;
        //bubbleSort(sortedHeights);
        //mergeSort(sortedHeights);
        //heapSort(sortedHeights);
        //countingSort(sortedHeights);
        
        // build-in sort
        sort(sortedHeights.begin(), sortedHeights.end());

        int count = 0;
        for (int i = 0; i < sortedHeights.size();i++){
            if(heights[i]!=sortedHeights[i])
                count += 1;
        }

        return count;
    }
};