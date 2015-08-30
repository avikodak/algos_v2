/****************************************************************************************************************************************************
 *  File Name                   : brackets.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\brackets.h
 *  Created on                  : Aug 30, 2015 :: 1:47:36 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/BRACKETS
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

#ifndef BRACKETS_H_
#define BRACKETS_H_

//Tested
unsigned int getMaxLength(string userInput){
	unsigned int maxLength = 0,balance =0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == '('){
			balance++;
		}else{
			balance--;
		}
		maxLength = max(maxLength,balance);
	}
	return maxLength;
}

//Tested
void printSequence(string userInput){
	unsigned int maxLen = getMaxLength(userInput);
	string newSeq;
	for(unsigned int counter = 0;counter < maxLen;counter++){
		newSeq.append("(");
	}
	for(unsigned int counter = 0;counter < maxLen;counter++){
		newSeq.append(")");
	}
	cout << newSeq << endl;
}

//Tested
void printResults(){
	unsigned int testCases;
	scanf("%u",&testCases);
	string userInput;
	while(testCases--){
		cin >> userInput;
		printSequence(userInput);
	}
}

#endif /* BRACKETS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
