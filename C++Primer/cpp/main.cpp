#include<bits/stdc++.h>
#include"demo.h"
using namespace std;
#define lson (0)
#define rson (1)
template<typename T>
class TreeNode{
public:
    typedef int size_type;
    friend class SplayTreeSet;
    TreeNode(T _value,shared_ptr<TreeNode<T>> _father = nullptr){
        value = _value;
        father = _father;
        son[0] = son[1] = nullptr;
    }
private:
    size_type cnt;
    T value;
    shared_ptr<TreeNode<T>> son[2];
    weak_ptr<TreeNode<T>> father;
};
template<typename T1,typename T2 = less<T1>()>
class SplayTreeSet{
public:
    typedef T1 value_type;
    typedef TreeNode<T1> Node;
    void insert(value_type _value){
        if(root == nullptr){
            root = make_shared<Node>(Node(_value));
        }
        shared_ptr<Node> t = root;
        while(t){
            if(t->value == _value){
                splay(t,nullptr);
                return;
            }
            bool which_son()
        }
    }
private:
    shared_ptr<Node> root;
    T2 Compare;

    bool which_son(shared_ptr<Node> f,shared_ptr<Node> s){
        return f->son[rson] == s;
    }
    void rotate(shared_ptr<Node> t){
        shared_ptr<Node> f = t->father.lock();
        shared_ptr<Node> g = f->father.lock();
        bool which = which_son(f,t);
        f->son[which] = t->son[!which];
        t->son[!which] = f;
        f->father = t;
        t->father = g;
        if(f->son[which])
            f->son[which]->father = f;
        if(g)
            g->son[which_son(g,f)] = t;
        else
            root = t;
    }
    void splay(shared_ptr<Node> t,shared_ptr<Node> p){
        while(t->father != p){
            shared_ptr<Node> f = t->father.lock();
            shared_ptr<Node> g = f->father.lock();
            if(g == p)
                rotate(t);
            else{
                if(which_son(g,f) == which_son(f,t)){
                    rotate(f);rotate(t);
                }
                else{
                    rotate(t);rotate(t);
                }
            }
        }
    }
    shared_ptr<Node> where_value(value_type _value){
        shared_ptr<Node> t = root;
        while(t){
            if(t->value == _value)
                return t;
            t = t->son[_value > t->value];
        }
        return nullptr;
    }
};

int main(void){



    return 0;
}
