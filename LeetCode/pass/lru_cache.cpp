/*************************************************************************
  > File Name: lru_cache.cpp
  > Author:Haoson 
  > Created Time: Thu 12 Mar 2015 10:00:09 AM PDT
  > 解题思路:为了使查找、插入和删除都有较高的性能，我们使用一个双向链表(std::list) 和一个哈希表(std::unordered_map)
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
struct CacheNode
{
    int key;
    int value;
    CacheNode(int k, int v):key(k), value(v){}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end())
            return -1;
        else
        {
            //把当前访问的节点移到链表头部,并且更新map中该节点的地址
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
            return cacheMap[key]->value;
        }
        
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end())
        {
            if(cacheList.size() == static_cast<size_t>(size))
            {//删除链表尾部节点（最少访问的节点）
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            //插入新节点到链表头部,并且更新map中增加该节点
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
        else
        {//更新节点的值，把当前访问的节点移到链表头部,并且更新map中该节点的地址
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
        
    }
private:
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator>cacheMap;
    int size;
};


int main(int argc,char* argv[]){
    LRUCache l(18);
    for(int i=0;i<20;++i)
        l.set(i+1,i+2);
    
    for(int i=0;i<20;++i)
        cout<<(l.get(i+1))<<" ";
    cout<<endl;
    for(int i=3;i<6;++i)
        cout<<(l.get(i*i))<<" ";
    cout<<endl;
    return 0;
}
