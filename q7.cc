#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <exception>
using namespace std;

class m2dvector {
    vector<int> vi = {0, 0};

public:
    m2dvector(vector<int> some_vi) : vi(some_vi) {
        if (some_vi.size() > 2)
            throw std::invalid_argument("Input vector should have size 2.");
    }

    const vector<int>& get_data() const {
        return vi;
    }
};

// Question 7.1 - Output operator
ostream& operator<<(ostream& out, const m2dvector& v) {
    out << "<" << v.get_data()[0] << " "
        << v.get_data()[1] << ">";
    return out;
}

// Question 7.2 - Input operator
istream& operator>>(istream& in, m2dvector& v) {
    char first, last;
    int x, y;

    if (!(in >> first))
        return in;

    if (first == '<' && (in >> x >> y >> last) && last == '>') {
        v = m2dvector({x, y});
    }
    else {
        in.setstate(ios::badbit);
    }

    return in;
}

int main() {
    try {
        vector<int> vi = {11, 12, 13, 14, 15};
        m2dvector z1({vi[0], vi[1]});
        m2dvector z2({vi[3], vi[4]});

        cout << z1 << endl; // should print: <11 12>
        cout << z2 << endl; // should print: <14 15>

        string s1 = "<11 12>    <13 14>a";
        istringstream iss(s1);

        iss >> z2 >> z1;

        cout << z1 << endl; // should print: <13 14>
        cout << z2 << endl; // should print: <11 12>

        char c;
        iss >> c;
        cout << c << endl; // should print: a

        ostringstream oss;
        oss << z2;
        string so = oss.str();

        for (char c : so)
            if (c == '\n') {
                cout << "Output contains a newline\n";
                return 0;
            }

        cout << "Output does not contain a newline\n";

    } catch (...) {
        throw;
    }

    return 0;
}
