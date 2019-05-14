#pragma once
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryNode.h"

template <typename T>
class BinarySearchTree
{
protected:
   BinaryNode<T>* _root = nullptr;

   virtual BinaryNode<T>* bstAdd(BinaryNode<T>* node, int value)
   {
      //null node indicates time to create a new item in our tree
      if (node == nullptr)
      {
         node = new BinaryNode<T>{ value };
         return node;
      }

      //if not null, send result to child based on relation of node's value
      //and new value
      if (value >= node->getValue())
      {
         node->setRight(bstAdd(node->getRight(), value));
      }
      else
      {
         node->setLeft(bstAdd(node->getLeft(), value));
      }

      //to maintian recursive correctness, always return a BinaryNode<T>*
      return node;
   }

   virtual BinaryNode<T>* bstRemove(BinaryNode<T>* node, int value)
   {
      //ALWAYS guard against a null ptr
      if (node == nullptr)
      {
         return nullptr;
      }

      if (node->getValue() == value)
      {
         //case #1: no children
         if (node->getLeft() == nullptr && node->getRight() == nullptr)
         {
            delete node;
            return nullptr;
         }
         else if (node->getLeft() == nullptr || node->getRight() == nullptr)
         {
            //a little verbose, but completely okay. Not any slower than
            //other method.
            /*BinaryNode<T>* child = node->getLeft();
            if (child == nullptr)
            {
               child = node->getRight();
            }*/
            //same thing as above
            BinaryNode<T>* child = node->getLeft() == nullptr
               ? node->getRight()
               : node->getLeft();
            delete node;
            return child;
         }
         else
         {
            //two children.  Grab rightmost in left subtree
            BinaryNode<T>* largest = node->getLeft();
            while (largest->getRight() != nullptr)
            {
               largest = largest->getRight();
            }

            //take largest's value
            node->setValue(largest->getValue());
            largest = bstRemove(node->getLeft(), largest->getValue());

            //reassign left side to be reconfiguration resulting from
            //delete
            node->setLeft(largest);
         }
      }
      else if (value > node->getValue())
      {
         BinaryNode<T>* result = bstRemove(node->getRight(), value);
         node->setRight(result);
      }
      else
      {
         BinaryNode<T>* result = bstRemove(node->getLeft(), value);
         node->setLeft(result);
      }
      return node;
   }


public:
   virtual void addElement(const T& value)
   {
      _root = bstAdd(_root, value);
   }

   virtual void removeElement(const T& value)
   {
      _root = bstRemove(_root, value);
   }

   /*
   This function returns true when the supplied binary search tree is AVL compliant 
   (difference between left and right height is no more than 1).  True at all levels of the tree.
   */
   bool isAvl() const
   {
      //LAB 7 TODO: Implement!
      return false;
   }

   /*
   Merges the supplied BST into the current BST in such a way that the BST property is maintained
   */
   void mergeTree(const BinarySearchTree<T>& other)
   {
      //LAB 7 TODO: Implement!
      return;
   }

   /*
   For this function, determine the closest common ancestor of both values in the tree.  If one value is not in the tree, output "NONE".  For example, given the tree:
            10
        5       15
     1    6   11   17

     * Values 1 and 5 share the ancestor 5 (parent-child relationship).
     * Values 1 and 6 share the ancestor 5 (sibling relationship).
     * Values 6 and 11 share the ancestor 10 (grandparent relationship).
     Return -1 if there is no common ancestor.
   */
   int commonAncestor(int val1, int val2)
   {
      //LAB 7 TODO: Implement!
      return -1;
   }


   
   
};

#endif // !BINARY_SEARCH_TREE_H
