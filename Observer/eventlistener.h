#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "event.h"

class EventListener // слушатель ивента
{
public:
    virtual void notify(const Event& ev) = 0;

    virtual ~EventListener() {}
};


#endif // EVENTLISTENER_H
