#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SelectPartitionClass {
public:
	int midposition = 0;
	//int splitNum = 5;
	int sortTest(vector<int>& A) {
		insertSort(A, 0, A.size() - 1);
		for (vector<int>::iterator it = A.begin(); it != A.end(); it++) {
			cout << *it << endl;
		}
		return 0;
	}
	int Select(vector<int>& A, int m, int p, int k) {
		int n, i, j;
		int r = 5;
		if (p - m + 1 <= r) {
			//sort
			return m + k;
		}
		while (true) {
			n = p - m + 1;
			int t = floor(n / r);  // n/5向下取整
			if (t == 1) {
				//只有一组
			}
			else {
				for (i = 1; i <= t; i++) {   //求每一组的中位数
					//sort
					swap(A[m + i - 1], A[m + (i - 1)*r + r/2]);  //交换中位数和第一个数
				}
				j = Select(A, m, m + t - 1, r / 2);
				swap(A[m], A[j]);
				if (k == j - m + 1) {
					return j;
				}
				else if (k < j - m + 1) {
					p = j - 1;
				}
				else {
					k = k - (j - m + 1);
					m = j + 1;
				}
			}
		}
	}
	int PartSelect(vector<int>& A, int n, int k) {
		int m, r, j;
		m = 1; r = n + 1;
		A.push_back(0);
		while (true) {
			j = partition(A, m, r);
			if (k == j) return j;
			else if (k < j) r = j;
			else {
				m = j + 1; //k = k - j; 
			}
		}
	}

	int partition(vector<int>& arr, int startIndex, int endIndex) {
		int key = arr[startIndex];
		int i = startIndex, j = endIndex;

		while (i != j) {
			while (i < j && arr[j] >= key) {
				j--;
			}

			if (i <= j) {
				swap(arr[i], arr[j]);
			}
			while (i < j && arr[i] <= key) {
				i++;
			}
			if (i <= j) {
				swap(arr[i], arr[j]);
			}
		}
		return i;
	}
private:
	int searchInsert(vector<int>& A, int left, int right, int target) {
		while (left <= right) {
			if (target < A[right]) {
				right--;
			}
			else {
				return ++right;
			}
		}
		return right + 1;
	}
	void insertSort(vector<int>& A, int start, int end) {
		int length = end - start + 1;
		for (int i = 1; i < length; i++) {
			int temp = A[start + i];
			int k = searchInsert(A, start, i + start - 1, temp);
			if (k != i + start) {
				for (int j = i + start; j > k; j--) {
					A[j] = A[j - 1];
				}
				A[k] = temp;
			}
		}
	}
	int quickSort() {

	}
	int merge() {

	}
	void mergeSort() {

	}
};


int main() {
	vector<int> arrs = { -1, -5, 3, 9, 2, 0, 1, -2 };
	SelectPartitionClass spc = SelectPartitionClass();
	//cout << arrs[spc.PartSelect(arrs, 7, 5)];
	spc.sortTest(arrs);
	return 0;
}