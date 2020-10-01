#include "linked_list.h"

using namespace std;

int main()
{
    LinkedList<int> list1;
    list1.push(5);
    list1.push(5);
    list1.push(5);
    list1.push(2);
    list1.push(1);

    cout<<"The following list has 3 iterations of 5."<<endl;
    list1.print();
    cout<<"The count method should return 3, it returns: "<<list1.count(5)<<endl;

    cout<<endl;

    cout<<"Deleting list with deleteList method..."<<endl;
    list1.deleteList();
    cout<<"List has been deleted, is_empty method should now return 1, it returns: "<<list1.is_empty()<<endl;

    cout<<endl;

    LinkedList<int> list2;
    list2.push(5);
    list2.push(4);
    list2.push(2);
    list2.push(1);

    Node<int> newNode(3,NULL);

    cout<<"The following list is missing a three, the sortedInsert method should place it in the middle."<<endl;
    list2.print();
    list2.sortedInsert(&newNode);
    cout<<"After using sortedInsert the list now looks like this: "<<endl;
    list2.print();

    cout<<endl;

    LinkedList<int> list3;
    list3.push(5);
    list3.push(5);
    list3.push(5);
    list3.push(3);
    list3.push(3);
    list3.push(1);

    cout<<"The following list has 5 and 3 multiple times, the removeDuplicates method should remove them."<<endl;
    list3.print();
    list3.removeDuplicates();
    cout<<"After running removeDuplicates, the list now looks like this: "<<endl;
    list3.print();

    cout<<endl;

    LinkedList<int> list4;
    list4.push(5);
    list4.push(3);
    list4.push(4);
    list4.push(2);
    list4.push(1);

    cout<<"The following list is in a particular order."<<endl;
    list4.print();
    list4.reverse();
    cout<<"After running the reverse method it should now be: 5,3,4,2,1"<<endl;
    cout<<"It now looks like this: "<<endl;
    list4.print();

    return 0;
}