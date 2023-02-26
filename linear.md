// codesbon019
#include <bits/stdc++.h>
using namespace std;
#define size 10

int hash_function(int key)
{
    return key % size;
}

int probing(int table[], int key)
{
    int i = 0;
    int index = hash_function(key);
    while (table[(index + i)%size] != 0)
    {
        i++;
    }

    return (index+i)%size;
}

void insert(int table[], int key)
{
    int index = hash_function(key);
    if (table[index] != 0)
    {
        index = probing(table, key);
    }

    table[index] = key;
}

int search(int table[], int val)
{
    int index = hash_function(val);
    if(table[index] == val)
    {
        return index;

    }else
    {
        int i = index;
        while(table[i%size] != val)
        {
            i++;
            if(table[i%size] == 0)
            {
                return -1;
            }
        }
        return i%size;
    }

    
}

int main()
{
    int hash_table[size] = {0};
    insert(hash_table, 12);
    insert(hash_table, 14);
    insert(hash_table, 75);
    insert(hash_table, 68);
    insert(hash_table, 129);
    insert(hash_table, 15);


    for (int i = 0; i < 10; ++i)
    {
        cout << hash_table[i] << " ";
    }
    cout << endl;

    cout << search(hash_table,12) << endl;
    cout << search(hash_table,15) << endl;
    cout << search(hash_table,129) << endl;
    cout << search(hash_table,1212) << endl;

    return 0;
}
