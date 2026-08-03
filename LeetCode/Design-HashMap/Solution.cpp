1class MyHashMap {
2public:
3
4    vector<int> mp;
5
6    MyHashMap() {
7        mp.resize(1000001,-1);
8    }
9    
10    void put(int key, int value) {
11        mp[key]= value;
12    }
13    
14    int get(int key) {
15        return mp[key];
16    }
17    
18    void remove(int key) {
19        mp[key]=-1;
20    }
21};
22
23/**
24 * Your MyHashMap object will be instantiated and called as such:
25 * MyHashMap* obj = new MyHashMap();
26 * obj->put(key,value);
27 * int param_2 = obj->get(key);
28 * obj->remove(key);
29 */