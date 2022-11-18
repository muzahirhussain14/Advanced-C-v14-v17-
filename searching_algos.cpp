#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    string hello{"Hello World"};
    string vowel{"aeiou"};

    // 1) Find First Of

    int index = hello.find_first_of(vowel);                 // Searches the string for the first character that matches any of the characters (in vowels) specified in its arguments.
    cout << index << "\n";


    // if we want to find the first n vowel, we can get the iterator 
    auto itr = find_first_of(begin(hello), end(hello), begin(vowel), end(vowel));
    if(itr != end(hello)) {
        cout << "First vowel: " << *itr << "\n";
        
        itr = find_first_of(next(itr), end(hello), begin(vowel), end(vowel));
        if (itr != end(hello))
            cout << "Second vowel: " << *itr << "\n";
    }


    // 2) Adjacent Find 
    // adjacent_find finds two neighboring elements that have the same value. It returns an iterator to the first element

    auto pos = adjacent_find(cbegin(hello), cend(hello));
    if (pos != cend(hello)) {
        cout << "Adjacent Find: " << *pos << '\n';                   // should return l
    }


    // 3) Search N
    // search_n() looks for a sequence of m successive elements which have the same given value.
    vector<int> vec{1,2,2,3,2,3,3};
    auto pos_1 = search_n(cbegin(vec), cend(vec), 2, 3);            // Looks for the sequence of two elements with value 3
    if (pos_1 != cend(vec))
        cout << "Index of search_n(): " << distance(cbegin(vec), pos_1) << "\n";


    // 4) Search
    // search() takes two iterator ranges and it looks for an occurance of the second iterator range inside the first range
    string str{"Hello world"};
    string sub{"wo"};

    // returns an iterato to the first element of the "wo"
    auto pos_2 = search(cbegin(str), cend(str), cbegin(sub), cend(sub));
    cout << "search() substring starting element: " << *pos_2 << '\n';


    cout << endl;
    return 0;
}