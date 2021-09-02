#include <iostream>
//#include "functions.h"
#include "functions.cpp"

using namespace std;

int main() {
    Point p;
    p.x = -1;
    p.y = -1;
    int l0 = -9;
    CheckRes checking = check(&p, l0);
    if (checking.inside){
        cout << p.x << " " << p.y << " " << l0 << endl;
        cout << checking.step << " step";
    }
    else cout << "No";
    return 0;
}
