#include <iostream>
using namespace std;
class my_array_over
{
    size_t len = 1;
    int *a = new int[1];

public:
    my_array_over() { a[0] = 0; }

    my_array_over(size_t ln, const int *o) : len(ln), a(new int[ln])
    {
        for (size_t n = 0; n < ln; ++n)
            a[n] = o[n];
    }

    ~my_array_over() { delete[] a; }

    // Returns the number of elements in the array
    size_t get_length() const
    {
        return len;
    }

    // Changes an element and returns its old value
    int set(size_t n, int v)
    {
        int tmp = a[n];
        a[n] = v;
        return tmp;
    }

    // Overloads [] so we can access an array element
    int operator[](size_t n) const
    {
        return a[n];
    }
};

void foo(const my_array_over &a2, size_t i)
{
    if (i < a2.get_length())
        std::cout << a2[i] << std::endl;
}

int main()
{
    int zero12[] = {23, 1, 2};
    my_array_over a1(3, zero12);
    a1.set(0, 13);
    foo(a1, 0); // should print 13
    return 0;
}
