#include <iostream>

using namespace std;

int main() {
	int t,n;
	
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int v=n;
	    int tax=0;
	    if (n>1500000) {
	        tax+=0.30*(n-1500000); 
	        n=1500000; 
	    }
	    if(n>1250000&&n<=1500000) {
	        tax+=0.25*(n-1250000);
	        n=1250000;
	    }
	    if(n>1000000&&n<=1250000) {
	        tax+=0.20*(n-1000000);
	        n=1000000;
	    }
	    if(n>750000&&n<=1000000) {
	        tax+=0.15*(n-750000);
	        n=750000;
	    }
	    if(n>500000&&n<=750000) {
	        tax+=0.10*(n-500000);
	        n=500000;
	    }
	    if(n>250000&&n<=500000) {
	        tax+=0.05*(n-250000);
	        n=250000; 
	    }
	    cout<<v-tax<<"\n";
	}
	return 0;
}