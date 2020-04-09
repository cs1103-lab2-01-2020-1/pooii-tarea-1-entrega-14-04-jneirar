//
// Author: marvin on 4/8/20.
//

#include "quicksort_t.h"

quicksort_t::quicksort_t() : capacity_{10}, size_{0} {
    data_ = new int[capacity_];
}

quicksort_t::~quicksort_t() {
    capacity_ = 10;
    size_ = 0;
    delete [] data_;
}

void quicksort_t::add_one() {
    if (size_ + 1 > capacity_) {
        capacity_ *= 2;
        int* aux = new int[capacity_];
        for (size_t i = 0; i < size_; i++)
            aux[i] = data_[i];
        delete [] data_;
        data_ = aux;
    }
    ++size_;
}

quicksort_t& operator<<(quicksort_t &qs, const string &file_name) {
    ifstream in(file_name);
    if (in.is_open()) {
        int item;
        while (in>>item) {
            qs.add_one();
            qs.data_[qs.size_-1] = item;
        }
    }
    qs.quicksort(qs.data_, 0, qs.size_ - 1);
    return qs;
}

int quicksort_t::partition_hoare(int* data, int l, int h) {
    int i = l-1, j = h+1;
    int pivot = data[l];
    while (true) {
        do{
            i++;
        } while (data[i]<pivot);
        do{
            j--;
        } while (data[j]>pivot);
        if (j<=i) return j;
        swap(data[i], data[j]);
    }

}

void quicksort_t::quicksort(int *data, int l, int h) {
    if (l < h) {
        int p = partition_hoare(data, l, h);
        quicksort(data, l, p);
        quicksort(data, p+1, h);
    }
}

quicksort_t& operator>>(quicksort_t &qs, const string &file_name) {
    ofstream out(file_name);
    if (out.is_open()) {
        out<<"quicksort_t sorting"<<endl;
        for (size_t i = 0; i < qs.size_; i++)
            out<<qs.data_[i]<<" ";
    }
    return qs;
}
