#ifndef NODE_H
#define NODE_H


    /**
     * @class  Node
     * @brief  A struct for the node in our binary search tree.
     * What encapsulation is used and why:
     *
     *
     * @date   May 2024
     * @author William Halling
     */
template<class T>
struct Node
{
    Node(T storedData);

   ~Node();

    T thisData;  /// The data going into the BST
    Node* left;  /// Left Hand side Node
    Node* right; /// Right Hand side Node
};


/**
 * @brief Node initialized Constructor.
 * Used to create a node with data of any type
 */
template<class T>
Node<T>::Node(T storedData) : thisData(storedData), left(nullptr), right(nullptr){}


/**
 * @brief Node Destructor
 * Used to delete a node releasing its resources when not in use
 */

template<class T>
Node<T>::~Node()
{
    left  = nullptr; ///Left Hand side Node

    right = nullptr; ///Right Hand side Node
}
#endif // NODE_H
