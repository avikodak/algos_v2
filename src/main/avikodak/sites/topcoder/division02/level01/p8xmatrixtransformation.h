/****************************************************************************************************************************************************
 *  File Name                   : p8xmatrixtransformation.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\p8xmatrixtransformation.h
 *  Created on                  : Jul 17, 2015 :: 8:10:26 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=11056
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

#ifndef P8XMATRIXTRANSFORMATION_H_
#define P8XMATRIXTRANSFORMATION_H_

//Tested
class P8XMatrixTransformation {
public:
	string solve(vector<string> original,vector<string> target){
		unsigned zeroCount[2] = {0},oneCount[2] = {0};
		for(unsigned int rowCounter = 0;rowCounter < original[0].size();rowCounter++){
			for(unsigned int columnCounter = 0;columnCounter < original.size();columnCounter++){
				if(original[rowCounter][columnCounter]=='0'){
					zeroCount[0]++;
				}else{
					oneCount[0]++;
				}
			}
		}
		for(unsigned int rowCounter = 0;rowCounter < target[0].size();rowCounter++){
			for(unsigned int columnCounter = 0;columnCounter < target.size();columnCounter++){
				if(target[rowCounter][columnCounter]=='0'){
					zeroCount[1]++;
				}else{
					oneCount[1]++;
				}
			}
		}
		return zeroCount[0] == zeroCount[1] && oneCount[0] == oneCount[1]?"YES":"NO";
	}
};

#endif /* P8XMATRIXTRANSFORMATION_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
