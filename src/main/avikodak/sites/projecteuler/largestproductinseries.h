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
