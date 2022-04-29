#include <iostream>
#include "vector/vector.hpp"

using namespace std;

int main(int argc, char ** argv) {
    vectorProto<int> vectorInt;
    for (int i = 0; i < 64; ++i) {
        vectorInt.push(i);
    }

    cout << vectorInt.getCapacity();
    vectorInt.out();
}
