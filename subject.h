#ifndef SUBJECT_H
#define SUBJECT_H
#include <stdint.h>
#include "observer.h"
/* Subject's attributes... */

#define NB_OBSERVERS 10
typedef struct
{
    int16_t temperature; 
    int16_t humidity;    
    int16_t pressure;
} Subject;

/* Subject's operations (Subject's interface)... */
void Subject_ctor();
void Subject_registerObserver(Observer *const me);
void Subject_removeObserver(Observer *const me);
void setMeasurements(int16_t temperature, int16_t humidity, int16_t pressure);
void measurementsChanged();
#endif
