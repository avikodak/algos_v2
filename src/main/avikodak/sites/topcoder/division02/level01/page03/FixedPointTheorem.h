/****************************************************************************************************************************************************
 *  File Name                   : FixedPointTheorem.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\page03\FixedPointTheorem.h
 *  Created on                  : Jul 22, 2015 :: 8:52:19 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=1765
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

#ifndef FIXEDPOINTTHEOREM_H_
#define FIXEDPOINTTHEOREM_H_

//Tested
class FixedPointTheorem {
private:
	double static minValue(double firstValue,double secondValue){
		return firstValue < secondValue?firstValue:secondValue;
	}

	double maxValue(double firstValue,double secondValue){
		return firstValue > secondValue?firstValue:secondValue;
	}
public:
	double cycleRange(double R){
		double x = 0.25;
		for(long int counter = 0;counter <= 2000000;counter++){
			x = R * x * (1-x);
		}
		double minVal = x,maxVal = x;
		for(long int counter = 2000000;counter < 200999;counter++){
			x = R * x * (1-x);
			minVal = minValue(minVal,x);
			maxVal = maxValue(maxVal,x);
 		}
		return maxVal - minVal;
	}
};

#endif /* FIXEDPOINTTHEOREM_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
