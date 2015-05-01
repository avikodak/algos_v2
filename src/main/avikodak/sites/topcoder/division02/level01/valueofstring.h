/****************************************************************************************************************************************************
 *  File Name                   : valueofstring.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\valueofstring.h
 *  Created on                  : May 1, 2015 :: 3:29:30 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=13678
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

#ifndef VALUEOFSTRING_H_
#define VALUEOFSTRING_H_

class ValueOfString {
public:
	int findValue(string userInput){
		map<char,int> frequency;
		map<char,int>::iterator itToFrequency;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			if(frequency.find(userInput[counter]) == frequency.end()){
				frequency[userInput[counter]] = 1;
			}else{
				frequency[userInput[counter]] += 1;
			}
		}
		int sum = 0;
		for(itToFrequency = frequency.begin();itToFrequency != frequency.end();itToFrequency++){
			sum += itToFrequency->second;
			frequency[itToFrequency->first] = sum;
		}
		sum = 0;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			sum += (userInput[counter] -'a'+1)*(frequency[userInput[counter]]);
		}
		return sum;
	}
};

#endif /* VALUEOFSTRING_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
