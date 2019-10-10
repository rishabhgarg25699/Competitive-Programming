#include <iostream>
#include <map>
using namespace std;

class node{
public:
	char data;
	map<char,node*> h;
	bool isTerminal;

	node(char d){
		data=d;
		isTerminal=false;
	}
};

class Trie{
	node* root;
public:
	Trie(){
		root=new node('\0');
	}

	void addWord(char *word){
		node*temp= root;
		for(int i=0;word[i]!='\0';i++){
			char ch=word[i];
			if(temp->h.count(ch)==0){
				node* child=new node(ch);
				temp->h[ch]=child;
				temp=temp->h[ch];
			}
			else{
				temp=temp->h[ch];
			}
		}
		temp->isTerminal=true;
	}

	bool search(char *word){
		node* temp=root;
		for(int i=0;word[i]!='\0';i++){
			char ch=word[i];
			if(temp->h.count(ch)==1){
				temp=temp->h[ch];
			}
			else{
				return false;
			}
		}
		return temp->isTerminal;
	}
};

int main(){
	Trie t;

	t.addWord("No");
	t.addWord("Not");
	t.addWord("Noway");
	t.addWord("abc");
	char f[100];

	cin>>f;
	if(t.search(f)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}



}
