#include <iostream>
#include <algorithm>
#include <map>
#include <limits>
#include <vector>


using namespace std;

    class LRU {

        public:
            /* takes in an unordered map and cache size*/
            bool validSize(void);
            int getCacheSize(void);
            void insertCache(int value);
            int currentIndexCount(void);
            void prettyPrintCache(void);
            void lruAlg(int key, int value);
            void updateCachedIndex(int key, int value);
            void deleteCachedIndex(int key);
            int  cacheHitCount(void);
            bool cacheHit(int key);
            void updateCache(int key, int value);
            void deleteMinCache(int key);
            void setSize(int size);
            void setHits(int hits);
            int getHits(void);
            LRU(int cache_size, map<int,int> cached, int index);

        private:

            /* size of cache */
            int limits;
            /* cache */
            map<int,int> cache = {};
            /* cache hits*/
            int cache_hits;
            /* index */
            int current_index;

    };

    /* constructor */
    LRU::LRU(int cache_size, map<int,int> cached, int index) {
        cache_size = limits;
        cached = cache;
        // make == 0 ?
        index = current_index;
    }

    /* set size limit */
    void LRU::setSize(int size) {
        limits = size;
    }
    /* size of cache */
    int LRU::getCacheSize(void) {
        return cache.size(); ;
    }

    /* check if elements fit in valid cache size */
    bool LRU::validSize(void) {
        if (getCacheSize() < limits) {
            return true;
        }
        return false;
    }

    /* insert value from cache */
    void LRU::insertCache(int value) {
        if (!validSize()) {
            lruAlg(currentIndexCount(), value);
        }
        else {
            cache[currentIndexCount()] = value;
        }
    }

    /* uses index count to use as key in map, useful for timing*/
    int LRU::currentIndexCount(void) {
        current_index += 1;
        return current_index;
    }

    /* deletes value from cache */
    void LRU::deleteMinCache(int key) {
        // want to delete the min of all elements for LRU
        int min = 0;
        vector<int> values;
        for (auto c : cache) {
            values.push_back(c.first);
        }
        // sort list of keys and get smallest key
        sort(values.begin(), values.end());
        // assuming we add by key number, then the smallest key
        // must be the least recently used index
        cache.erase(values[0]);

        // reset vector values ot null;
        values.clear();
    }

    /* updates value of the cache using index */
    void LRU::updateCache(int key, int value) {
        cache[key] = value;
    }

    /* cache hit true if value is present in cache */
    bool LRU::cacheHit(int key) {
        for (auto c : cache) {
            if (c.first == key) {
                return true;
            }
        }
        return false;
    }

    /* updates cache hit count */
    int LRU::cacheHitCount(void){
        return cache_hits++;
    }

    /* set cache hits */
    void LRU::setHits(int hits) {
        cache_hits = hits;
    }

    int LRU::getHits(void){
        return cache_hits;
    }

    /* delete index for cached element -- if hit */
    void LRU::deleteCachedIndex(int key) {
        // must assert the key is present
        for (auto c : cache) {
            if (c.first == key) {
                cache.erase(c.first);
                break;
            }
        }
    }

    /* update index for cached element  -- if hit */
    void LRU::updateCachedIndex(int key, int value){
        // delete current cached index and update with new one updated
        deleteCachedIndex (key);
        cache[key++] =  value;
    }

    /* runs lru algorithm */
    void LRU::lruAlg(int key, int value) {
        // delete min index element -> update element
        deleteMinCache(key);
        updateCache(key, value);
        if (cacheHit(key)) {
            // if cache hit, update current index +1
            updateCachedIndex(key, value);
            cacheHitCount();
        }
    }

    /* Preety Print needs fix */
    void LRU::prettyPrintCache(void){
        cout << "****** Cache ******" << endl;
        for (auto c : cache) {
            cout << "###################" << endl;
            cout << "|" << "Index: " << c.first << " Value: "<< c.second << "|" << endl;
        }
        cout << "###################" << endl;
    }


