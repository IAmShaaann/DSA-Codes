int merge(vector<int> arr, int low, int mid, int high){
    int count = 0;
    int j = mid + 1; // find the center.
    for(int i = low;i<= mid;i++){ //run a loop to the left half of the array.
        while(j<= high and arr[i] > (long) 2 * arr[j]){
            j++;
        }
        count += (j - (mid + 1));
    }
    vector<int> temp;
    int left = low, right = mid+1;
    while(left<= mid and right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left++]);
        }else{
            temp.push_back(arr[right++]);
        }
    }
    while(left<= mid){
        temp.push_back(arr[left++]);
    }
    while(right<= high){
        temp.push_back(arr[right++]);
    }
    for(int i =low;i<high ;i++){
        arr[i] = arr[i=low];
    }
    return count;
}