/****************************************************************************************************************************************************
 *  File Name   		: permut2.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\codechef\permut2.h
 *  Created on			: Feb 6, 2015 :: 6:43:56 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.codechef.com/problems/PERMUT2
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

#ifndef PERMUT2_H_
#define PERMUT2_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void arePermutationsAmbiguous(){
	int testCaseSize;
	vector<int> userInput,auxSpace;
	int number;
	bool flag;
	while(true){
		scanf("%d",&testCaseSize);
		if(testCaseSize == 0){
			break;
		}
		userInput.clear();
		auxSpace.clear();
		while(testCaseSize--){
			scanf("%d",&number);
			userInput.push_back(number);
		}
		auxSpace.assign(userInput.size(),0);
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			auxSpace[userInput[counter]-1] = counter+1;
		}
		flag = true;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			if(userInput[counter] != auxSpace[counter]){
				flag = false;
			}
		}
		if(flag){
			cout << "ambiguous" << endl;
		}else{
			cout << "not ambiguous" << endl;
		}
	}
}

#endif /* PERMUT2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
