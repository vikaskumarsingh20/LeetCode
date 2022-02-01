Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages,
you must instead have the result be placed in the first part of the array nums. More formally,
if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result.
It does not matter what you leave beyond the first k elements.

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if(arr.size() == 0) return 0; 
        int i=1;
        for(int j=1; j<arr.size(); j++){
            if(arr[j] == arr[j-1])
                continue;
            arr[i] = arr[j];
            i++;
        }
        return i;
    }
};
