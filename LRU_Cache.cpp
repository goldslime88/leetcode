#include <vector>
#include <iostream>

class cacheItem{
public:
	int key;
	int value;
	int used;
	cacheItem(): key(-1), value(-1), used(0){}
};

class LRUCache{
public:
        int a;
        int b;
        int *aa;

    LRUCache(int capacity) {

    	std::vector<cacheItem> cache;
        
        for(int i = 0; i < capacity; ++i){
        	cacheItem item = cacheItem();
        	cache.push_back (item);
        }
        a=5;
        b=10;
        aa = &b;

        head = cache.begin();
        tail = cache.end();
                std::cout<< "cache size is " <<cache.size() <<std::endl;
        
    }


    
    int get(int key) {

        if(head == tail){
            return -1;
        }
        else{
    	    for (std::vector<cacheItem>::iterator it = head; it != tail; ++it){
    		    if(((*it).key) == key && ((*it).used) > 0){

    			    ((*it).used)++;
    			    return ((*it).value);

    		    }
    	    }
        }

    	return -1;
        
    }
    
    void set(int key, int value) {

    	std::vector<cacheItem>::iterator it = head;
        if(head == tail){

        }
        else{

    	    for(it = head; it != tail; ++it){
    		    if(((*it).key) == key && ((*it).used) > 0){
                    
    			    ((*it).used)++;
    			    ((*it).value) = value;
                    std::cout<< "key " << (*it).key << " is in cache used " << (*it).used << std::endl;
    			    break;
 
    		    }
    	    }

    	    if(it == tail){
    		    for (it = head; it != tail; ++it){
    			    if(((*it).used) == 0){
                        
    				    ((*it).used)++;
    				    ((*it).key) = key;
    				    ((*it).value) = value;
                        std::cout<< "key " << (*it).key << " is added to cache used " << (*it).used << std::endl;
    				    break;
 
    			    }
    		    }
    	    }
        
    	    if(it == tail){
                it = head;
    		    int lruNum = ((*it).used);
    		    int lruKey = ((*it).key);
    		    for (it = head; it != tail; ++it){
    			    if(((*it).used) < lruNum){
    				    lruNum = ((*it).used);
    				    lruKey = ((*it).key);
    			    }
    		    }

                std::cout<< "key " << lruKey << " least recent used " << lruNum << std::endl;



    		    for(it = head; it != tail; ++it){
    	       		if(((*it).key) == lruKey){
    				    ((*it).key) = key;
    				    ((*it).value) = value;
    				    ((*it).used) = 1;
                        std::cout<< "clear key " << lruKey << " load key " << (*it).key << std::endl;
    			     	break;
    		      	}
    		    }
    	    }
        }        
    }

private:

	std::vector<cacheItem>::iterator head, tail;
};

int main(){
	LRUCache *lrucache = new LRUCache(1);
	// lrucache.set(2,1);
 //    lrucache.set(3,4);
 //    lrucache.set(2,2);
 //    lrucache.set(4,5);
    delete lrucache;
	std::cout<< *(lrucache->aa) << std::endl;


}