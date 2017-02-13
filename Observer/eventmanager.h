#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <memory>
#include <vector>
#include "eventlistener.h"
#include "event.h"

class EventManager // ивент менеджера
{
public:
    static EventManager& getInstance(); // пример

    void publishEvent(const Event& ev);

    void addListener(std::shared_ptr<EventListener>& listener/*, const vector<EVENT_TYPE>& ev_type_list*/);
    // добавить ивент

    void removeListener(std::shared_ptr<EventListener>& listener/*, const vector<EVENT_TYPE>& ev_type_list*/);
    //удалить ивент

private:
    EventManager() = default;
    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;
    std::vector<std::weak_ptr<EventListener>> m_listeners;
};
#endif // EVENTMANAGER_H
