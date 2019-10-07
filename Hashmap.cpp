#include <iostream>
using namespace std;

class node{
public:
	int value;
	string key;
	node* next;

	node(string key,int value){
		this->key=key;
		this->value=value;
		next=NULL;
	}
};
// template<typename T>
class Hashmap{

	int hashFn(string key){
		int ans=0;
		int mul=1;
		for(int i=0;key[i]!='\0';i++){
			ans += key[i]*mul;

			mul *= 37;
			ans %= ms;
			mul %= ms;
		}
		ans %= ms;
		return ans;
	}

	void rehash(){
		node** oldBucket=Bucket;
		int oldts=ms;
		cs=0;
		ms=2*ms;
		Bucket=new node*[ms];
		for(int i=0;i<ms;i++){
			Bucket[i]=NULL;
		}
		for(int i=0;i<oldts;i++){
			node* temp=oldBucket[i];
			while(temp){
				insert(temp->key,temp->value);
				temp=temp->next;
			}

			if(oldBucket[i]!=NULL){
				delete oldBucket[i];
			}
		}
		delete []oldBucket;
	}



public:
	node** Bucket;
	int cs;
	int ms; // ms:table size

	Hashmap(int s=7){
		cs=0;
		ms=s;
		Bucket=new node*[ms];
		
		// Initialize all Buckets with Null as pointers should be NULL when they don't
		// point any valid address
		for(int i=0;i<s;i++){
			Bucket[i]=NULL;
		}
	}

	void insert(string key,int value){
		int i=hashFn(key);cb

		node* n=new node(key,value);

		n->next=Bucket[i];
		Bucket[i]=n;
		cs++;

		float load_factor=cs/(ms*1.0);
		if(load_factor>0.7){
			rehash();
		}
	}

	node* Search(string key){
		int i=hashFn(key);

		node* temp=Bucket[i];
		while(temp){
			if(temp->key==key){
				return temp;
			}
			temp=temp->next;
		}
		return NULL;
	}

	int& operator[](string key){
		node* temp=Search(key);
		if(temp==NULL){
			// key does not exists that means create key and insert its value
			int garbage; 
			insert(key,garbage);
			temp=Search(key);
			return temp->value;

		}
		else{
			// Key exists so update its value
			return temp->value;

		}

	}

	void print(){

		for(int i=0;i<ms;i++){
			cout<<i<<"-->";
			node* temp=Bucket[i];
			while(temp){
				cout<<temp->key<<",";
				temp=temp->next;
			}
			cout<<endl;
		}
	}

	void Delete(string key){
		int i=hashFn(key);
		// Homework
	}


};


int main(){
	Hashmap h;
	h.insert("Mango",100);
	h.insert("Pineapple",30);

	h["Apple"]=140; // Insertion
	h["Apple"]=200; // Updation
	cout<<h["Apple"]<<endl; // search
	h["Kiwi"]=80;
	h["Banana"]=60;


	h.print();

	return 0;
}