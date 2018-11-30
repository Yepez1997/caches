#include "lru.h"

/**** TO DO ADD TEMPLATES FOR VALUES ****/
int main() {

    /* vars */
    int size = 5;

    map<int, int> lru = {};
    int index = 0;
    LRU lru_cache{size, lru, index};
    // must include this
    // still figuring why get a weird random large number
    lru_cache.setSize(4);
    lru_cache.setHits(0); // set hits default == 0
    /* values to insert to cache */
    vector<int> values = {1, 4, 5, 3, 2, 8};

    for (auto v : values) {
        lru_cache.insertCache(v);
    }


    lru_cache.prettyPrintCache();

}