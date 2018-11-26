#include <iostream>
#include <vector>
#include <string>

using namespace std;

//rvalues represents a temporary object that has no identity. rvalues give
// away ownership of its resources

vector<int> get_a_vector();

int main()
{
    vector<string> v0{"CHUKS", "mmadu", "good will", "hello", "königberger"}; //v0 is an lvalue

    auto v1 = move(v0);

    for (int i = 0; i < v1.size(); i++)
        cout << "v[" << i << "]: " << v1[i] << ", ";
    cout << endl;

    /* If we try to instance a new vector v1 with the lvalue v0, we are 
    forced to perform a copy of the v0 internal buffer to v1 and also an 
    allocation. A possible alternative consists of releasing the ownership 
    of the source vector's buffer and giving it away to the destination vector. 
*/

    //So, when can that be done safely? We can only do that when the source is an
    //rvalue because it doesn't have any identity and it's about to expire.
    //auto v2 = get_a_vector();

    //int arr[] = {1,2,3,4,5,6};

    int data = 1000;

    auto *arr_ptr = new int[data];
    cout << "size of the new array: " << sizeof(arr_ptr) * data << endl;

    for (int i = 0; i < data; i++)
    {
        arr_ptr[i] = 8000 + i;
        cout << "arr_ptr[" << i << "]: " << arr_ptr[i] << endl;
    }

    delete[] arr_ptr;

    cout << "after deleteing..." << endl;

    cout << "arr_ptr["
         << "5"
         << "]: " << arr_ptr[4] + 1 << endl;

    cout << "size after deleting: " << sizeof(arr_ptr) * data << endl;
}