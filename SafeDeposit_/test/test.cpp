#include <cassert>

#include "safe_depo.h"
#include "valuable.h"

int main()
{

    SafeDeposit safe(5, 7, 10);
    Valuable *item = new Valuable("key", 10);
    assert(safe.add(*item));
    assert(safe.add(*item));
    assert(safe.add(*item));
    assert(safe.add(*item));
    assert(safe.add(*item));
    assert(safe.add(*item));
    assert(safe.add(*item));
    assert(safe.add(*item));
    assert(safe.add(*item));
    assert(safe.add(*item));
    assert(safe.add(*item));

    return 0;
}