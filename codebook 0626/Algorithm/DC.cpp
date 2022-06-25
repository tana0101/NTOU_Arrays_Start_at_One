/*最近點對*/
double dist(pair<double, double> a, pair<double, double> b) {
	return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}
double closest(int l, int r) {
	if (l >= r)
		return 10000;
	int mid = (l + r) / 2;
	double radl = closest(l, mid);
	double radr = closest(mid + 1, r);
	double range = min(radl, radr), middle = (point[mid].first + point[mid + 1].first) / 2, minimum;
	minimum = range;
	for (int i = mid + 1; i <= r && point[i].first < middle + range; i++) {
		for (int j = mid; j >= l && point[j].first > middle - range; j--) {
			minimum = min(minimum, dist(point[i], point[j]));
		}
	}
	return minimum;
}
/*Quick Sort*/
void quicksort(int array[], int left, int right){
    if (left >= right) return;
    int i = left, j = right;
    int k = (left + right) / 2; // 可以隨便選
    int pivot = array[k];
    while (true){
        // 小於等於改成小於，就不必偵測陣列邊界。
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i >= j) return;
        // 代價：等於pivot的數字，一直做交換。
        swap(array[i], array[j]);
        i++; j--;
    }
    // 代價：array[i]不一定就是pivot。
    quicksort(array, left, j);
    quicksort(array, i, right);
}
/*Merge Sort*/
void Merge(vector<int> &Array, int front, int mid, int end) {
    vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
    vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);
    int idxLeft = 0, idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
    // Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into Array[i]
    for (int i = front; i <= end; i++) {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
            Array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        } else {
            Array[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}
void MergeSort(vector<int> &Array, int front, int end) {
    if (front >= end)
        return;
    int mid = front + (end - front) / 2;
    MergeSort(Array, front, mid);
    MergeSort(Array, mid + 1, end);
    Merge(Array, front, mid, end);
}
