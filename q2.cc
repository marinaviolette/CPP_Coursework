#include <iostream>
using namespace std;
template <typename T>
class person {
T age;
public:
person() : age(10) {}
person(T a) : age(a) {}
T get_age() const;
void set_age(T a);
};
//code below
template <typename T>
T person<T>::get_age() const {
return age;
}
template <typename T>
void person<T>::set_age(T a) {
age = a;
}
int main() {
person<unsigned long> p1;
p1.set_age(25);
cout << p1.get_age() << endl;
return 0;
}
