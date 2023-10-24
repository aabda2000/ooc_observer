#ifndef CCD_H
#define CCD_H

#include "observer.h" /* the base class interface */

typedef struct
{
    Observer super; /* <== inherits Shape */
    int16_t temperature;
    int16_t humidity;
    int16_t pressure;
} CCD;
void CCD_ctor(CCD *const me);
#endif