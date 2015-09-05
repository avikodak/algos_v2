/****************************************************************************************************************************************************
 *  File Name                   : maxdiff.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\easy\maxdiff.h
 *  Created on                  : Sep 4, 2015 :: 8:53:47 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/MAXDIFF
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

#ifndef MAXDIFF_H_
#define MAXDIFF_H_

//Tested
void printMinDifference(vector<unsigned int> userInput,int kValue,int sum){
	int firstKSum=0,lastKSum = 0;
	sort(userInput.begin(),userInput.end());
	for(int counter = 0;counter < kValue;counter++){
		firstKSum += userInput[counter];
	}
	for(int counter = userInput.size()-1;kValue--;counter--){
		lastKSum += userInput[counter];
	}
	cout << max(abs(firstKSum - (sum-firstKSum)),abs(lastKSum-(sum-lastKSum))) << endl;
}

//Tested
void printResults(){
	unsigned int testCases,input,size;
	int kValue,sum;
	scanf("%u",&testCases);
	vector<unsigned int> userInput;
	while(testCases--){
		scanf("%u %u",&size,&kValue);
		userInput.clear();
		sum = 0;
		while(size--){
			scanf("%u",&input);
			sum += input;
			userInput.push_back(input);
		}
		printMinDifference(userInput,kValue,sum);
	}
}

#endif /* MAXDIFF_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
