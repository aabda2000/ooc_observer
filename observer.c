#include "observer.h"
#include <assert.h>
#include "subject.h"
/* Shape's prototypes of its virtual functions */
static void Observer_update_(Observer *const me, int16_t temperature, int16_t humidity, int16_t pressure);
static void Observer_display_();
/* constructor */
void Observer_ctor(Observer *const me)
{
    static const struct ObserverVtbl vtbl = {&Observer_update_, &Observer_display_};
    me->vptr = &vtbl;
}
/* Observer class dummy implementations of its virtual functions... */
static void Observer_update_(Observer *const me, int16_t temperature, int16_t humidity, int16_t pressure)
{
    assert(0);
}

static void Observer_display_()
{
    assert(0);
}
