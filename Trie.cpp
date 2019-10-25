#include<iostream>
#include <unordered_map>
#define hashmap unordered_map<char,node*>
using namespace std;

class node{

    public:
    char ch;
    bool isTerminal;
    hashmap mp;

        node(char c){
            ch=c;
            isTerminal = false;
        }
};
class Trie{
    node* root;
    public : 
        Trie(){
            root= new node('\0');
        }
        void insertString(string str){
            node* temp = root;
            int leng = str.length();
            for(int i=0;i<leng;i++)
             {   if(temp->mp.count(str[i])==0)
                    {
                        node* child = new node(str[i]);
                        temp->mp[str[i]]= child;
                        temp=child;
                        
                    }
                    else{
                        temp=temp->mp[str[i]];
                        
                        }
            }
           
            temp->isTerminal=true;
            

         }
        bool isPresent(string s){
                node* temp= root;
                int len=s.length();
                for(int i=0;i<len;i++){
                    if(temp->mp.count(s[i])==0)
                    {
                        
                        return false;
                        }
                    else
                    {
                        temp=temp->mp[s[i]];
                    }
                    
                }
                
            return temp->isTerminal;
        }

};
int main(){

    string sts[]={"apple","ap","app","apps"};

    Trie t;
    t.insertString(sts[0]);
    t.insertString(sts[1]);
    t.insertString(sts[2]);
    t.insertString(sts[3]);

    cout<<"If present "<<t.isPresent("apping")<<endl;
    return 0;
}