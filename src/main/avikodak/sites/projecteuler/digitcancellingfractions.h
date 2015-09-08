/****************************************************************************************************************************************************
 *  File Name                   : digitcancellingfractions.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\digitcancellingfractions.h
 *  Created on                  : Aug 16, 2015 :: 10:42:28 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=33
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef DIGITCANCELLINGFRACTIONS_H_
#define DIGITCANCELLINGFRACTIONS_H_

//Tested
struct fraction{
	unsigned int numerator;
	unsigned int denominator;

	fraction(){};
	fraction(unsigned int numerator,unsigned int denominator){
		this->numerator = numerator;
		this->denominator = denominator;
	}
};

//Tested
unsigned int reverseNumber(unsigned int userInput){
	unsigned int reverse = 0;
	while(userInput){
		reverse = (reverse << 1)+(reverse << 3)+userInput%10;
		userInput /= 10;
	}
	return reverse;
}

//Tested
fraction * reduceFraction(unsigned int numerator,unsigned int denominator){
	unsigned flags[10] ={0};
	unsigned int temp = numerator;
	while(temp){
		flags[temp%10]++;
		temp /= 10;
	}
	unsigned int reducedDenominator = 0;
	denominator = reverseNumber(denominator);
	while(denominator){
		if(flags[denominator%10] > 0){
			flags[denominator%10]--;
		}else{
			reducedDenominator *= 10;
			reducedDenominator += denominator%10;
		}
		denominator /= 10;
	}
	unsigned int reducedNumerator = 0;
	temp = reverseNumber(numerator);
	while(temp){
		if(flags[temp%10] > 0){
			reducedNumerator *= 10;
			reducedNumerator += temp%10;
			flags[temp%10]--;
		}
		temp /= 10;
	}
	return new fraction(reducedNumerator,reducedDenominator);
}

//Tested
unsigned int gcd(unsigned int a,unsigned int b){
	if(a == 1 || b == 1){
		return 1;
	}
	if(b%a == 0){
		return a;
	}
	return gcd(a%b,a);
}

//Tested
//Ans : 100
void getProductDenominator(){
	fraction *reducedResult;
	unsigned int productOfDenominator = 1,productNumerator = 1;
	for(unsigned int numerator = 11;numerator < 100;numerator++){
		for(unsigned int denominator = numerator+1;denominator < 100;denominator++){
			if(denominator %10 ==0 || (numerator%10 == numerator/10)){
				continue;
			}
			reducedResult = reduceFraction(numerator,denominator);
			if(reducedResult->numerator  != numerator && (double)reducedResult->numerator/(double)reducedResult->denominator == ((double)(numerator)/(double)(denominator))){
				productNumerator *= reducedResult->numerator;
				productOfDenominator *= reducedResult->denominator;
			}
		}
	}
	cout << productOfDenominator/(gcd(productNumerator,productOfDenominator)) << endl;
}

#endif /* DIGITCANCELLINGFRACTIONS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/