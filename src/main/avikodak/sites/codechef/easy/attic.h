/****************************************************************************************************************************************************
 *  File Name                   : attic.h
 *  File Location               : /home/avikodak/eclipse_ws/algos/algos/src/main/avikodak/sites/codechef/easy/attic.h
 *  Created on                  : 08-Sep-2015 :: 5:57:14 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/ATTIC
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
#include <stdint.h>
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

#ifndef ATTIC_H_
#define ATTIC_H_

//Tested
void getMaxDays(string userInput){
	long int totalDays = 0,maxJumps = 0;
	unsigned int outerCounter = 0,innerCounter;
	while(outerCounter < userInput.size()){
		if(userInput[outerCounter] != '#'){
			innerCounter = outerCounter;
			while(innerCounter < userInput.size() && userInput[innerCounter] == '.'){
				innerCounter++;
			}
			if(innerCounter - outerCounter > maxJumps){
				totalDays++;
				maxJumps = innerCounter - outerCounter;
			}
			outerCounter = innerCounter;
		}
		outerCounter++;
	}
	cout << totalDays << endl;
}

//Tested
void printResults(){
	long int testCases;
	string userInput;
	cin >> testCases;
	while(testCases--){
		cin >> userInput;
		getMaxDays(userInput);
	}
}

#endif /* ATTIC_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
