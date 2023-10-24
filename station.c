#include "subject.h"  /* Rectangle class interface */
#include "observer.h" /* Circle class interface */
#include "currentconditionsdisplay.h"
#include <stdio.h> /* for printf() */
int main()
{
    Subject s;
    CCD ccd_1;
    CCD ccd_2;
    Subject_ctor(&s);
    CCD_ctor(&ccd_1);
    CCD_ctor(&ccd_2);
    Subject_registerObserver((Observer *)&ccd_1);
    Subject_registerObserver((Observer *)&ccd_2);
    setMeasurements(12, 12, 12);
}