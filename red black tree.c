#include<stdio.h>
#include<stdlib.h>

struct tree{

struct node* root;

};

struct node{

int data;
char color;
struct node* left;
struct node* right;
struct node* parent;
char which;

struct tree* t;

};

void l_rotate(struct node* x){

struct node* xp = x->parent;
struct node* xrc = x->right;
struct node* xrclc = xrc->left;

if(xp != NULL){
    if(x->which == 'l'){
        xp->left = xrc;
        xrc->parent =xp;
        xrc->which = 'l';
    }
    if(x->which == 'r'){
        xp->right = xrc;
        xrc->parent =xp;
        xrc->which = 'r';
    }
}
else{

    xrc->parent = NULL;
    xrc->which = 'n';
    x->t->root = xrc;
    xrc->t = x->t;
    x->t = NULL;

}


x->parent = xrc;
xrc->left = x;
x->which = 'l';


if(xrclc != NULL){

    xrclc->parent = x;
    x->right =xrclc;
    xrclc->which = 'r';

}
else{

    x->right = NULL;

}

return;

}

void r_rotate(struct node* x){

struct node* xp = x->parent;
struct node* xlc = x->left;
struct node* xlcrc = xlc->right;

if(xp != NULL){
    if(x->which == 'l'){
        xp->left = xlc;
        xlc->parent =xp;
        xlc->which = 'l';
    }
    if(x->which == 'r'){
        xp->right = xlc;
        xlc->parent =xp;
        xlc->which = 'r';
    }
}
else{

    xlc->parent = NULL;
    xlc->which = 'n';
    x->t->root = xlc;
    xlc->t = x->t;
    x->t = NULL;

}


x->parent = xlc;
xlc->right = x;
x->which = 'r';


if(xlcrc != NULL){

    xlcrc->parent = x;
    x->left =xlcrc;
    xlcrc->which = 'l';

}
else{

    x->left = NULL;

}

return;

}

void rb_fix(struct node* x){

if(x->which=='n'){
    x->color = 'B';
    return;
}

struct node* xp = x->parent;

if(xp->color == 'B'){
    return;
}
if(xp->color == 'R'){

    struct node* xg =xp->parent;
    struct node* xu = NULL;

    if(xp->which == 'l'){
        xu = xg->right;
    }
    if(xp->which == 'r'){
        xu = xg->left;
    }


    if(xu != NULL){
        if(xu->color == 'R'){
            xu->color = 'B';
            xp->color = 'B';
            xg->color = 'R';
            rb_fix(xg);
            return;
        }


        if(xu->color == 'B'){

            if(x->which == 'l'){

                if(xp->which == 'l'){
                    r_rotate(xg);
                    xg->color = 'R';
                    xp->color = 'B';
                    return;
                }
                if(xp->which == 'r'){
                    r_rotate(xp);
                    l_rotate(xg);
                    x->color = 'B';
                    xg->color = 'R';
                    return;
                }

            }
            if(x->which == 'r'){

                if(xp->which == 'l'){
                    l_rotate(xp);
                    r_rotate(xg);
                    x->color = 'B';
                    xg->color = 'R';
                    return;
                }
                if(xp->which == 'r'){
                    l_rotate(xg);
                    xg->color = 'R';
                    xp->color = 'B';
                    return;
                }

            }

        }

    }
    else{

        if(x->which == 'l'){

            if(xp->which == 'l'){
                r_rotate(xg);
                xg->color = 'R';
                xp->color = 'B';
                return;
            }
            if(xp->which == 'r'){
                r_rotate(xp);
                l_rotate(xg);
                x->color = 'B';
                xg->color = 'R';
                return;
            }

        }
        if(x->which == 'r'){

            if(xp->which == 'l'){
                l_rotate(xp);
                r_rotate(xg);
                x->color = 'B';
                xg->color = 'R';
                return;
            }
            if(xp->which == 'r'){
                l_rotate(xg);
                xg->color = 'R';
                xp->color = 'B';
                return;
            }

        }

    }

}

}

void rb_insert(struct tree* T,int x){

struct node* r;
struct node* p;
int c;
r=T->root;

if(T->root==NULL){
    T->root=(struct node*) malloc(sizeof(struct node));
    struct node* Root;
    Root = T->root;
    Root->data = x;
    Root->right = NULL;
    Root->left = NULL;
    Root->color = 'B';
    Root->parent = NULL;
    Root->which = 'n';
    Root->t = T;
    return;
}
else{
    while(r!=NULL){
        p=r;
        if(r->data > x){
            r = r->left;
            c=-1;
        }
        else{
            r=r->right;
            c=1;
        }
    }

    if(c==1){
        p->right=(struct node*) malloc(sizeof(struct node));
        r=p->right;
    }
    if(c==-1){
        p->left=(struct node*) malloc(sizeof(struct node));
        r=p->left;
    }

    r->data=x;
    r->left=NULL;
    r->right=NULL;
    r->color = 'R';
    r->parent = p;

    if(c==1){
        r->which = 'r';
    }
    if(c==-1){
        r->which = 'l';
    }
    r->t = NULL;

    rb_fix(r);
    return;
}

}


void inorderwalk(struct node* r){

if(r!=NULL){
    inorderwalk(r->left);
    printf("(%d,%c)",r->data,r->color);
    inorderwalk(r->right);
    return;
}
else{
    return;
}

}

void postorderwalk(struct node* r){

if(r!=NULL){
    postorderwalk(r->left);
    postorderwalk(r->right);
    printf("(%d,%c)",r->data,r->color);
    return;
}
else{
    return;
}

}

void preorderwalk(struct node* r){

if(r!=NULL){
    printf("(%d,%c)",r->data,r->color);
    preorderwalk(r->left);
    preorderwalk(r->right);
    return;
}
else{
    return;
}

}

void printtree(struct node* r,int c){

if(r != NULL){
    int i;
    printtree(r->right,c+1);
    for(i=0;i<2*c;i++){
        printf(" ");
    }
    printf("%d %c",r->data,r->color);
    printf("\n");
    printtree(r->left,c+1);

}
else{
    printf("\n");
    return;
}
}

int main(){

struct tree* T;
T=(struct tree*) malloc(sizeof(struct tree));
T->root = NULL;
int c=1,v;

while(1){

    printf("1.insert \t 2.traverse \t 3.print tree\t 4.exit \n");
    scanf("%d",&c);

    if(c==1){
        printf("give the value to insert : ");
        scanf("%d",&v);
        rb_insert(T,v);
    }
    if(c==2){
        inorderwalk(T->root);
        printf("\n");
    }
    if(c==3){
            printtree(T->root,0);
            printf("\n");
    }
    if(c==4){
        break;
    }
    if(c!=1&&c!=2&&c!=3&&c!=4){
        printf("wrong input\n");
    }

}

return 0;
}
