#include <iostream>
using namespace std;
class person {
int age;
public:
person(int a = 10) : age(a) {}
int get_age() const;
};
// code below
int person::get_age() const {
return age;
}
int main() {
person p1;
cout << p1.get_age() << endl; // print 10
//code
p1 = person(25);
cout << p1.get_age() << endl; // print 25
return 0;
}
