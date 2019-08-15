#include "vect.h"

vect::vect(const vect& arg)
    : sz(arg.sz), elem(new double[arg.sz])
{
    std::copy(arg.elem, arg.elem+sz, elem);  // std::copy()
    // was originally arg.elem.sz, but i think it was a mistake
}

vect::vect(vect&& a)
    : sz(a.sz), elem(a.elem)
{
    // make a the empty vector
    a.sz = 0;
    a.elem = nullptr;
}

vect& vect::operator=(vect&& a)
{
    delete[] elem;          // deallocate old space
    elem = a.elem;
    a.elem = nullptr;
    sz = a.sz;
    a.sz = 0;
    return *this;
}

void vect::reserve(int newalloc)
{
    if (newalloc <= space) return;      // never decrease allocation
    double* p = new double[newalloc];   // allocate new space
    for (int i = 0; i < sz; ++i)
        p[i] = elem[i];                 // copy old elements
    delete[] elem;
    elem = p;
    space = newalloc;
}

void vect::resize(int newsize)
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i)
        elem[i] = 0;                    // initialize only the new elements
    sz = newsize;
}

void vect::push_back(double d)
{
    if (space == 0)
        reserve(8);                     // start with space for 8 elements
    else if (sz == space)
        reserve(2 * space);             // get more space
    elem[sz] = d;
    ++sz;
}

vect& vect::operator=(const vect& a)
{
    if (this == &a) return *this;       // self assignment, nothing to do
    if (a.sz <= space) {
        for (int i = 0; i < a.sz; ++i)
            elem[i] = a.elem[i];
        sz = a.sz;
        return *this;
    }
    double* p = new double[sz];
    for (int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;
    space = sz = a.sz;
    elem = p;
    return *this;
}
