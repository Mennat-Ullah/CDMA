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
void mulDK (int  d , int k[1000] , int Ks, int ss[1000])
{
	for(int i=0 ; i< Ks ; ++i)
		ss[i] = d * k[i]  ;


}
void mulEK (int  d[1000] , int k[1000] , int Ks, int ss[1000])
{
	for(int i=0 ; i< Ks ; ++i)
		ss[i] = d[i] * k[i]  ;


}

void sumAB (int x , int A[1000] , int B[1000] , int AB[1000])
{
	for(int i=0 ; i< x; ++i)
		AB[i] = A[i] + B[i]  ;

}
int sumX(int x , int X[1000])
{
	int t=0;
	for(int i=0 ; i< x; ++i)
		t += X[i] ;
	return t;
}
void assign (string S , int s0 , int s1 , int SS[1000])
{
	int xs = S.size() ;
	for(int i = 0 ; i < xs ; ++i)
	{
		SS[i] =  S[i]=='1' ? s1  : s0 ;
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
	//freopen("test.in", "r", stdin);

	while (1)
	{
		// take all input of A ::
		int KeySize ;
		int VA0 , VA1 ;
		cout << "	Sender A :\nEnter the value of 0 and 1 \n";
		cin >> VA0 >> VA1 ;

		string Ak ;
		int Ad ;
		cout <<"\nEnter Ak\n";
		cin >> Ak ;
		KeySize = Ak.size();
		cout << "\nEnter Ad \n" ;
		cin >> Ad ;

		int Ad_assing =  Ad ? VA1  : VA0 ;
		int As[1000] , Ak_assing[1000];
		// assign -1 , 1 to Akey value
		assign(Ak , VA0 , VA1 , Ak_assing);
		//printarr(Ak.size() , Ak_assing);
		mulDK(Ad_assing , Ak_assing , KeySize , As);
		//		printarr(Ak.size() , As);

		//------------

		// take all input of B ::
		int VB0 , VB1 ;
		cout << "	Sender B :\nEnter the value of 0 and 1 \n";
		cin >> VB0 >> VB1 ;

		string Bk ;
		int Bd ;
		cout <<"\nEnter Bk\n";
		cin >> Bk ;

		cout << "\nEnter Bd \n" ;
		cin >> Bd ;

		int Bd_assing =  Bd? VB1 : VB0 ;
		int Bs[1000] , Bk_assing[1000];
		// assign -1 , 1 to Bkey value
		assign(Bk , VB0 , VB1 , Bk_assing);
		//printarr(Ak.size() , Ak_assing);
		mulDK(Bd_assing , Bk_assing , KeySize , Bs);
		//		printarr(Ak.size() , As);

		cout << "	Both signals superimpose in space \nAs + Bs = ";
		int A_B[1000] ;
		sumAB(Bk.size() ,As ,Bs , A_B);
		printarr(Bk.size() , A_B);
		cout << endl ;

		int AE[1000] ;
		mulEK(A_B , Ak_assing , KeySize , AE);
		int Ae = sumX(KeySize , AE)  , A =  (Ae > 0) ? 1 : 0 ;
		cout << "	Receive signal from sender A :\nAe = " << Ae << "\nOriginal bit was " << A  << "\n\n" ;

		int BE[1000] ;
		mulEK(A_B , Bk_assing , KeySize , BE);
		int Be = sumX(KeySize , BE) , B = ( Be > 0) ? 1 : 0;
		cout << "	Receive signal from sender B :\nBe = " << Be << "\nOriginal bit was " <<B  << "\n\n";

		cout << " **************************************************\n\n";




	}
	return 0;
}