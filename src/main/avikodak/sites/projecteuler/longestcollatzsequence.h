/****************************************************************************************************************************************************
 *  File Name                   : longestcollatzsequence.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\longestcollatzsequence.h
 *  Created on                  : Aug 1, 2015 :: 2:31:43 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://projecteuler.net/problem=14
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

#ifndef LONGESTCOLLATZSEQUENCE_H_
#define LONGESTCOLLATZSEQUENCE_H_

void getLongestCollatzSequence(){
	queue<unsigned long long int> values;
	map<unsigned long long int,bool> visitedValue;
	unsigned long long int counter = 0,userInput = 1;
	visitedValue.insert(pair<unsigned long long int,bool>(1,true));
	while(userInput < 1000000){
		if(visitedValue.find(2*userInput) == visitedValue.end()){
			values.push(2*userInput);
			visitedValue.insert(pair<unsigned long long int,bool>(2*userInput,true));
		}
		if(userInput-1 > 0 && (userInput-1)%3 == 0){
			if(visitedValue.find((userInput-1)/3) == visitedValue.end()){
				values.push((userInput-1)/3);
				visitedValue.insert(pair<unsigned long long int,bool>((userInput-1)/3,true));
			}
		}
		userInput = values.front();
		values.pop();
	}
	cout << visitedValue.size() << endl;
}

#endif /* LONGESTCOLLATZSEQUENCE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
