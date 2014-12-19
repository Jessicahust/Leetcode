#include<unordered_map>
#include<list>
#include<iostream>
using namespace std;

struct CacheNode
{
    int key;
    int value;
    CacheNode(int k,int v):key(k),value(v) {}
};
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        size=capacity;
    }

    int get(int key)
    {
        auto iter=cacheMap.find(key);
        if(iter!=cacheMap.end())
        {
            cacheList.splice(cacheList.begin(),cacheList,iter->second);
            cacheMap[key]=cacheList.begin();
            return cacheMap[key]->value;
        }
        return -1;
    }

    void set(int key, int value)
    {
        auto iter=cacheMap.find(key);
        if(iter!=cacheMap.end())
        {
            cacheMap[key]->value=value;
            cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
            cacheMap[key]=cacheList.begin();
        }
        else
        {
            if(size==(int)cacheList.size())
            {
                //记得要先删除map中的元素，然后再删除list中的地址，不然map中的地址无效，有可能指向后来插入的元素
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key,value));
            cacheMap[key]=cacheList.begin();
        }
    }
private:
    int size;
    unordered_map<int,list<CacheNode>::iterator> cacheMap;
    list<CacheNode> cacheList;
};

int main(){
    LRUCache lru_cache(1);
    lru_cache.set(2,1);
    cout<<lru_cache.get(2)<<endl;
    lru_cache.set(3,2);
    cout<<lru_cache.get(2)<<endl;
    cout<<lru_cache.get(3)<<endl;
}
