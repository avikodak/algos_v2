/****************************************************************************************************************************************************
 *  File Name                   : igcdlift.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/contest/ignitedcoders/igcdlift.h
 *  Created on                  : 20-Sep-2015 :: 11:12:01 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/IGCD2015/problems/IGCDLIFT
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
#include <stdint.h>
#include <iomanip>
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

#ifndef IGCDLIFT_H_
#define IGCDLIFT_H_

//Tested
void printResults(){
	long long int testCases,totalFloors,personFloor,liftFloor,destinationFloor,liftSpeed,personSpeed;
	long long int liftTime,personTime;
	scanf("%lld",&testCases);
	while(testCases--){
		scanf("%lld %lld %lld %lld %lld %lld",&totalFloors,&personFloor,&liftFloor,&destinationFloor,&liftSpeed,&personSpeed);
		liftTime = (abs(liftFloor-personFloor) + abs(destinationFloor-personFloor))*liftSpeed;
		personTime = abs(personFloor-destinationFloor)*personSpeed;
		if(liftTime <= personTime){
			cout << "LIFT" << endl;
		}else{
			cout << "STAIRS" << endl;
		}
	}
}

#endif /* IGCDLIFT_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
