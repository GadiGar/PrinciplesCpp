#include <iostream>
#include <algorithm>

class vect
{
    int sz;
    double* elem;
    int space;
 public:
    vect() : sz(0), elem(nullptr), space(0) {}
    explicit vect(int s) : sz(s), elem(new double[s]), space(s) {
        for (int i = 0; i < sz; ++i)
            elem[i] = 0;
    }

    vect(const vect&);                  // copy constructor
    vect(vect&&);                       // move constructor
    vect& operator=(const vect&);       // copy assignment
    vect& operator=(vect&&);            // move assignment
    ~vect() { delete[] elem; }          // destructor

    double& operator[](int n) { return elem[n]; }
    const double& operator[](int n) const { return elem[n]; }

    int size() const { return sz; }
    int capacity() const { return space; }

    void resize(int newsize);           // growth
    void push_back(double d);
    void reserve(int newalloc);
};
