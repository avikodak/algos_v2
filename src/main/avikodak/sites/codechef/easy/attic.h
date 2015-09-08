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
