/****************************************************************************************************************************************************
 *  File Name   		: sherlockandarray.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\hackerrank\implementation\sherlockandarray.h
 *  Created on			: Feb 10, 2015 :: 6:45:22 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: https://www.hackerrank.com/challenges/sherlock-and-array
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SHERLOCKANDARRAY_H_
#define SHERLOCKANDARRAY_H_

//Tested
void doesEquilibriumElementExists(){
	int testCases,size;
	long int input,sumOfArray,leftSum;
	scanf("%d",&testCases);
	vector<int> userInput;
	bool flag;
	while(testCases--){
		scanf("%d",&size);
		sumOfArray = 0;
		userInput.clear();
		while(size--){
			scanf("%ld",&input);
			sumOfArray += input;
			userInput.push_back(input);
		}
		leftSum = 0;
		flag = false;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			if(leftSum == sumOfArray - leftSum - userInput[counter]){
				flag = true;
				break;
			}
			leftSum += userInput[counter];
		}
		printf("%s\n",flag?"YES":"NO");
	}
}

#endif /* SHERLOCKANDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
