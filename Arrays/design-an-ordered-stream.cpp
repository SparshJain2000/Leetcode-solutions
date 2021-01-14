
//Problem Statement
/*
    There is a stream of n (id, value) pairs arriving in an arbitrary order, where id is an integer between 1 and n and value is a string. No two pairs have the same id.
    Design a stream that returns the values in increasing order of their IDs by returning a chunk (list) of values after each insertion. The concatenation of all the chunks should result in a list of the sorted values.

    Implement the OrderedStream class:
    OrderedStream(int n) Constructs the stream to take n values.
    String[] insert(int id, String value) Inserts the pair (id, value) into the stream, then returns the largest possible chunk of currently inserted values that appear next in the order.
*/
#include <bits/stdc++.h>
using namespace std;
class OrderedStream {
    vector<string>vec;
    int ptr;
public:
    OrderedStream(int n) {
        this->vec=vector<string>(n+1,"");
        ptr=1;
    }
    
    vector<string> insert(int id, string value) {
        vec[id]=value;
        int x=ptr;
        if(ptr==id)
        while(ptr<vec.size()){
            if(vec[ptr]=="") 
                return vector<string>(vec.begin()+x,vec.begin()+ptr);
            ptr++;
        }
        return vector<string>(vec.begin()+x,vec.begin()+ptr);
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */