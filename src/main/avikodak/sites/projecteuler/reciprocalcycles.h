/****************************************************************************************************************************************************
 *  File Name                   : reciprocalcycles.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\reciprocalcycles.h
 *  Created on                  : Aug 27, 2015 :: 12:07:10 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=26
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

#ifndef RECIPROCALCYCLES_H_
#define RECIPROCALCYCLES_H_

//Tested
unsigned int getReciprocalLength(unsigned int userInput){
	map<unsigned int,bool> visitedRemainders;
	vector<unsigned int> visitedRemaindersList;
	unsigned int numerator = 1,remainder;
	while((remainder = numerator%userInput) != 0){
		if(visitedRemainders.find(remainder) != visitedRemainders.end()){
			unsigned int counter;
			for(counter = 0;counter < visitedRemaindersList.size();counter++){
				if(visitedRemaindersList[counter] == remainder){
					break;
				}
			}
			return visitedRemainders.size() - counter;
		}
		visitedRemainders.insert(pair<unsigned int,bool>(remainder,true));
		visitedRemaindersList.push_back(remainder);
		numerator = remainder*10;
	}
	return 0;
}

//Tested
void getLongestReciprocalCycle(){
	unsigned int maxLength = 0,cycleLength,maxLengthValue;
	for(unsigned int counter = 2;counter < 1000;counter++){
		cycleLength = getReciprocalLength(counter);
		if( maxLength < cycleLength){
			maxLength =cycleLength;
			maxLengthValue = counter;
		}
	}
	cout << maxLengthValue << endl;
}

#endif /* RECIPROCALCYCLES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
