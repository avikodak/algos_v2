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
