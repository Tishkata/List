#include "list.h"

int main()
{
    /** Create a list of int type, in this case we call the default constructor. */
    List<int> mylist;

    /** Add elements in front of list, in this case list will begin with 1, 2, 3. */
    mylist.push_front(3);
    mylist.push_front(2);
    mylist.push_front(1);

    /** Add elements in back of list, in this case list will become 1, 2, 3, 4, 5. */
    mylist.push_back(4);
    mylist.push_back(5);

    /** Remove element in front of list, in this case we remove 1. */
    mylist.pop_front();

    /** Remove element in back of list, in this case we remove 5. */
    mylist.pop_back();

    /** Insert element after given position, in this case list will become 2, 3, 11, 4. */
    mylist.insert_after(11, 1);

    /** Insert element before give position, in this case list will become 2, 3, 10, 11, 4. */
    mylist.insert_before(10, 2);

    /** Remove element at given position, in this case we remove 10. */
    mylist.remove_at(2);

    /** Print list using iterator */
    std::cout << "List elements: ";
    for(List<int>::Iterator itr = mylist.cbegin(); itr != mylist.cend(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    /** Create a list with the same values as the one above, in this case we call the copy constructor. */
    List<int> copyList(mylist);

    /** Print copied list */
    std::cout << "Copied list elements: ";
    for(List<int>::Iterator itr = copyList.begin(); itr != copyList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    /** Create a list with the same values as the one above, in this case we call the assignment operator. */
    List<int> assignmentList = mylist;

    /** Print assigned list */
    std::cout << "Assignment list elements: ";
    for(List<int>::Iterator itr = assignmentList.begin(); itr != assignmentList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    /** Clear assignment list */
    assignmentList.clear();
    std::cout << "Assignment list cleared? " << (assignmentList.empty() ? "Yes." : "No.") << std::endl;

    /** Create a list so that we can merge it with copied list. */
    List<int> mergeList;

    /** Add some elements, in this case list will become 20, 30, 40 */
    mergeList.push_back(20);
    mergeList.push_back(30);
    mergeList.push_back(40);

    std::cout << "Before merge: ";
    for(List<int>::Iterator itr = mergeList.begin(); itr != mergeList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    /** Merge with copied list */
    mergeList.merge(copyList);

    std::cout << "After merge: ";
    for(List<int>::Iterator itr = mergeList.begin(); itr != mergeList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    /** Create a unique list, there should not be equal elements in this list, if there is, the unique function removes them. */
    List<int> uniqueList;

    /** Add some elements, in this case list will become 25, 25, 33, 33, 46, 46, 73, 73. */
    uniqueList.push_back(25);
    uniqueList.push_back(25);
    uniqueList.push_back(33);
    uniqueList.push_back(33);
    uniqueList.push_back(46);
    uniqueList.push_back(46);
    uniqueList.push_back(73);
    uniqueList.push_back(73);

    std::cout << "Before being unique: ";
    for(List<int>::Iterator itr = uniqueList.begin(); itr != uniqueList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    /** Make the list unique */
    uniqueList.unique();

    std::cout << "After becoming unique: ";
    for(List<int>::Iterator itr = uniqueList.begin(); itr != uniqueList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    /** Process unique list */
    uniqueList.process(uniqueList);

    std::cout << "Unique list processed: ";
    for(List<int>::Iterator itr = uniqueList.begin(); itr != uniqueList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    std::cout << "Merged and processed lists before swap: ";
    for(List<int>::Iterator itr = mergeList.begin(); itr != mergeList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << "- ";

    for(List<int>::Iterator itr = uniqueList.begin(); itr != uniqueList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    /** Swap processed list with merged list */
    uniqueList.swap(mergeList);

    std::cout << "Merged and processed lists after swap: ";
    for(List<int>::Iterator itr = mergeList.begin(); itr != mergeList.end(); itr++)
    {
        std::cout << *itr << " ";
    }


    std::cout << "- ";

    for(List<int>::Iterator itr = uniqueList.begin(); itr != uniqueList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    std::cout << "Unique list before sorting: ";
    for(List<int>::Iterator itr = uniqueList.begin(); itr != uniqueList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    /** Sort merged list. */
    uniqueList.sort();

    std::cout << "Sorted unique list: ";
    for(List<int>::Iterator itr = uniqueList.begin(); itr != uniqueList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    std::cout << std::endl;

    /** Reverse sorted list. */
    uniqueList.reverse();

    std::cout << "Reversed list: ";
    for(List<int>::Iterator itr = uniqueList.begin(); itr != uniqueList.end(); itr++)
    {
        std::cout << *itr << " ";
    }

    return 0;
}
