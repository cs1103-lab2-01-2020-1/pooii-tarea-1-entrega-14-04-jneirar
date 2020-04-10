//
// Author: marvin on 4/8/20.
//

#ifndef QUICKSORT_T_H
#define QUICKSORT_T_H

#include "../tipos.h"


class quicksort_t {
private:
    int* data_;
    int size_;
    int capacity_;
    void add_one();

public:
    quicksort_t();
    ~quicksort_t();
    int partition_hoare(int* data, int l, int h);
    void quicksort(int* data, int l, int h);
    friend quicksort_t& operator<<(quicksort_t& qs, const string& file_name);
    friend quicksort_t& operator>>(quicksort_t& qs, const string& file_name);
};

#endif //QUICKSORT_T_H
