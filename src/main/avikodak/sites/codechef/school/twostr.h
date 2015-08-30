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
