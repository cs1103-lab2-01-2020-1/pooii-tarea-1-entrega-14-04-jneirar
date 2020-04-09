//
// Author: marvin on 4/8/20.
//

#ifndef QUICKSORT2_T_H
#define QUICKSORT2_T_H

#include "../tipos.h"

template <typename T>
static int partition_hoare(T* data, int l, int h);

template <typename T>
static void quicksort(T* data, int l, int h);


template <typename T>
class quicksort2_t {
private:
    T* data_;
    int size_;
    int capacity_;
    void add_one();

public:
    quicksort2_t();
    ~quicksort2_t();
    template <typename U>
    friend quicksort2_t<U>& operator<<(quicksort2_t<U>& qs, const string& file_name);

    template <typename U>
    friend quicksort2_t<U>& operator>>(quicksort2_t<U>& qs, const string& file_name);
};

#endif //QUICKSORT2_T_H
