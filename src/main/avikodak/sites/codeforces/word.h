/****************************************************************************************************************************************************
 *  File Name                   : word.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\codeforces\word.h
 *  Created on                  : Apr 11, 2015 :: 9:42:58 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://codeforces.com/problemset/problem/59/A
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

#ifndef WORD_H_
#define WORD_H_

//Tested
void changeCaseWord(){
	string userInput;
	cin >> userInput;
	unsigned int lowerCaseCount = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] >= 'a' && userInput[counter] <= 'z'){
			lowerCaseCount++;
		}
	}
	if(lowerCaseCount >= userInput.size() - lowerCaseCount){
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			if(userInput[counter] >= 'A' && userInput[counter] <= 'Z'){
				userInput[counter] = userInput[counter] - 'A' + 'a';
			}
		}
	}else{
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			if(userInput[counter] >= 'a' && userInput[counter] <= 'z'){
				userInput[counter] = userInput[counter] - 'a' + 'A';
			}
		}
	}
	cout << userInput;
}

#endif /* WORD_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
