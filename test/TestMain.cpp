#include "../src/main.h"
#include <assert.h>

void testGetTriangleType() {
    assert(getTriangleType(3, 4, 5) == 0);
}

int main() {
    assert(addNumber(5, 2) == 7);
<<<<<<< HEAD
    assert(abc(2)==6);
=======
    assert(Add(123, 456) == 579);
>>>>>>> master
    testGetTriangleType();
    return 0;
}
