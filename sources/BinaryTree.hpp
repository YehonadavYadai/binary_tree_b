#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "iterator.hpp"
#include "Node.hpp"
const int CNT = 5;
namespace ariel
{
    
    template <typename T>
    class BinaryTree
    {
    private:
       
        Node<T> *BiTy;
         uint max_level = 0;

       
        void deepCopying(Node<T> *copy_tree, const Node<T> *origin_tree)
        {
            // we already have the root . maybe the val is in this .
            //if there a left child 
            
            if (pn(origin_tree->l) )
            {
                
                // creating a new node
                copy_tree->l = new Node<T>(origin_tree->l->val);
                //put the dad in the dad field
                copy_tree->l->dad = copy_tree;
                // put the right degree 
                copy_tree->l->degree = copy_tree->degree + 1;
                // keep copy from this spot .
                deepCopying(copy_tree->l, origin_tree->l);
            }
            // same at right child 
            if (pn(origin_tree->r ))
            {
                copy_tree->r = new Node<T>(origin_tree->r->val);
                copy_tree->r->dad = copy_tree;
                copy_tree->r->degree = copy_tree->degree + 1;
                deepCopying(copy_tree->r, origin_tree->r);
            }
        }
 Node<T> *search_node(Node<T> *curr, T v)
        {
            if (curr->val == v)
            {
                return curr;
            }
            Node<T> *search = nullptr;

            if (!pn(search) && pn(curr->r) )
            {
                search = search_node(curr->r, v);
            }
            if (!pn(search) && pn(curr->l ))
            {
                search = search_node(curr->l, v);
            }
            return search;
        }

        void delete_nodes(Node<T> *Tree)
        {
            //if its not empty
            if (pn(Tree) )
            {
                //delete in req the left and right .
                delete_nodes(Tree->l);
                delete_nodes(Tree->r);
            }

            delete Tree;
        }

    public:
    
    int pn(Node<T> *root){

         int a= CNT;
         int b=CNT;
        for(int i=0; i<a;i++){
           rand();
        }
            if (root!=nullptr){
                return 1;
            }
            return 0;
        }
    // default constructur
     
        BinaryTree(BinaryTree &&other) noexcept
        {
            BiTy = other.BiTy;
            max_level = other.max_level;
            other.BiTy = nullptr;
        }
        BinaryTree() : BiTy(nullptr) {}
        //deep copy constructor
        BinaryTree(const BinaryTree &other)
        {
            //build the root and put the val in this like i assumed above
            BiTy = new Node<T>(other.BiTy->val);
            // i know what the max level that should be in the end so copy it 
            max_level = other.max_level;
            // copy all the nodes.
            deepCopying(BiTy, other.BiTy);
        }

        // no deep copy constructor
       

        ~BinaryTree() { delete_nodes(BiTy); };

        //operator assume operator 
        //
        BinaryTree &operator=(const BinaryTree<T> &other)
        {
            if (this != &other)
            {
                delete_nodes(BiTy);
                BiTy = new Node<T>(other.BiTy->val);
                max_level = other.max_level;
                deepCopying(BiTy, other.BiTy);
            }
            return *this;
        }
        // BinaryTree &operator=(const BinaryTree<T> &other)
        // {
        //     // if its no the same // compare the memory .
        //     if (this != &other)
        //     {
        //         // i delete what inside to keep something ou
        //         delete_nodes(BiTy);
        //         // copy the value
        //         BiTy = new Node<T>(other.BiTy->val);
        //         max_level = other.max_level;
        //         // copy the tree 
        //         deepCopying(BiTy, other.BiTy);
        //     }
        //     return *this;
        // }

        auto begin()
        {
            return begin_inorder();
        }

        auto end()
        {
            return end_inorder();
        }

        auto begin_preorder()
        {
            return iterator<T>{BiTy,"preorder"};
        }

        auto end_preorder()
        {
            return iterator<T>{};
        }

        auto begin_inorder()
        {
            return iterator<T>{BiTy,"inorder"};
        }

        auto end_inorder()
        {
            return iterator<T>{};
        }

        auto begin_postorder()
        {
            return iterator<T>{BiTy,"postorder"};
        }

        auto end_postorder()
        {
            return iterator<T>{};
        }
        BinaryTree &operator=(BinaryTree<T> &&other) noexcept
        {
            if (this != &other)
            {

                delete_nodes(BiTy);

                BiTy = other.BiTy;
                max_level = other.max_level;
                other.BiTy = nullptr;
            }
            return *this;
        }
        BinaryTree &add_root(const T v)
        {
            if (pn(BiTy) )
            {
                BiTy->val = v;
            }
            else
            {
                BiTy = new Node<T>(v);
            }
            return *this;
        }
        BinaryTree &add_left(T dad, T left_child)
        {
            if (!pn(BiTy) )
            {
                throw "add root first\n";
            }

            Node<T> *src = search_node(BiTy, dad);
            if (pn(src ))
            {
                if (pn(src->l) )
                {
                    src->l->val = left_child;
                }
                else
                {
                    src->l = new Node<T>(left_child);
                    src->l->dad = src;
                    src->l->degree = src->degree + 1;
                    if (src->l->degree > max_level>0)
                    {
                        max_level = src->l->degree;
                    }
                }
                return *this;
            }
            throw "no dad that you searched for \n";
        }




        BinaryTree &add_right(T dad, T right_child)
        {
            if (!pn(BiTy) )
            {
                throw "go add root first\n";
            }
            Node<T> *src = search_node(BiTy, dad);

            if (pn(src) )
            {
                
                if (pn(src->r) )
                {
                    src->r->val = right_child;
                }
                else
                {
                    src->r = new Node<T>(right_child);
                    src->r->dad = src;
                    src->r->degree = src->degree + 1;
                    if (src->r->degree > max_level)
                    {
                        max_level = src->r->degree;
                    }
                }
                return *this;
            }
            throw "no dad that you searched for\n";
        }

        

        const Node<T> *get_root() { return BiTy; }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree &t)
        {

            os<<"check me"<<endl;
            return os;
        }
        /*
        print method idea taken from GeeksForGeeks:
        https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/

        */
       

        
    };
}
