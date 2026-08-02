#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of cars in the parking lot"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter numberplates of cars"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    int b;
    int found=0;
    
    cout<<"Enter the number of car you want to find"<<endl;
    cin>>x;
      for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            cout<<"The Car with the numberplate "<<arr[i]<<" "<<"is at the "<<i+1<<" "<<"position"<<endl;
            found++;
            break;
        }

    } 
    
  

   
    if(found<1)
    {
        cout<<"The Car with the numberplate"<<x<<"is not present"<<endl;
    }
    return 0;
}
