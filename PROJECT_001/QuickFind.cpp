/*
//Quick-find solution to connectivity problem

//input......................
// N and (p, q) pairs
//functionality..............
//1. produce an array of N elements and print it.(explaination: N > p , q)
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
#include <iterator> //std::ostream_iterator
#include <algorithm> //std::copy
using namespace std;


int main() {
    cout << "Enter the value for N" << endl;
    int n;
    cin >> n;
    const int N = n; // It is a good practice to give "those parameters that we do not want to change" a type of "const".
    int p, q, referenceArray[N];

    // produce an array of N elements.....................
    for(int i = 0; i < N; i++) referenceArray[i] = i;
    //print referenceArray................................
    cout << "You referenceArray is :" << endl;
    ostream_iterator <int> out_it (cout, ",");
    copy (referenceArray, referenceArray + N, out_it);
    cout << endl;
    //Ask user for p and q pairs..........................
    cout << "Please enter your pair p q" << endl;

    //Main program begins here!...........................
     while (cin >> p >> q) { 
         
          
         if ( referenceArray[p] == referenceArray[q]) {
            cout << "p , q are  related" << endl;
            copy (referenceArray, referenceArray + N, out_it);
            cout << endl;
             continue;
             }
            int memory = referenceArray [p];// Tricky point. Notice to the next comment.
            for(int i = 0; i < N; i++){
            //int memory = referenceArray [p]; // There is a tricky point here! we should not define our "memory" here.
                                               // The reason is that, although in the "for loop" the value of "p" do not change.
                                               // But, the value of "referenceArray[p]" is very likely to change then "memory"
                                               // will change, and that cuase bugs. 
                                               // To illustrate, the valuse of referenceArray[p] may change because the valuse of 
                                               // referenceArray[i] is changing incrimently, and at some point the value of "i" happens 
                                               // to be similar to the value of "p" !!!!
                                               // So, be extra careful.
                if ( referenceArray[i] == memory) referenceArray [i] = referenceArray [q];
            }
            cout << "Dear User,\n"<< p << "and" << q << "are not related!\nBut do not worry! I have just made them related!\nYour referenceArray has changed into :" << endl;
            //print referenceArray............................
            copy (referenceArray, referenceArray + N, out_it);
            cout << endl;
            //Ask user for new input..........................
            cout << "Please enter another pair" << endl;
             
     }
   
    return 0;
}

// Here, you can find a simpler version of the program.

// #include <iostream.> 
// using namespace std;
// static const int N = 10;
// int main (){
//     int i, p, q, id[N];
//     for (i=0; i < N; i++) id[i] = i;
//     while (cin >> p >> q) {
//         int t = id[p];
//         if (t == id[q]) continue;
//         for (i=0; i < N; i++)
//             if(id [i] == t) id[i] = id[q];
//         cout << "" << p << "" << q << endl;
//          
//     }
// }



