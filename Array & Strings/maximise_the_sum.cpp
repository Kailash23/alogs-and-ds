#include<iostream>
using namespace std;

	long maxPathSum(int ar1[], int ar2[], int m, int n){
		long maxSum=0, s1=0, s2=0;
		int i=0, j=0;

		while(i<m && j<n){
			if(ar1[i]<ar2[j]){
				s1+=ar1[i++];
			} else if(ar1[i]==ar2[j]){
				s1+=ar1[i++];
				s2+=ar2[j++];

				maxSum+=max(s1,s2);
				s1=0;
				s2=0;
			} else {
				s2+=ar2[j];
				j++;
			}
		}

		while (i<m) {
			s1+=ar1[i];
			i++;
		}

		while (j<n) {
			s2+=ar2[j];
			j++;
		}
	  	maxSum+=max(s1,s2);
		return maxSum;
	}

int main(){
	int ar1[] = {1,5,10,15,20,25};
	int m = sizeof(ar1)/sizeof(ar1[0]);
	int ar2[] = {2,4,5,9,15};
	int n = sizeof(ar2)/sizeof(ar2[0]);
	cout<<maxPathSum(ar1,ar2,m,n);
}
