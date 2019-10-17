/* ---------------
 * Jorge L. Garcia
 * //2019
 * ---------------
 * LRU Cache
 */

#include <iostream>
#include <utility>
#include <map>

using namespace std;

class LRUCache {
    int cap, pos;
    map<int,pair<int,int>> m;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) { 
            m[key].second = pos++;
            return m[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end() || m.size() < cap) {
            m[key] = make_pair(value, pos++);
        } else {
            if(cap > 0 && m.size() > 0) {
                auto m_it         = m.begin(), 
                     el_to_remove = m.begin();

                int min = pos;

                while(m_it != m.end()) {
                    if(min > m_it->second.second) {
                        min = m_it->second.second;
                        el_to_remove = m_it;
                    }
                    m_it++;
                }

                m.erase(el_to_remove);
                m[key] = make_pair(value, pos++);
            }
        }
    }
};

int main(int argc, char **argv)
{
  LRUCache *lruc = new LRUCache(2);
	
	lruc->put(1,1);
	lruc->put(2,2);
	lruc->get(1);
	lruc->put(3,3);

	printf("%d\n", lruc->get(1));
	printf("%d\n", lruc->get(2));
	printf("%d\n", lruc->get(3));


	return 0;
}
