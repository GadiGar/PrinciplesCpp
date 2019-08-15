#include "vect.h"

void print_vec(const vect& vec)
{
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << i << ": " << vec[i] << '\t';
    }
    std::cout << "\n";
}

int main()
{
    vect a(3);
    a[1] = 3.14;
    print_vec(a);
    vect b = a;
    print_vec(b);
}
