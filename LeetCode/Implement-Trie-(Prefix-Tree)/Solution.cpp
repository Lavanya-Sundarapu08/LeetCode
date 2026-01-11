1class Node{
2    Node links[]=new Node[26];
3    boolean flag=false;
4    boolean containsKey(char ch){
5        return links[ch-'a']!=null;//null need to keep
6    }
7    void put(char ch,Node node){
8         links[ch-'a']=node;
9    }
10    Node get(char ch){
11        return links[ch-'a'];
12    }
13    boolean isEnd(){ return flag;}//directly true not given so fn taken
14    void setEnd(){ flag=true;}
15
16}
17class Trie {
18    private Node root;
19    public Trie() {
20        root=new Node();
21    }
22    
23    public void insert(String word) {
24        Node node=root;
25        for(int i=0;i<word.length();i++){
26            if(!node.containsKey(word.charAt(i))){
27                node.put(word.charAt(i),new Node());
28            }
29            node=node.get(word.charAt(i));
30        }
31        node.setEnd();
32    }
33    
34    public boolean search(String word) {
35        Node node=root;
36        for(int i=0;i<word.length();i++){
37            if(!node.containsKey(word.charAt(i))){
38                return false;
39            }
40            node=node.get(word.charAt(i));
41        }
42        return node.isEnd();
43    }
44    
45    public boolean startsWith(String prefix) {
46        Node node=root;
47        for(int i=0;i<prefix.length();i++){
48            if(!node.containsKey(prefix.charAt(i))){
49                return false;
50            }
51            node=node.get(prefix.charAt(i));
52        }
53        return true;
54    }
55}
56
57/**
58 * Your Trie object will be instantiated and called as such:
59 * Trie obj = new Trie();
60 * obj.insert(word);
61 * boolean param_2 = obj.search(word);
62 * boolean param_3 = obj.startsWith(prefix);
63 */