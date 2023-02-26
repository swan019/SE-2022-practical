// codesbon019 

#include <bits/stdc++.h>
using namespace std;
#define size 10

int hf(int key)
{
    return (key % size);
}

int probing(int t[],int key)
{
    int i = 0;
    int index = hf(key);

    while(t[(index + (i*i))%size] != 0)
    {
        i++;
    }

    return (index + (i*i) % size);
}

void insert(int t[],int key)
{
    int index = hf(key);

    if(t[index] != 0)
    {
        index = probing(t,key);
    }

    t[index] = key;
}

void print(int t[])
{
    for(int i = 0; i < size; ++i)
    {
        cout << t[i] << " ";
    }

    cout << endl;
}

int search(int t[], int key)
{
    int index = hf(key);

    if(t[index] == key)
    {
        return index;
    }else
    {
        int i = 0;
        while(t[index + (i*i) % size] != key)
        {
            i++; 
            if(t[index + (i*i)%size] == 0)
            {
                return -1;
            }
        }

        return (index+(i*i)%size);
    }
}

int main()
{
    

    int ht[size] = {0};

    insert(ht,11);
    insert(ht,10);
    insert(ht,22);
    insert(ht,134);
    insert(ht,34);
    insert(ht,434);
    insert(ht,341);

 

    print(ht);

    cout << search(ht,11) << endl;
    cout << search(ht,10) << endl;
    cout << search(ht,111) << endl;
    cout << search(ht,341) << endl;


    return 0;
}
