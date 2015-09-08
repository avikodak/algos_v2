/****************************************************************************************************************************************************
 *  File Name                   : largestproductinseries.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\largestproductinseries.h
 *  Created on                  : Jul 29, 2015 :: 3:30:47 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=8
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LARGESTPRODUCTINSERIES_H_
#define LARGESTPRODUCTINSERIES_H_

//Tested
long long int max(long long int first,long long int second){
	return first > second?first:second;
}

//Tested
long long int largestProductInSeries(vector<string> userInput,unsigned int size){
	long long int maxProduct = LONG_LONG_MIN;
	long long int currentProduct = 1;
	for(unsigned int rowCounter = 0;rowCounter < userInput.size();rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < userInput[0].size()-size+2;columnCounter++){
			currentProduct = 1;
			for(unsigned int counter = 0;counter < size;counter++){
				currentProduct *= (userInput[rowCounter][columnCounter+counter] - '0');
			}
			maxProduct = max(currentProduct,maxProduct);
		}
	}
	return maxProduct;
}

//Tested
//Ans : 23514624000
void printLargestProduct(){
	unsigned int testCases;
	cin >> testCases;
	vector<string> userInput;
	string input;
	while(testCases--){
		cin >> input;
		userInput.push_back(input);
	}
	cout << largestProductInSeries(userInput,13);
}

#endif /* LARGESTPRODUCTINSERIES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
