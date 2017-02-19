#include <iostream>
#include <list>
#include <unordered_map>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

template <class K, class V>
class LRUCache
{
private:
    mutable list< pair<K,V> > m_list;
    unordered_map<K, decltype(m_list.begin()) > m_umap;
    size_t m_max_size;

    void Clean(void)
    {
        while(m_umap.size()>m_max_size)
        {
            auto last_it = m_list.end(); last_it --;
            m_umap.erase(last_it->first);
            m_list.pop_back();
        }
    }
public:

    LRUCache(int m_max_size_) : m_max_size(m_max_size_)
    {
    }

    void Put(const K& key, const V& val)
    {
        auto it = m_umap.find(key);
        if(it != m_umap.end())
        {
            m_list.erase(it->second);
            m_umap.erase(it);
        }
        m_list.push_front(make_pair(key,val));
        m_umap.insert(make_pair(key, m_list.begin()));
        Clean();
    }

    const V& Get(const K& key) const
    {
        if (!Exist(key))
        {
            throw runtime_error("Key does not exist");
        }
        auto it = m_umap.find(key);
        m_list.splice(m_list.begin(), m_list, it->second);
        return it->second->second;
    }

    bool Exist(const K& key) const
    {

        return (m_umap.count(key)>0);
    }

    void Clear(void)
    {
        m_list.clear();
        m_umap.clear();
    }

    size_t Size() const
    {
        return m_list.size();
    }
};

int main()
{
    srand(time(NULL));
        LRUCache <int,string>lCache(5);

        for(int i=1; i<=5; ++i)
        {
            lCache.Put(i,"value");
        }

        for(int i=1; i<=5; ++i)
        {
            cout << " : "<< lCache.Get(i) << endl;
        }
        lCache.Put(1, "1");
        cout <<  endl;
        for(int i=1; i<=5; ++i)
        {
            cout << " : "<< lCache.Get(i) << endl;
        }
        cout << "size: " << lCache.Size() << endl;

        lCache.Clear();
        try
        {
            for(int i=1; i<=5; ++i)
            {
                cout << " : "<< lCache.Get(i) << endl;
            }
        }
        catch(exception& ex)
        {
            cout << ex.what() << endl;
        }

    return 0;
}
