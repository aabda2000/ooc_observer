#include "subject.h"
#include "observer.h"
#include <assert.h>
#include <stdio.h>
static uint16_t top;
static Observer *observers[NB_OBSERVERS];
static Subject weatherData;

/* constructor */
void Subject_ctor()
{
    top = 0;
}

void Subject_removeObserver(Observer *const me)
{
    int c = 0;
    int trouve = 0;
    while ((c++ < top) && (trouve == 0))
    {
        if (observers[c]->uidObserver == me->uidObserver)
        {
            trouve == 1;
            observers[c] = (Observer *)0;
        }
    }
}
void Subject_registerObserver(Observer *const me)
{
    int trouve = 0;
    int i;
    for (i = 0; i <= top; i++)
    {

        if (observers[i] == (Observer *)0)
        {
            observers[i] = me;
            trouve = 1;
            break;
        }
    }
    if (i == top)
        top++;
}

void Subject_notifyObservers()
{
    for (int i = 0; i < top; i++)
        (observers[i]->vptr->update)(observers[i], weatherData.temperature, weatherData.humidity, weatherData.pressure);
}

void measurementsChanged()
{
    Subject_notifyObservers();
}

void setMeasurements(int16_t temperature, int16_t humidity, int16_t pressure)
{
    weatherData.temperature = temperature;
    weatherData.humidity = humidity;
    weatherData.pressure = pressure;
    measurementsChanged();
}