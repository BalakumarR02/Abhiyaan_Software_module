#include <bits/stdc++.h>
using namespace std;

 // Algorithm: The midpoint of the range where 1's are present is the position to which the minimum swaps can occur
int main() 
{  
    long long int n,a[100000],i,ans=0,io=INT_MAX,fo=0,mid=0;
    //Getting value of n
    cout<<"Enter value of n: ";
    cin>>n;

    //Getting array of 1's and 0's
    cout<<"Enter value for array:\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1 && i<io)
        {
            io=i;      // Storing the index of first 1 present in array into io
        } 
         if(a[i]==1 )
         {
             fo=i;     // Storing the index of last 1 present in array into fo
         }
    }
    mid=(fo+io+1)/2;   // Storing the index of midpoint of range of 1's present in array into mid

    // Iterating from io to fo to find minimum number of swaps to group all 1's together   
    for(i=io;i<=fo;i++)
    {
         
        if(a[i]==1 && i!=mid)
        {
            ans+=abs(mid-i)-1;     // ans = Storing number of swaps 
                        

        }
    }
    // Printing the result
    cout<<"Minimum number of swaps: "<<ans;    
    return 0;
}
