#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <algorithm>
#include <iostream>

using namespace std;

/**
 * @class Bst
 * @brief Template class representing a Binary Search Tree (BST).
 * @tparam T The type of data stored in the BST.
 */
template <class T>
class Bst
{
    typedef void (*funcPtr)(T&);

    /**
     * @struct Node
     * @brief Represents a node in the BST.
     */
    struct Node
    {
        long key; /**< The key of the node. */
        T data;   /**< The data stored in the node. */
        Node* left;  /**< Pointer to the left child node. */
        Node* right; /**< Pointer to the right child node. */
        int height;  /**< The height of the node in the AVL tree. */

        /**
         * @brief Constructor for Node.
         * @param key The key of the node.
         * @param data The data stored in the node.
         */
        Node(long key, const T& data) : key(key), data(data), left(nullptr), right(nullptr), height(1) {}
    };

private:
    Node* root; /**< Pointer to the root node of the BST. */
    long size;  /**< The size (number of nodes) of the BST. */

    // Private helper methods for AVL tree balancing
    int Height(Node* node);
    Node* Copy(Node* sourceRoot);
    int BalanceFactor(Node* node);
    Node* Insert(Node* node, long key, const T &data);
    bool Search(Node* node, long key) const;
    void InOrder(Node* node, funcPtr process);
    void PreOrder(Node* node, funcPtr process);
    void PostOrder(Node* node, funcPtr process);
    void DeleteTree(Node*& node);
    Node* LeftRotate(Node* x);
    Node* RightRotate(Node* y);
    Node* BalanceNode(Node* node);
    Node* GetNode(Node* node, long key) const;

public:
    /**
     * @brief Default constructor for the Bst class.
     */
    Bst();

    /**
     * @brief Destructor for the Bst class.
     */
    ~Bst();

    /**
     * @brief Copy constructor for the Bst class.
     * @param other The Bst object to be copied.
     */
    Bst(const Bst<T>& other);

    /**
     * @brief Assignment operator overload for the Bst class.
     * @param otherBst The Bst object to be assigned from.
     * @return Reference to the current Bst object after assignment.
     */
    Bst& operator=(const Bst<T>& otherBst);

    /**
     * @brief Inserts a new node with the specified key and data into the BST.
     * @param key The key of the new node.
     * @param data The data to be stored in the new node.
     */
    void Insert(long key, const T &data);

    /**
     * @brief Searches for a node with the specified key in the BST.
     * @param key The key to search for.
     * @return True if the key is found, false otherwise.
     */
    bool Search(const long key) const;

    /**
     * @brief Performs an in-order traversal of the BST and applies the given function to each node's data.
     * @param process A function pointer to the function to be applied to each node's data.
     */
    void InOrder(funcPtr process);

    /**
     * @brief Performs a pre-order traversal of the BST and applies the given function to each node's data.
     * @param process A function pointer to the function to be applied to each node's data.
     */
    void PreOrder(funcPtr process);

    /**
     * @brief Performs a post-order traversal of the BST and applies the given function to each node's data.
     * @param process A function pointer to the function to be applied to each node's data.
     */
    void PostOrder(funcPtr process);

    /**
     * @brief Calculates the height difference between the left and right subtrees of the BST.
     * @return The height difference between the left and right subtrees.
     */
    int GetHeightDifference();

    /**
     * @brief Gets the data associated with the node having the specified key.
     * @param key The key of the node to retrieve data from.
     * @return Reference to the data associated with the specified key.
     * @throws std::runtime_error if the key is not found in the BST.
     */
    T& GetData(long key) const;

    /**
     * @brief Gets the size (number of nodes) of the BST.
     * @return The size of the BST.
     */
    long GetSize() const;
};


// ===========================================
// I  M  P  L  E  M  E  N  T  A  T  I  O  N  S
// ===========================================


// Constructors
template <class T>
Bst<T>::Bst() : root(nullptr), size(0) {}

template <class T>
Bst<T>::Bst(const Bst<T>& other) : root(Copy(other.root)), size(other.size) {}

// Destructor
template <class T>
Bst<T>::~Bst()
{
    DeleteTree(root);
}

// Operator = overload
template <class T>
Bst<T>& Bst<T>::operator=(const Bst<T>& source)
{
    if (this != &source)   // We do this checking to avoid self-assignment
    {
        // First, deallocate the existing tree
        DeleteTree(root);

        // Secondly, we make a deep copy of the source tree through a helper method
        root = Copy(source.root);

        //Thirdly, we copy the size of the bst
        size = source.size;
    }

    return *this;
}



//=================================
// P R I V A T E      M E T H O D S
//=================================

