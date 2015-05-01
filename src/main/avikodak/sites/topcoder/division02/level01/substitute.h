/****************************************************************************************************************************************************
 *  File Name                   : substitute.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\substitute.h
 *  Created on                  : May 1, 2015 :: 4:41:16 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=1333
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

#ifndef SUBSTITUTE_H_
#define SUBSTITUTE_H_

class Substitute {
public:
	int getValue(string key, string code){
		map<char,int> charIndexMap;
		for(unsigned int counter = 0;counter < key.size();counter++){
			if(counter == 9){
				charIndexMap[key[counter]] = 0;
			}else{
				charIndexMap[key[counter]] = counter+1;
			}
		}
		int result = 0;
		for(unsigned int counter = 0;counter < code.size();counter++){
			if(charIndexMap.find(code[counter]) != charIndexMap.end()){
				result *= 10;
				result += charIndexMap[code[counter]];
			}
		}
		return result;
	}
};

#endif /* SUBSTITUTE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
