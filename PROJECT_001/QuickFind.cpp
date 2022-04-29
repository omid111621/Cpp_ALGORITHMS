/*
//Quick-find solution to connectivity problem

//input......................
// (p, q) pairs
//functionality..............
//1. produce an array of N elements.(explaination: N > p , q)
//2. Check whether p and q are connected.
//(explaination: p and q are connected if and only if refrenceArray[p]==refrenceArray[q])
//3. if (related) do {nothing}.
//4. else {
    1. connect p and q .(explaination: array[p]=array[q] OR array[q]=array[p])
    2. print p q.
}
//by product.................
//An array of N elements whith a growing population of similar elements.
//In other words, the more we feed the program with (p,q) pairs, the more 
//elements of the array[] become similar so that eventually we have an array
//of unified numbers.
//However, notice that we cannot make any statements about the final number 
//that all of the elements will turn into. That number depends on the fashion 
//that we choose p q pairs. However, the only thing that we are certain of is that 
//the final unified number will certainly be <= N-1.

*/

#include <iostream>
using namespace std;
int main() {
    cout << "Enter p then q" << endl;
    const int n = 15;
    int p, q, referenceArray[n];
    cin >> p >> q ;
    //1. produce an array of N elements.
    for(int i = 0; i <= n; i++) referenceArray[i] = i;
    cout << referenceArray[3] << endl;

    return 0;
}



