#ifndef _SELF_H
#define _SELF_H

class vector{
    public:
    
    typedef long long int index_t;
    typedef long long int ssize_t;

    vector();

    vector(ssize_t N);

    vector(ssize_t N,int new_val);

    vector(const vector& other_vec);

    ~vector();

    void show(const char* msg) const;

    ssize_t size() const;

    ssize_t max_size() const;

    typedef enum status {
                          SUCCESS=1,
                          INVALID_INDEX,
                          VECTOR_EMPTY,
                          INDEX_OUT_OF_RANGE}status_t;

    status_t push_back(int new_val);
    status_t pop_back(int* element);

    status_t get(index_t index,int* element);
    status_t set(index_t index,int new_val);

    status_t sort(index_t index,int* p_arr);

    status_t serach(index_t s_num,int* p_arr) const;

    private:
      int* arr;
      int N;
};

#endif
