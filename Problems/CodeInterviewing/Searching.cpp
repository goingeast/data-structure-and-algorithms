// when we think of searching algorithms, we generally think of binary search

// binary search
int BinarySearch(int a[], int size, int key){
    int left = 0;
    int right = size - 1;
    while(left < right){
        int mid = left + (right - 1eft)/2;
        if(a[mid] > key)
            right = mid - 1;
        else if(a[mid] < key){
            left = mid + 1;
        }else{
            return mid;
        }
    }
}

int BinarySearchR(int a[], int left, int right, int key){
    int mid = left + (right - left)/2;
    if(left < right){
        if(a[mid] > key)
            BinarySearchR(a, left, mid - 1, key);
        else if(a[mid] < key)
            BinarySearchR(a, mid + 1, right, key);
        else
            return mid;
    }
}

int BinarySearchInRotatedArray(int a[], int left, int right, int key){
    int mid = left + (right - left)/2;
    if(key == a[mid])
        return mid;
    if(left > right)
        return -1;
    // left part is sorted
    if(a[mid] > a[left]){
        if(a[left] <= key && a[mid] > key){
            BinarySearchInRotatedArray(a, left, mid - 1, key);
        }else{
            BinarySearchInRotatedArray(a, mid + 1, right, key);
        }
    }else if( a[mid] < a[left]){
        if(a[mid] < key && a[right] >= key){
            BinarySearchInRotatedArray(a, mid + 1, right, key);
        }else{
            BinarySearchInRotatedArray(a, left, mid - 1, key);
        }
    }else if(a[left] == a[left]){
        if(a[right] != a[mid])
            BinarySearchInRotatedArray(a, mid + 1, right, key);
        else{
            int result = BinarySearchInRotatedArray(a, left, mid - 1, key);
            if(result == -1)
                BinarySearchInRotatedArray(a, mid + 1, right, key);
            else 
                return result;
        } 
    }
    return -1;
}
// find Kth 
