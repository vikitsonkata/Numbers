#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

//if the number discribes itself,
// e.g. 14233221 has 1 4, 2 3s, 3 2s and 2 1s in it
// descending order of numbers in pairs in selfdiscription
int SpecialNum(uint64_t num, int descending = 0)
{
    int countDigits[10];
    for(auto &i: countDigits) i = 0;

    int size = 0;
    for(uint64_t n = num; n; n /= 10)
    {
        ++size;
        ++countDigits[n%10];
    }
    // have to be with with even digits
    if(size % 2)
        return false;

    //to describe exactly itself
    int sum = 0;
    int i = num%10;
    while(num != 0)
    {
        int d = num % 10;
        if(descending && d != i)
            return false;
        i += descending;
        num /= 10;
        int count = num % 10;
        sum += count;
        num /= 10;
        if(count != (countDigits[d]))
            return false;
    }

    if(sum != size)
        return false;

    return true;
}

void SearchForSpecialNumbers()
{
    cout << "Start" << endl;
    cout << "Looking for Special numbers less than " << UINT64_MAX << endl;
    for(uint64_t i = 1; i < UINT64_MAX; ++i)
    {
        if(SpecialNum(i, 1))
            cout << "Special Number is " << i << endl;
        if(i == 14233221 || i == 14331231 || i == 1514332231)
            cout << "known special number: " << i << endl;

        if(i % 100000000 == 0)
            cout << i*100.0/UINT64_MAX << "%\t\t" << i << endl;
    }
    cout << "End" << endl;
}

void BuildSpecialNumbers()
{
     for(uint32_t i = 1, j = 1, size = 1; i < 1000000000; ++i)
     {
         if(i == j)
         {
             cout << "\t** LEVEL " << size << " **" << endl;
             j *= 10;
             size ++;
         }
         auto num = i;
         uint32_t descendingDigits {987654321};
         uint64_t testNumD = 0;
         while(num)
         {
             testNumD *= 10;
             testNumD += num%10;
             num /= 10;

             testNumD *= 10;
             testNumD += descendingDigits%10;
             descendingDigits /= 10;
         }
         if(SpecialNum(testNumD, -1) || SpecialNum(testNumD, 1))
         {
             cout << "SpecialNum:\t";
             while(testNumD)
             {
                 cout << testNumD%100 << " ";
                 testNumD /= 100;
             }
             cout << endl;
         }
     }
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main()
{
    BuildSpecialNumbers();
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
