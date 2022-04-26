typedef struct node{
    struct node *next;
    struct node *prior;
    int key;
    int value;
    node(int _key, int _value, node* n = NULL, node* p = NULL){
        key = _key;
        value = _value;
        next = n;
        prior = p;
    }
}node;

class myQueue{  // 队列，但是支持删除中间节点
private:
    node* front;
    node* end;
    int size;
    unordered_map<int, node*> queueMap;
public:
    myQueue(){
        front = NULL;
        end = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool hasKey(int key){
        if(queueMap.find(key) != queueMap.end())
            return true;
        else
            return false;
    }
    int getValue(int key){
        return queueMap[key]->value;
    }
    void push(int key, int value){  // 进入队尾
        if(!size){
            node* n = new node(key, value);
            queueMap[key] = n;
            front = n;
            end = n;
            ++size;
        }
        else{
            node* n = new node(key, value);
            queueMap[key] = n;
            end->next = n;
            n->prior = end;
            end = n;
            ++size;
        }
    }
    void pop(){  // 出队
        if(size > 0){
            node* n = front;
            front = front->next;
            front->prior = NULL;
            queueMap.erase(n->key);
            delete n;
            --size;
        }
    }
    void pop(int key){  // 删除key对应的节点
        node *n = queueMap[key];
        if(n->prior)
            n->prior->next = n->next;
        else
            front = n->next;
        
        if(n->next)
            n->next->prior = n->prior;
        else
            end = n->prior;
        queueMap.erase(key);
        delete n;
        --size;
    }
};
class LRUCache {
private:
    int capacity;
    myQueue keyQueue;

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    int get(int key) {
        if(keyQueue.hasKey(key)){
            int value = keyQueue.getValue(key);
            keyQueue.pop(key);  // 也要改变位置
            keyQueue.push(key, value);
            return value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(keyQueue.hasKey(key)){
            keyQueue.pop(key);
            keyQueue.push(key, value);
            
        }
        else{
            keyQueue.push(key, value);
        }

        if(keyQueue.getSize() > capacity){
            keyQueue.pop();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
