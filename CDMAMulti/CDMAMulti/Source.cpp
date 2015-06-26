#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <ctype.h>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <cstdio>
#include <stdio.h>
#include <list>
#include <functional>
#include <limits>
#include <limits.h>


using namespace std;


void mulEK (int  d[1000] , int k[1000] , int Ks, int ss[1000])
{
	for(int i=0 ; i< Ks ; ++i)
		ss[i] = d[i] * k[i]  ;


}
void XOR (int  d[1000] , int k[1000] , int ds, int ss[1000])
{
	for(int i=0 ; i< ds ; ++i)
		for(int j=(i*6) ; j<(i*6)+6 ; ++j)
			if (d[i] == k[j ])
				ss[j] = 0  ;
			else
				ss[j] = 1  ;


}
void sumAB (int x , int A[1000] , int B[1000] , int AB[1000])
{
	for(int i=0 ; i< x; ++i)
		AB[i] = A[i] + B[i]  ;

}
void sum2( int ABK[1000] ,int DataSize, int sum[1000] , int data[1000] )
{
	for(int j=0 ; j<DataSize ; ++j )
	{
		int t=0;
		for(int i=(j*6) ; i< (j*6)+6 ; ++i)
			t += ABK[i] ;
		sum[j] = t;   
		data[j] =  (t < 0) ? 1 : 0 ;
	}

}
void assign (string S , int s0 , int s1 , int SS[1000])
{
	int xs = S.size() ;
	for(int i = 0 ; i < xs ; ++i)
	{
		SS[i] =  S[i]=='1' ? s1  : s0 ;
	}
}
void assign2 (int S[1000] , int xs , int s0 , int s1 , int SS[1000])
{
	for(int i = 0 ; i < xs ; ++i)
	{
		SS[i] =  S[i]==1 ? s1  : s0 ;
	}
}
void printarr(int x , int X[1000])
{
	for(int i=0 ; i<x ; ++i)
		cout << X[i] << " " ;
	cout << endl ;
}
int main ()
{
	while(1)
	{

		int KeySize , DataSize  ;
		int VA0 , VA1 ;
		cout << "		Sender A :\n		---------- \nEnter the value of 0 and 1 \n";
		cin >> VA0 >> VA1 ;

		string Ak ;
		string Ad ; 
		cout <<"\nEnter Ak\n";
		cin >> Ak ;
		KeySize = Ak.size();
		cout << "\nEnter Ad \n" ;
		cin >> Ad ;
		DataSize = Ad.size();

		int As[1000] , Ak_assing[1000] , Ad_assing [1000] ,  As_assing[1000] ;
		assign(Ad , VA0 , VA1 , Ad_assing);
		assign(Ak , VA0 , VA1 , Ak_assing);
		XOR (Ad_assing ,  Ak_assing , DataSize , As );
		assign2(As ,KeySize , VA0 , VA1 , As_assing);


		//------------

		int VB0 , VB1 ;
		cout << "\n		Sender B :\nEnter the value of 0 and 1 \n";
		cin >> VB0 >> VB1 ;

		string Bk ;
		string Bd ;
		cout <<"\nEnter Bk\n";
		cin >> Bk ;
		cout << "\nEnter Bd \n" ;
		cin >> Bd ;

		
		int Bs[1000] , Bk_assing[1000], Bd_assing [1000] , Bs_assing[1000] ;
		assign(Bd , VB0 , VB1 , Bd_assing);
		assign(Bk , VB0 , VB1 , Bk_assing);
		XOR (Bd_assing ,  Bk_assing , DataSize , Bs );
		assign2(Bs ,KeySize , VB0 , VB1 , Bs_assing);


		//------------

		cout << "\n\n		Both signals superimpose in space \nAs + Bs = ";
		int A_B[1000] ;
		sumAB(KeySize ,As_assing ,Bs_assing , A_B);
		printarr(KeySize , A_B);
		cout << endl ;

		int AE[1000] ;
		mulEK(A_B , Ak_assing , KeySize  , AE);
		int Asum[1000] ,  A[1000] ;
		sum2(AE ,DataSize, Asum , A)  ;	
		cout << "\n\n		Receive signal from sender A :\n";
		for(int i=0 ; i< DataSize ; ++i)
			cout << "Ae["<<i<<"] = " << Asum[i] << "\nOriginal bit was " << A[i]  << "\n\n" ;


		int BE[1000] ;
		mulEK(A_B , Bk_assing , KeySize , BE);
		int Bsum[1000] ,  B[1000] ;
		sum2(BE ,DataSize, Bsum , B)  ;
		cout << "		Receive signal from sender B :\n";
		for(int i=0 ; i< DataSize ; ++i)
			cout << "Be[" << i <<"] = " << Bsum[i] << "\nOriginal bit was " <<B[i]  << "\n\n";


		cout << "		 **************************************************\n\n\n";
	}
	return 0;
}
