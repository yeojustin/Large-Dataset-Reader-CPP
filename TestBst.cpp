#include <iostream>
#include <cassert>
#include "Bst.h"

using namespace std;

void Print(int& data)
{
    cout << data << " ";
}

int main()
{
    Bst<int> bst;
    int elements[] = {10, 20, 30, 40, 50, 25};

    // Edge Case: Empty tree
    assert(!bst.Search(10));
    assert(bst.GetSize() == 0); // Test: Empty tree size
    cout << "Test Passed: Element 10 not found and size 0 in the empty tree.\n";

    for(int i = 0; i < 6; i++)
    {
        bst.Insert(elements[i], elements[i]);
    }

    // Test: Tree size after inserting elements
    assert(bst.GetSize() == 6);
    cout << "Test Passed: Tree size is 6 after inserting 6 elements.\n";

    // Test: Search for elements
    for(int i = 0; i < 6; i++)
    {
        assert(bst.Search(elements[i]));
        cout << "Test Passed: Element " << elements[i] << " found in the tree.\n";
    }

    // Test: Search for an element not in the tree
    assert(!bst.Search(100));
    cout << "Test Passed: Element 100 not found in the tree.\n";

    // Test: Height Difference
    int heightDifference = bst.GetHeightDifference();
    assert(heightDifference >= -1 && heightDifference <= 1);
    cout << "Test Passed: Height difference is within the expected range.\n";

    // Test: InOrder, PreOrder and PostOrder traversals
    cout << "\nInOrder traversal: ";
    bst.InOrder(Print);
    cout << "\n";

    cout << "PreOrder traversal: ";
    bst.PreOrder(Print);
    cout << "\n";

    cout << "PostOrder traversal: ";
    bst.PostOrder(Print);
    cout << "\n";

    // Test: Copy constructor
    Bst<int> bstCopy(bst);
    cout << "\nCopy InOrder traversal: ";
    bstCopy.InOrder(Print);
    cout << "\n";

    // Test: Changes to original don't affect copy
    bst.Insert(60, 60);
    assert(!bstCopy.Search(60));
    cout << "Test Passed: Changes to original don't affect copy.\n";

    // Test: Changes to copy don't affect original
    bstCopy.Insert(70, 70);
    assert(!bst.Search(70));
    cout << "Test Passed: Changes to copy don't affect original.\n";

    // Edge Case: Single element tree
    Bst<int> singleElementTree;
    singleElementTree.Insert(1, 1);
    assert(singleElementTree.Search(1));
    cout << "Test Passed: Single element found in the tree.\n";

    // Edge Case: Inserting duplicate elements
    singleElementTree.Insert(1, 1);
    heightDifference = singleElementTree.GetHeightDifference();
    assert(heightDifference == 0);
    cout << "Test Passed: Duplicate insertion did not change the tree.\n";

    // Edge Case: Large inputs
    Bst<int> largeTree;
    for(int i = 0; i < 1000000; i++)
    {
        largeTree.Insert(i, i);
    }
    assert(largeTree.Search(123456));
    cout << "Test Passed: Element 123,456 found in the large tree of 1,000,000 nodes.\n";

    // Test: Height Difference after large inputs
    int heightDifferenceForLargeTree = largeTree.GetHeightDifference();
    assert(heightDifferenceForLargeTree >= -1 && heightDifferenceForLargeTree <= 1);
    cout << "Test Passed: Height difference is within the expected range for a large tree.\n";

    // Test: Size for large inputs
    assert(largeTree.GetSize() == 1000000);
    cout << "Test Passed: Size is 1,000,000 for a large tree.\n";

    cout << "\nAll tests passed!\n";

    return 0;
}
