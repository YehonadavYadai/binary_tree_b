#pragma once
namespace ariel
{
    template <typename T>
    struct Node
    {
        T val;
        uint degree;
        Node *l;
        Node *r;
        Node *dad;
       
        Node(const T &v)
        : dad(nullptr), l(nullptr), r(nullptr), val(v),degree(0) 
        {}

        Node()
        :  r(nullptr), dad(nullptr), l(nullptr)
         {}
    };
}