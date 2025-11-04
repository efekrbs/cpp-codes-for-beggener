#include <iostream>
#include <ostream>
#include <string>

using namespace std;


int arrayMax(int array[10]){
    int maxNum = array[0];
    for (int i = 1; i < 10; i++)
    {
        if (maxNum < array[i])
        {
            maxNum = array[i];
        }
        
    }
    
    cout << maxNum << endl;
    return maxNum;

}

int main(){

    int array[10]={1,2,11,4,5,6,7,8,9,0};
    arrayMax(array);
    return 0;

}

