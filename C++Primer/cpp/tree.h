#include<bits/stdc++.h>

using namespace std;
#define lson (0)
#define rson (1)
class Node{
public:
    friend class Tree;
    Node(int _value,shared_ptr<Node> _father = nullptr){
        cnt = 1;
        value = _value;
        father = _father;
        son[0] = son[1] = nullptr;
    }
private:
    int cnt;
    int value;
    int size;
    shared_ptr<Node> son[2];
    shared_ptr<Node> father;
};

class Tree{
public:
    void insert(int val){
        if(root == NULL){
            root = make_shared<Node>(val);
        }
        shared_ptr<Node> t = root;
        while(t){
            if(t->value == val){
                splay(t,nullptr);
                return;
            }
            bool which = (val > t->value);
            if(t->son[which] == nullptr)
                t->son[which] = make_shared<Node>(val,t);
            t = t->son[which];
        }
    }
    int count(int val){
        shared_ptr<Node> t = root;
        while(t){
            if(t->value == val){
                splay(t,nullptr);
                return t->cnt;
            }
            t = t->son[val > t->value];
        }
        return 0;
    }
    bool erase(int val){
        shared_ptr<Node> t = where_value(val);
        if(t == nullptr)
            return false;
        splay(t,nullptr);
        if(t->son[lson] == nullptr){
            root = t->son[rson];
            if(root)
                root->father = nullptr;
        }
        else{
            shared_ptr<Node> p = t->son[lson];
            while(p->son[rson] != nullptr)
                p = p->son[rson];
            splay(p,t);
            root = p;
            root->father = nullptr;
            p->son[rson] = t->son[rson];
            if(p->son[rson])
                p->son[rson]->father = p;
        }
        return true;
    }
private:
    shared_ptr<Node> root;
    bool which_son(shared_ptr<Node> f,shared_ptr<Node> s){
        return f->son[rson] == s;
    }
    void rotate(shared_ptr<Node> t){
        shared_ptr<Node> f = t->father;
        shared_ptr<Node> gf = f->father;
        bool which = which_son(f,t);
        f->son[which] = t->son[!which];
        if(t->son[!which])
            t->son[!which]->father = f;
        t->son[!which] = f;
        f->father = t;
        t->father = gf;
        if(gf)
            gf->son[which_son(gf,f)] = t;
        else
            root = t;
    }
    void splay(shared_ptr<Node> t,shared_ptr<Node> p){
        while(t->father != p){
            shared_ptr<Node> f = t->father;
            shared_ptr<Node> gf = f->father;
            if(gf == p)
                rotate(t);
            else{
                if(which_son(gf,f) == which_son(f,t)){
                    rotate(f);rotate(t);
                }
                else{
                    rotate(t);rotate(t);
                }
            }
        }
    }
    shared_ptr<Node> where_value(int val){
        shared_ptr<Node> t = root;
        while(t){
            if(t->value == val)
                return t;
            t = t->son[val > t->value];
        }
        return nullptr;
    }
};
int main(void){
    Tree t;
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);






    return 0;
}
