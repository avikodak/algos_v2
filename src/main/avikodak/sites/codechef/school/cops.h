/****************************************************************************************************************************************************
 *  File Name                   : cops.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/school/cops.h
 *  Created on                  : 01-Nov-2015 :: 11:54:46 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/COPS
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

#ifndef COPS_H_
#define COPS_H_

//Tested
void printResults(){
	int testCases,safeHouseCount;
	int size,speed,houses,input,housesCovered;
	scanf("%d",&testCases);
	while(testCases--){
		scanf("%d %d %d",&size,&speed,&houses);
		housesCovered = speed*houses;
		vector<int> copsHouses;
		for(int counter = 0;counter < size;counter++){
			scanf("%d",&input);
			copsHouses.push_back(input);
		}
		sort(copsHouses.begin(),copsHouses.end());
		int index = 1;
		safeHouseCount = 0;
		for(unsigned int counter = 0;counter < copsHouses.size();counter++){
			if(copsHouses[counter]-housesCovered > index){
				safeHouseCount += copsHouses[counter] - housesCovered -index;
			}
			index = copsHouses[counter] + housesCovered+1;
		}
		if(index <= 100){
			safeHouseCount += 100-index+1;
		}
		printf("%d\n",safeHouseCount);
	}
}

#endif /* COPS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
