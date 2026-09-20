/*#include <iostream>
#include <string>
int calhash(std::string name){
  int total=0;
  int prev=0;
  for(int i=0;i<name.size();i++){
    char c=name[i];
    prev=total;
    total=(prev*31)+unsigned (c);
    std::cout<<total<<std::endl;
      }
  return total;
}
int main(void){
  std::string hash ="cat";
  int index=calhash(hash);
  std::cout<<index<<std::endl;
  int capacity=60;
  int in=index%capacity;
  std::cout<<in<<std::endl;
  return 0;
}*/
#include <cstddef>
#include <iostream>
#include <vector>
template<typename t1,typename t2>
struct node{
  t1 key;
  t2 value;
  node *next;
  node(t1 k,t2 v):key(k),value(v),next(nullptr){}
};
template <typename t1,typename t2>
class unordermap{
  private:
    int capacity;
    int size;
    std::vector<node<t1,t2>*>buckets;
    int hashfunction(const t1& key){
    char c;
    int total=0;
    int prev=0;
    for(int i=0;i<key.size();i++){
      c=key[i];
      total=(prev*31)+unsigned (c);
        prev=total;
    }
   return (total%60)%capacity;
    }
 public:
    unordermap(int cap=10){
      capacity=cap;
      size=0;
      buckets.resize(capacity,nullptr);
    }
void insert(t1 key,t2 value){
  int index=hashfunction(key);
    node<t1,t2> *newnode=new node<t1,t2>(key,value);
     buckets[index]=newnode;
}
void get(t1 key){
  int index=hashfunction(key);
  node<t1,t2> *newnode=NULL;
  newnode=buckets[index];
  std::cout<<newnode->value<<std::endl;
}
};
int main(void){
 unordermap<std::string,int>map;
 map.insert("apple",100);
 map.get("apple");
 map.insert("hello",200);
 map.get("hello");
 unordermap<std::string,bool>map2;
map2.insert("gello",true);
map.get("gello");
}
