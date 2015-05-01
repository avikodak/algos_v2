/****************************************************************************************************************************************************
 *  File Name                   : valueaddedtax.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\valueaddedtax.h
 *  Created on                  : May 1, 2015 :: 7:00:04 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=7894
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

#ifndef VALUEADDEDTAX_H_
#define VALUEADDEDTAX_H_

class ValueAddedTax {
public:
	double calculateFinalPrice(string product, int price, vector<string> food){
		bool isFoodProduct = false;
		for(unsigned int counter = 0;counter < food.size();counter++){
			if(product.compare(food[counter]) == 0){
				isFoodProduct = true;
				break;
			}
		}
		double total = price;
		if(isFoodProduct){
			total += (double)(0.1) * (double)(price);
		}else{
			total += (double)(0.18) * (double)(price);
		}
		return total;
	}
};

#endif /* VALUEADDEDTAX_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
