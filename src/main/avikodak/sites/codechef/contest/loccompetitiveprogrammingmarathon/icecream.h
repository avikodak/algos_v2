/****************************************************************************************************************************************************
 *  File Name                   : icecream.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/codechef/contest/loccompetitiveprogrammingmarathon/icecream.h
 *  Created on                  : Feb 28, 2016 :: 10:34:52 AM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/LOCFEB16/problems/ICECREAM
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_LOCCOMPETITIVEPROGRAMMINGMARATHON_ICECREAM_H_
#define MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_LOCCOMPETITIVEPROGRAMMINGMARATHON_ICECREAM_H_

//Tested
void solveProblem(){
	unsigned int testCases;
	double 	r1,h1,r2,h2;
	const double PI = 3.141592653589793;
	scanf("%u",&testCases);
	while(testCases--){
		cin >> r1 >> h1 >> r2 >> h2;
		double volumeCone = ((PI * r1 * r1 * h1)/3) + ((2 * PI * r1 * r1 * r1)/3);
		double volumeCylinder = PI * r2 * r2 * h2;
		cout << std::fixed;
		cout << std::setprecision(9) << volumeCone <<  " " << volumeCylinder << endl;
	}
}


#endif /* MAIN_AVIKODAK_SITES_CODECHEF_CONTEST_LOCCOMPETITIVEPROGRAMMINGMARATHON_ICECREAM_H_ */
