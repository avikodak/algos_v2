/****************************************************************************************************************************************************
 *  File Name                   : strangecomputer.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\page03\strangecomputer.h
 *  Created on                  : Jul 26, 2015 :: 12:06:13 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=10537
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

#ifndef STRANGECOMPUTER_H_
#define STRANGECOMPUTER_H_

//Tested
class StrangeComputer {
public:
	int setMemory(string mem){
		int total = 0;
		unsigned int outerCounter = 0,innerCounter =0;
		while(outerCounter < mem.size() && mem[outerCounter] == '0'){
			outerCounter++;
		}
		while(outerCounter < mem.size()){
			innerCounter = outerCounter;
			total++;
			while(innerCounter < mem.size() && mem[innerCounter] == mem[outerCounter]){
				innerCounter++;
			}
		}
		return total;
	}
};

#endif /* STRANGECOMPUTER_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/