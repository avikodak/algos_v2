/****************************************************************************************************************************************************
 *  File Name                   : twostr.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codechef\school\twostr.h
 *  Created on                  : Aug 30, 2015 :: 2:50:16 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/TWOSTR
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

#ifndef TWOSTR_H_
#define TWOSTR_H_

//Tested
bool isMatching(string firstUserInput,string secondUserInput){
	unsigned int firstCounter = 0,secondCounter = 0;
	while(firstCounter < firstUserInput.size() && secondCounter < secondUserInput.size()){
		if(firstUserInput[firstCounter] != secondUserInput[secondCounter]){
			if(firstUserInput[firstCounter] != '?' && secondUserInput[secondCounter] != '?'){
				return false;
			}
		}
		firstCounter++;
		secondCounter++;
	}
	return firstCounter >= firstUserInput.size() && secondCounter >= secondUserInput.size();
}

//Tested
void printResults(){
	unsigned int testCases;
	scanf("%u",&testCases);
	string first,second;
	while(testCases--){
		cin >> first >> second;
		printf("%s\n",isMatching(first,second)?"Yes":"No");
	}
}

#endif /* TWOSTR_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
