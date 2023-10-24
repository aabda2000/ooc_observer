#include "currentconditionsdisplay.h"
#include <stdio.h>
#include <stdlib.h>
static void CCD_update_(Observer *const me, int16_t temperature, int16_t humidity, int16_t pressure);
static void CCD_display_();

void CCD_ctor(CCD *const me)
{
    static const struct ObserverVtbl vtbl = {&CCD_update_, &CCD_display_};
    Observer_ctor(&me->super);
    me->super.uidObserver = rand() % 1500 + 1;
    me->super.vptr = &vtbl;
}
static void CCD_update_(Observer *const me, int16_t temperature, int16_t humidity, int16_t pressure)
{
    CCD *const me_ = (CCD *)me;
    me_->temperature = temperature;
    me_->humidity = humidity;
    me_->pressure = pressure;
    CCD_display_(me_);
}
static void CCD_display_(CCD *const me)
{
    printf("I m th observer identified by %d :\n temperature= %d, humidity=%d , pressure=%d\n", me->super.uidObserver, me->temperature, me->humidity, me->pressure);
}