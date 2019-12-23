#include<bits/stdc++.h>
using namespace std;
struct node{
  struct node *next;
  int coef,expo;
};
struct node *firstp=NULL,*firstr=NULL,*firstq=NULL;
struct node  *insert(struct node *first,int coef,int expo){
  struct node *nw,*ptr;
  nw=(struct node *)malloc(sizeof(struct node));
  nw->next=NULL;
  nw->coef=coef;
  nw->expo=expo;
  if(first==NULL){
    first=nw;
  }
  else{
    for(ptr=first;ptr->next!=NULL;ptr=ptr->next);
      ptr->next=nw;
  }
   return first;
}

struct node *add(struct node *p,struct node *q,struct node *first){
  while(p!=NULL && q!=NULL){
    if(p->expo==q->expo){
      first=insert(first,(p->coef+q->coef),p->expo);
      p=p->next;
      q=q->next;
    }
    else if(p->expo>q->expo){
      first=insert(first,p->coef,p->expo);
      p=p->next;
    }
    else{
      first=insert(first,q->coef,q->expo);
      q=q->next;
    }
  }// end of the while loop.
  while(p!=NULL){
    insert(first,p->coef,p->expo);
    p=p->next;
  }
  while(q!=NULL){
    insert(first,q->coef,q->expo);
    q=q->next;
  }
  return first;
} // end of the ADD function.
void display(struct node *first){
  struct node *ptr;
  for(ptr=first;ptr!=NULL;ptr=ptr->next){
    cout<<ptr->coef;
    cout<<"x^"<<ptr->expo;
    cout<<"+";
 }
 cout<<endl;

}
int main()
{
  struct node *w,*ptr;
  char ch='y';
  int coef,expo;
  while(ch=='y'){
    cout<<"enter the coefficient"<<endl;
    cin>>coef;
    cout<<"enter the exponent"<<endl;
    cin>>expo;
    firstp=insert(firstp,coef,expo);
    cout<<"Do you want to enter more Y/N:";
    cin>>ch;
  }
  ch='y';
  cout<<"\n Now for the 2nd equation";
  while(ch=='y'){

    cout<<"enter the coefficient : "<<endl;
    cin>>coef;
    cout<<"enter the exponent:"<<endl;
    cin>>expo;
    firstq=insert(firstq,coef,expo);
    cout<<"Do you want to enter more Y/N:"<<endl;
    cin>>ch;
  }

  firstr=add(firstp,firstq,firstr);
  cout<<"the first euation is: "<<endl;
  display(firstp);
  cout<<" the 2nd equation is:\t"<<endl;
  display(firstq);
  cout<<"the resultant equation is : \t"<<endl;
  display(firstr);    
}
