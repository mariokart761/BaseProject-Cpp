#include "../src/main.h"
#include <assert.h>

void testGetTriangleType() {
    assert(getTriangleType(3, 4, 5) == 0);
}

int main() {
    assert(addNumber(5, 2) == 7);
    assert(Add(9453,8,9,17) == 9487);
    testGetTriangleType();
    return 0;
}
