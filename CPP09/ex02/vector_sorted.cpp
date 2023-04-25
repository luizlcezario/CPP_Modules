# include "PmergeMe.hpp"

void merge(std::vector<int>& v, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[middle + 1 + j];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }
    while (i < n1) {
        v[k++] = L[i++];
	}
    while (j < n2) {
        v[k++] = R[j++];
    }
}
void insertionSort(std::vector<int>& v, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= left && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void mergeInsertionSort(std::vector<int>& v, int left, int right) {
    int threshold = 16; 

    if (left < right) {
        if (right - left <= threshold) {
            insertionSort(v, left, right);
        } else {
            int middle = left + (right - left) / 2;
            mergeInsertionSort(v, left, middle);
            mergeInsertionSort(v, middle + 1, right);
            merge(v, left, middle, right);
        }
    }
}