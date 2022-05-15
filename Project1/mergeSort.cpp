#include <cstdio>
#include <vector>

using namespace std;

void merge(vector<int>* list, int n, int m, int k) {
	int st1 = n;
	int end1 = m;
	int st2 = m + 1;
	int end2 = k;
	vector<int> temp;
	while (st1 <= end1 && st2 <= end2) {
		if (list->at(st1) > list->at(st2)) {
			temp.push_back(list->at(st1));
		}
		else {
			temp.push_back(list->at(st2));
		}
	}
	while (st1 <= end1) {
		temp.push_back(list->at(st1));
	}
	while (st2 <= end2) {
		temp.push_back(list->at(st2));
	}
	copy(temp.begin(), temp.end(), list + st1);
}


void mergeSort(vector<int>* list, int start, int end) {
	if (start==end) return;
	int mid = (start + end) >> 1;
	mergeSort(list,start, mid);
	mergeSort(list,mid + 1, end);

	return merge(list,start, mid, end);


}

int main() {



	return 0;
}