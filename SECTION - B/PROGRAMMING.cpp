#include <bits/stdc++.h>
using namespace std;

 // Algorithm: The midpoint of the range where 1's are present is the position to which the minimum swaps can occur to group all 1's
int main() 
{  
    long long int n,a[100000],i,ans=0,mid=0,ones[100000],k=0;
    //Getting value of n
    cout<<"Enter value of n: ";
    cin>>n;

    //Getting array of 1's and 0's
    cout<<"Enter value for array:\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
         if(a[i]==1 )
         {
            ones[k]=i;     // Storing the index of 1's present in array into ones
            k++;
         }
    }

    

    mid=(k)/2;   // Storing the index of midpoint of range of 1's present in array into mid

    // Iterating from 0 to k to find minimum number of swaps to group all 1's together   
    
    for(i=0;i<k;i++)
    {        
        ans+=abs(ones[mid]-ones[i])-abs(mid-i);    // abs(ones[mid]-ones[i])-abs(mid-i) gives count of number of swaps for ith 1 to reach the desired position
                                                    // abs(ones[mid]-ones[i]) gives count of numbers between the mid and the ith 1(inclusive of the ith 1)
                                                     // abs(mid-i) gives count of 1's between the mid and the ith 1(inclusive of the ith 1)
                                                     
    }
    // Printing the result
    cout<<"Minimum number of swaps: "<<ans;    
    return 0;
}
