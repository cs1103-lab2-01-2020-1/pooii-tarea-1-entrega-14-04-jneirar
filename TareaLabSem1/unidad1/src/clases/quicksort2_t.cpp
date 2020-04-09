//
// Author: marvin on 4/8/20.
//

#include "quicksort2_t.h"

template <typename T>
quicksort2_t<T>::quicksort2_t() {
    size_ = 0;
    capacity_ = 10;
    data_ = new T[capacity_];
}

template <typename T>
quicksort2_t<T>::~quicksort2_t() {
    size_ = 0;
    capacity_ = 0;
    delete [] data_;
}

template <typename T>
void quicksort2_t<T>::add_one() {
    if (size_ + 1 > capacity_) {
        capacity_ *= 2;
        T* aux = new T[capacity_];
        for (size_t i = 0; i < size_; i++)
            aux[i] = data_[i];
        delete [] data_;
        data_ = aux;
        delete [] aux;
    }
    ++size_;
}

template <typename U>
quicksort2_t<U>& operator<<(quicksort2_t<U> &qs, const string &file_name) {
    ifstream in(file_name);
    if (in.is_open()) {
        U item;
        while (in>>item) {
            qs.add_one();
            qs.data_[qs.size_-1] = item;
        }
    }
    quicksort(qs.data_, 0, qs.size_-1);
    return qs;
}

template <typename U>
quicksort2_t<U>& operator>>(quicksort2_t<U> &qs, const string &file_name) {
    ofstream out(file_name);
    if (out.is_open()) {
        out<<"quicksort2_t sorting"<<endl;
        for (size_t i = 0; i < qs.size_; i++)
            out<<qs.data_[i]<<" ";
    }
    return qs;
}

template <typename T>
static int partition_hoare(T* data, int l, int h) {
    int i = l-1, j = h+1;
    T pivot = data[l];
    while (true) {
        do {
            i++;
        } while (data[i]<pivot);
        do {
            j--;
        } while (data[j]>pivot);
        if (j<=i) return j;
        swap(data[i], data[j]);
    }
}

template <typename T>
static void quicksort(T* data, int l, int h) {
    if (l < h) {
        int p = partition_hoare(data, l, h);
        quicksort(data, l, p);
        quicksort(data, p+1, h);
    }
}


