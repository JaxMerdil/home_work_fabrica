#include "calldispatcher.h"
#include "object.h"
#include <iostream>
#include <algorithm>

CallDispatcher::CallDispatcher()
{
}

void CallDispatcher::connect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    m_mMap.insert({{sender,signal}, {receiver,slot}});
}

void CallDispatcher::disconnect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    auto pair = m_mMap.equal_range(std::pair<Object*, std::string>(sender, signal)); // equal pair iter [first,last)
    std::cout << "Count of slots for signal (Disconect): " << signal << " = "<< m_mMap.count(std::pair<Object*, std::string>(sender, signal))<< std::endl;
    auto it = pair.first;

    for(; it != pair.second; ++it)
    {
        if(it->second.first == receiver && it->second.second == slot)
        {
            m_mMap.erase(it);
            break;
        }
    }
}

void CallDispatcher::sendSignal(Object *sender, const std::string& signal)
{
    std::cout << "Count of slots for signal (sendSignal): " << signal << " = "<< m_mMap.count(std::pair<Object*, std::string>(sender, signal))<< std::endl;

    auto pair = m_mMap.equal_range(std::pair<Object*, std::string>(sender, signal));
    auto it = pair.first;

    for(; it != pair.second; ++it)
    {
        std::pair<Object*, std::string> t1 = it->second;
        t1.first->dispatchMethod(t1.second);
    }
}
