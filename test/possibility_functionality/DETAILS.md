# possibility_functionality #
Unit tests for sanity validation that the Possibility class works as intended.

```c++
/*
Class Methods Tested:
    Possibility::Possibility(); // constructor

Expectations:
    Constructor saves the intended input value 
*/
void test_init();

/*
Class Methods Tested:
    Possibility::push();

Expectations:
    New Possibility nodes are appended to the end of the linked list.
*/
void test_push_unsorted();

/*
Class Methods Tested:
    Possibility::push();

Expectations:
    New Possibility nodes are placed into the list in numerical order.
*/
void test_push_sorted();

/*
Class Methods Tested:
    Possibility::push();

Expectations:
    Duplicate Possibility nodes are NOT placed into the list.
*/
void test_push_duplicate();

/*
Class Methods Tested:
    Possibility::remove();

Expectations:
    Removes Possibility nodes from the lhs.
    Case 1: Removed node is at the left-end of the list.
    Case 2: Removed node points to more nodes to the left.
*/
void test_remove_unsorted();

/*
Class Methods Tested:
    Possibility::remove();

Expectations:
    Removes Possibility nodes from the rhs.
    Case 1: Removed node is at the right-end of the list.
    Case 2: Removed node points to more nodes to the right.
*/
void test_remove_sorted();

/*
Class Methods Tested:
    Possibility::remove();

Expectations:
    Removes Possibility node at the head.
    Case 1: More than 1 node on list.
        Head node will replace its members with the member values from its previous neighbor (lhs).
        If no previous neighbor, then it will replace from its next neighbor (rhs).
        The duplicated neighbor will be deleted.

    Case 2: Only 1 node on list.
        Head node will be deleted, and return nullptr.
*/
void test_remove_self();
```