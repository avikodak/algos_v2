/****************************************************************************************************************************************************
 *  File Name                   : campers.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\competitions\countercode2015\campers.h
 *  Created on                  : Aug 2, 2015 :: 12:16:03 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.hackerrank.com/contests/countercode/challenges/campers
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

#ifndef CAMPERS_H_
#define CAMPERS_H_

void getMaxNumberPlayers(){
	unsigned int totalPlayers,snipersCount,sniperIndex;
	cin >> totalPlayers >> snipersCount;
	vector<int> flags[totalPlayers] = {0};
	while(snipersCount--){
		cin >> sniperIndex;
		sniperIndex -= 1;
		flags[sniperIndex] = 1;
		if(sniperIndex-1 >= 0){
			flags[sniperIndex] = -1;
		}
		if(sniperIndex+1 < totalPlayers){
			flags[sniperIndex] = -1;
		}
	}
	bool neighboursChosen;
	unsigned int maxPlayerCount = 0;
	for(unsigned int counter = 0;counter < totalPlayers;counter++){
		if(flags[counter] == 1){
			maxPlayerCount++;
			continue;
		}
		if(counter-1 >= 0){
			if(flags[counter-1] != 1){
				continue;
			}
		}
		if(counter+1 < totalPlayers){
			if(flags[counter+1] !=0){
				continue;
			}
		}
		flags[counter] = 1;
		maxPlayerCount++;
		if(counter-1 >= 0){
			flags[counter-1] = -1;
		}
		if(counter+1 < totalPlayers){
			flags[counter+1] = -1;
		}
	}
	cout << maxPlayerCount << endl;
}

#endif /* CAMPERS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
