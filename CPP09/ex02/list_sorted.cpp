# include "PmergeMe.hpp"
# include <iterator>

void merge(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right) {
    (void) lst;
    std::list<int> L;
    std::list<int> R;

    for (std::list<int>::iterator it = left; it != middle; ++it)
        L.push_back(*it);
    for (std::list<int>::iterator it = middle; it != right; ++it)
        R.push_back(*it);
    std::list<int>::iterator it = left;
    while (!L.empty() && !R.empty()) {
        if (L.front() <= R.front()) {
            *it++ = L.front();
            L.pop_front();
        } else {
            *it++ = R.front();
            R.pop_front();
        }
    }
    while (!L.empty()) {
        *it++ = L.front();
        L.pop_front();
    }
    while (!R.empty()) {
        *it++ = R.front();
        R.pop_front();
    }
}

void insertionSort(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator right) {
    (void) lst;

    for (std::list<int>::iterator it = left; it != right; ++it) {
        int key = *it;
        std::list<int>::iterator jt = it;
        while (jt != left && *--jt > key) {
            std::iter_swap(jt, jt++);
            --jt;
        }
    }
}

void mergeInsertionSort(std::list<int>& lst, std::list<int>::iterator left, std::list<int>::iterator right) {
    int threshold = 16;
    (void) lst;

    if (std::distance(left, right) > 0) {
        if (std::distance(left, right) <= threshold) {
            insertionSort(lst, left, ++right);
        } else {
            std::list<int>::iterator middle = left;
            std::advance(middle, std::distance(left, right) / 2);
            mergeInsertionSort(lst, left, middle);
            mergeInsertionSort(lst, middle, right);
            merge(lst, left, middle, right);
        }
    }
}