template <class T>
int Bst<T>::Height(Node* node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

template <class T>
typename Bst<T>::Node* Bst<T>::Copy(Node* sourceRoot)
{
    if (sourceRoot == nullptr)
    {
        return nullptr;
    }

    // Create a new node with the same key and data
    Node* newNode = new Node(sourceRoot->key, sourceRoot->data);

    // Recursively copy the left and right subtrees
    newNode->left = Copy(sourceRoot->left);
    newNode->right = Copy(sourceRoot->right);

    // Copy the height
    newNode->height = sourceRoot->height;

    return newNode;
}

template <class T>
int Bst<T>::BalanceFactor(Node* node)
{
    return Height(node->left) - Height(node->right);
}

template <class T>
typename Bst<T>::Node* Bst<T>::Insert(Node* node, long key, const T &data)
{
    if (node == nullptr)
        return new Node(key, data);

    if (key < node->key)
        node->left = Insert(node->left, key, data);
    else if (key > node->key)
        node->right = Insert(node->right, key, data);
    else
        return node;  // If the key already exists, return the existing node without changes

    node->height = 1 + max(Height(node->left), Height(node->right));

    return BalanceNode(node);
}

template <class T>
bool Bst<T>::Search(Node* node, long key) const
{
    if (node == nullptr)
    {
        return false;
    }
    else if (key < node->key)
    {
        return Search(node->left, key);
    }
    else if (key > node->key)
    {
        return Search(node->right, key);
    }
    else
    {
        return true;  // If the key is found, return true
    }
}

template <class T>
void Bst<T>::InOrder(Node* node, funcPtr process)
{
    if (node != nullptr)
    {
        InOrder(node->left, process);
        process(node->data);
        InOrder(node->right, process);
    }
}

template <class T>
void Bst<T>::PreOrder(Node* node, funcPtr process)
{
    if (node != nullptr)
    {
        process(node->data);
        PreOrder(node->left, process);
        PreOrder(node->right, process);
    }
}

template <class T>
void Bst<T>::PostOrder(Node* node, funcPtr process)
{
    if (node != nullptr)
    {
        PostOrder(node->left, process);
        PostOrder(node->right, process);
        process(node->data);
    }
}

template <class T>
void Bst<T>::DeleteTree(Node*& node)
{
    if (node != nullptr)
    {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
        node = nullptr;
    }
}

template <class T>
typename Bst<T>::Node* Bst<T>::LeftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(Height(x->left), Height(x->right)) + 1;
    y->height = max(Height(y->left), Height(y->right)) + 1;

    return y;
}

template <class T>
typename Bst<T>::Node* Bst<T>::RightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(Height(y->left), Height(y->right)) + 1;
    x->height = max(Height(x->left), Height(x->right)) + 1;

    return x;
}

template <class T>
typename Bst<T>::Node* Bst<T>::BalanceNode(Node* node)
{
    int balance = BalanceFactor(node);

    if (balance > 1 && BalanceFactor(node->left) >= 0)
        return RightRotate(node);

    if (balance < -1 && BalanceFactor(node->right) <= 0)
        return LeftRotate(node);

    if (balance > 1 && BalanceFactor(node->left) < 0)
    {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    if (balance < -1 && BalanceFactor(node->right) > 0)
    {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}

template <class T>
typename Bst<T>::Node* Bst<T>::GetNode(Node* node, long key) const
{
    if (node == nullptr)
    {
        throw runtime_error("Key not found");
    }
    else if (key < node->key)
    {
        return GetNode(node->left, key);
    }
    else if (key > node->key)
    {
        return GetNode(node->right, key);
    }
    else
    {
        return node;  // If the key is found, return the node
    }
}



//=============================
//P U B L I C    M E T H O D S
//=============================


template <class T>
void Bst<T>::Insert(long key, const T &data)
{
    root = Insert(root, key, data);
    size++;
}

template <class T>
bool Bst<T>::Search(const long key) const
{
    return Search(root, key);
}

template <class T>
void Bst<T>::InOrder(funcPtr process)
{
    InOrder(root, process);
}

template <class T>
void Bst<T>::PreOrder(funcPtr process)
{
    PreOrder(root, process);
}

template <class T>
void Bst<T>::PostOrder(funcPtr process)
{
    PostOrder(root, process);
}

template <class T>
int Bst<T>::GetHeightDifference()
{
    return BalanceFactor(root);
}

template <class T>
T& Bst<T>::GetData(long key) const
{
    Node* node = GetNode(root, key);
    return node->data;
}

template <class T>
long Bst<T>::GetSize() const
{
    return size;
}

#endif // BST_H_INCLUDED
