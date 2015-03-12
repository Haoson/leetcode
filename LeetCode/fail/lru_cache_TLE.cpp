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

struct CacheNode{
    int key;
    int value;
    CacheNode(int k,int v):key(k),value(v){}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->list_capacity = capacity<0?10:static_cast<size_t>(capacity);        
    }
    
    int get(int key) {
        auto it = key_pos.find(key); 
        if(it==key_pos.end())return -1;
        list<CacheNode>::iterator l_it = (*it).second;
        cache.splice(cache.begin(),cache,l_it); 
        key_pos[key] = cache.begin();
        return (*(cache.begin())).value;
    }
    
    void set(int key, int value) {
        auto it = key_pos.find(key);
        if(it==key_pos.end()){
            if(cache.size()==list_capacity){
                key_pos.erase(cache.back().key);
                cache.pop_back();
            } 
            cache.insert(cache.begin(),CacheNode(key,value));
        }else{
            cache.splice(cache.begin(),cache,it->second);
            key_pos[key] = cache.begin();
            cache.begin()->value = value;
        }
    }
private:
    unordered_map<int,list<CacheNode>::iterator> key_pos;//记录key在list中的位置信息
    list<CacheNode> cache;//双向循环链表记录cache键值对
    size_t list_capacity;
};
