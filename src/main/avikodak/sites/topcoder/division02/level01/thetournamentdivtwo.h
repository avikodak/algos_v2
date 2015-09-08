/****************************************************************************************************************************************************
 *  File Name                   : thetournamentdivtwo.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\thetournamentdivtwo.h
 *  Created on                  : Jul 18, 2015 :: 1:19:45 PM
 *  Author                      : avikodak
 *  Testing Status              : Locally Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=10686
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

#ifndef THETOURNAMENTDIVTWO_H_
#define THETOURNAMENTDIVTWO_H_

//Locally Tested
class TheTournamentDivTwo {
public:
	int find(vector<int> points){
		int totalGames = 0;
		int oneCount = 0;
		for(unsigned int counter = 0;counter < points.size();counter++){
			totalGames += (points[counter]/2);
			oneCount += (points[counter]%2);
		}
		return oneCount%2 == 1?-1:(totalGames + (oneCount/2));
	}
};

#endif /* THETOURNAMENTDIVTWO_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/