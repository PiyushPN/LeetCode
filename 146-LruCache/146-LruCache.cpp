// Last updated: 18/07/2026, 20:02:39
class LRUCache{
  public:
    class Node{
      public:
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int _key, int _value){
            key=_key;
            value=_value;
        }
    };
    unordered_map<int, Node*> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int capacity;

    LRUCache(int _capacity){
        capacity = _capacity;
        head->next=tail;
        tail->prev=head;
    }

    void insertathead(Node* node){
        Node* temp = head->next;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
        head->next=node;
    }

    void deletenode(Node* node){
        Node *nodeprev = node->prev;
        Node *nodenext = node->next;
        nodeprev->next=nodenext;
        nodenext->prev=nodeprev;
    }

    int get(int key){
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            int value = node->value;
            mp.erase(key);
            deletenode(node);
            insertathead(node);
            mp[key]=head->next;
            return value;
        } else {
            return -1;
        }
    }

    void put(int key, int value){
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value=value;
            mp.erase(key);
            deletenode(node);
            insertathead(node);
            mp[key]=head->next;
        } else {
            Node *toadd = new Node(key, value);
            if(mp.size()==capacity){
                Node *todel=tail->prev;
                deletenode(todel);
                mp.erase(todel->key);
                insertathead(toadd);
                mp[key]=toadd;
                delete todel;
            } else {
                insertathead(toadd);
                mp[key]=toadd;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */