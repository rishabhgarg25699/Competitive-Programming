//CPP Program to implement  data structure tries

#include<bits/stdc++.h>

using namespace std;

const int alphabet_nos=26;
struct Node
{

    Node *children[alphabet_nos];
} ;
//Function for creating an empty data structure
Node  *init()
{
        Node *root=new Node;

        for(int i=0;i<alphabet_nos;++i)
        {
            root->children[i]=NULL;

        }
        return root;
}
//Function for inserting a string into the trie
Node *insert_string(Node *root,char *s)
{
        Node *ptr=root;
        int sizee=strlen(s);
        for(int i=0;i<sizee;++i)
        {
            int index=s[i]-'a';
            if(ptr->children[index]==NULL)
            {
                ptr->children[index]=init();
                ptr=ptr->children[index];

            }
            else
            {
                ptr=ptr->children[index];
            }
        }
}
//Function for checking if a node is a leaf
bool Check_leaf(Node *root)
{
    bool flag=1;
    for(int i=0;i<alphabet_nos;++i)
    {
        if(root->children[i])
        {
            flag=0;
            break;
        }
    }
    return flag;

}
//Function to traverse and retrieve the words stored in the trie
void traverse_retrieve(Node *root,char s_disp[],int str_size)
{
    Node *ptr=root;
    if(Check_leaf(ptr))
    {
        s_disp[str_size]='\0';
        cout<<s_disp<<endl;
    }
    else
    {
        for(int i=0;i<alphabet_nos;++i)
        {
            if(ptr->children[i]!=NULL)
            {
                s_disp[str_size]='a'+i;
                traverse_retrieve(ptr->children[i],s_disp,str_size+1);
            }
        }
    }

}
//DRiver Fuction

int main()
{
    Node *root=init();
    char *s[5]={"going","gone","row","rotor","gong"};
    int str_size=0;
    int n=5;
    for(int i=0;i<n;++i)    //Taking input of n number of words
    {
        insert_string(root,s[i]);
    }
    char ch[20];
    traverse_retrieve(root,ch,str_size);  //Outputting the contents of the trie
    return 0;
}

