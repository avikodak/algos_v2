/****************************************************************************************************************************************************
 *  File Name                   : frgtnlng.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/contest/septembermegacook-off2015/frgtnlng.h
 *  Created on                  : 20-Sep-2015 :: 9:34:45 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/COOK62/problems/FRGTNLNG
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

#ifndef FRGTNLNG_H_
#define FRGTNLNG_H_

//Tested
void printResults(){
	unsigned int testCases,size,modernSize,noOfWords;
	string input;
	vector<string> oldLang;
	map<string,bool> modernLangMap;
	scanf("%u",&testCases);
	while(testCases--){
		scanf("%u %u",&size,&modernSize);
		oldLang.clear();
		modernLangMap.clear();
		for(unsigned int counter = 0;counter< size;counter++){
			cin >> input;
			oldLang.push_back(input);
		}
		for(unsigned int counter = 0;counter < modernSize;counter++){
			scanf("%u",&noOfWords);
			for(unsigned int wordCounter = 0;wordCounter < noOfWords;wordCounter++){
				cin >> input;
				modernLangMap.insert(pair<string,bool>(input,true));
			}
		}
		for(unsigned int counter = 0;counter < oldLang.size();counter++){
			if(modernLangMap.find(oldLang[counter]) != modernLangMap.end()){
				cout << "YES ";
			}else{
				cout << "NO ";
			}
		}
		cout << endl;
	}
}

#endif /* FRGTNLNG_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
