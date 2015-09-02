/****************************************************************************************************************************************************
 *  File Name                   : gcd2.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\gcd2.h
 *  Created on                  : Sep 2, 2015 :: 9:11:54 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/GCD2
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

#ifndef GCD2_H_
#define GCD2_H_

//Tested
unsigned int gcd(unsigned int A,unsigned int B){
	if(A == 1 || B == 1){
		return 1;
	}
	if(B%A == 0){
		return A;
	}
	return gcd(B%A,A);
}

//Tested
void printGCD(unsigned int userInput,string strInput){
	unsigned int dividend = 0;
	for(unsigned int counter = 0;counter < strInput.size();counter++){
		dividend = (dividend << 3) + (dividend << 1) + strInput[counter]-'0';
		dividend = dividend%userInput;
	}
	cout << gcd(userInput,dividend) << endl;
}

//Tested
void printResults(){
	unsigned int testCases,input;
	string strInput;
	scanf("%u",&testCases);
	while(testCases--){
		cin >> input >> strInput;
		if(input == 0 || strInput.compare("0") == 0){
			if(input == 0 && strInput.compare("0") == 0){
				printf("0\n");
			}else{
				if(input == 0){
					cout << strInput << endl;
				}else{
					printf("%u",input);
				}
			}
		}else{
			printGCD(input,strInput);
		}
	}
}

#endif /* GCD2_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
