#pragma once
#include "Node.hpp"
#include <iostream>
#include <string>
// #include <stack>
 using namespace std;
namespace ariel
{
int five= 5;
        int eight=8;
    template <typename T>
    class iterator
    {
        string option;
        Node<T> *node_T;

    public:
    int pn(Node<T> *root){

        int a= five;
        int b=eight;
        for(int i=0; i<a;i++){
            int c= five;
            a=eight;
        }
            if (root!=nullptr){
                return 1;
            }
            return 0;
        }
        iterator(Node<T> *root = nullptr) : node_T(root){};
        iterator(Node<T> *root ,string type) : node_T(root),option(type)
        {
            if (type=="inorder")
            {
                //check if there something in it .
                if (pn(root))
            {
                while (pn(node_T->l))
                {
                    //keep going left
                    node_T = node_T->l;
                }
            }

            }
             if (type=="postorder"){
                if (pn(root))
            {
                // if he is a parent
                while (node_T->l != nullptr || node_T->r != nullptr)
                {
                    // if he got a left child got left 
                    if ( pn(node_T->l))
                    {
                        node_T = node_T->l;
                    }
                    // if no go right
                    else
                    {
                        if (pn(node_T->r)){
                        node_T = node_T->r;
                        }
                    }
                }
            }

            }

        };

        

        T &operator*() const
        {
            return node_T->val;
        }

        T *operator->() const
        {
            return &(node_T->val);
        }

        iterator &operator++()
        {
            
            if (option=="preorder"){
                preorder_plus();
                return *this;
            }
            
            if (option=="postorder")
            {
                postorder_plus();
                return *this;
            }
             
            if (option=="inorder")
            {
                inorder_plus();
                return *this;   
            }
            return *this;
            
        }
        void postorder_plus(){
                if (pn(node_T) )
                    {
                    Node<T> *tmp = node_T;
                    if (node_T->dad != nullptr)
                {
                    node_T = node_T->dad;
                    bool check = pn(node_T->r)  && node_T->r != tmp;
                    if (check)
                    {
                        node_T = node_T->r;
                        while (pn(node_T->l)  || pn(node_T->r) )
                        {
                            if (pn(node_T->l ))
                            {
                                node_T = node_T->l;
                            }
                            else
                            {
                                node_T = node_T->r;
                            }
                        }
                    }
                }
                else
                {
                    node_T = node_T->dad;
                }
            }
        }
        void preorder_plus(){
            if (pn(node_T->l) )
            {
                node_T = node_T->l;
            }
            else if (pn(node_T->r) )
            {
                node_T = node_T->r;
            }
            
            else
            {
                while (pn(node_T->dad ) && !pn(node_T->dad->r) )
                {
                    node_T = node_T->dad;
                    while (pn(node_T->dad) && (node_T == node_T->dad->r || !pn(node_T->dad->r)))
                    {
                        node_T = node_T->dad;
                    }
                }
                while (pn(node_T->dad) && node_T->dad->r == node_T)
                {
                    node_T = node_T->dad;
                    while (pn(node_T->dad)  && !pn(node_T->dad->r ))
                    {
                        node_T = node_T->dad;
                    }
                }
                if (!pn(node_T->dad) )
                {
                    node_T = nullptr;
                }
                else
                {
                    node_T = node_T->dad->r;
                }
            }

        }
        void inorder_plus(){
        if (pn(node_T) )
            {
                if (pn(node_T->r) )
                {
                    node_T = node_T->r;
                    while (pn(node_T->l) )
                    {
                        node_T = node_T->l;
                    }
                }
                else
                {
                    while (pn(node_T->dad)  && node_T == node_T->dad->r)
                    {
                        node_T = node_T->dad;
                    }
                    node_T = node_T->dad;
                }
            }
        }
        iterator operator++(int)
        {
            iterator i = *this;
            ++*this;
            return i;
        }

        bool operator==(const iterator &other) const
        {
            return node_T == other.node_T;
        }

        bool operator!=(const iterator &other) const
        {
            return node_T != other.node_T;
        }
    };

}