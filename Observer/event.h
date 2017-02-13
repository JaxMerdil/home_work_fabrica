#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event
{
public:
    Event ();

    Event (const std::string& description);

    const std::string& getDescription() const;

private:
    std::string m_description; // м_описание ивента
};



#endif // EVENT_H
