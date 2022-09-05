/*最近點對*/
double dist(pair<double, double> a, pair<double, double> b)
	return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
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
void quicksort(int arr[], int left, int right){
    if (left >= right) return;
    int i = left, j = right;
    int k = (left + right) / 2;
    int pivot = arr[k];
    while (true){
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i >= j) return;
        swap(arr[i], arr[j]);
        i++; j--;
    }
    quicksort(arr, left, j);
    quicksort(arr, i, right);
}
void Merge(vector<int> &Arr, int front, int mid, int end) {
    vector<int> Left(Arr.begin() + front, Arr.begin() + mid + 1);
    vector<int> Right(Arr.begin() + mid + 1, Arr.begin() + end + 1);
    int idxLeft = 0, idxRight = 0;
    Left.insert(Left.end(), INT_MAX);
    Right.insert(Right.end(), INT_MAX);
    for (int i = front; i <= end; i++) {
        if (Left[idxLeft] < Right[idxRight]) {
            Arr[i] = Left[idxLeft];
            idxLeft++;
        } else {
            Arr[i] = Right[idxRight];
            idxRight++;
        }
    }
}
void MergeSort(vector<int> &Arr, int front, int end) {
    if (front >= end)
        return;
    int mid = front + (end - front) / 2;
    MergeSort(Arr, front, mid);
    MergeSort(Arr, mid + 1, end);
    Merge(Arr, front, mid, end);
}
