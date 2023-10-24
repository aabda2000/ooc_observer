
#ifndef OBSERVER_H
#define OBSERVER_H
#include <stdint.h>

struct ObserverVtbl;
typedef struct
{
    const struct ObserverVtbl *vptr;
    int16_t uidObserver;

} Observer;

struct ObserverVtbl
{
    void (*update)(Observer *const me, int16_t temp, int16_t humidity, int16_t pressure);
    void (*display)(Observer *const me);
};

void Observer_ctor(Observer *const me);

static inline void Observer_update(Observer *const me, int16_t temp, int16_t humidity, int16_t pressure)
{
    (me->vptr->update)(me, temp, humidity, pressure);
}

static inline void Observer_display(Observer *const me)
{
    (me->vptr->display)(me);
}
#endif