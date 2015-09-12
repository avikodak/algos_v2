/****************************************************************************************************************************************************
 *  File Name                   : mime2.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/easy/mime2.h
 *  Created on                  : 12-Sep-2015 :: 8:44:21 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/MIME2
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

#ifndef MIME2_H_
#define MIME2_H_

//Tested
vector<string> explode(string userInput,char delimiter = '.'){
	vector<string> result;
	std::stringstream  data(userInput);
	std::string line;
	while(std::getline(data,line,delimiter)){
		result.push_back(line);
	}
	data.clear();
	return result;
}

//Tested
void printResults(){
	unsigned int typesSize,testCases;
	cin >> typesSize >> testCases;
	string extension,name,input;
	map<string,string> extNameMap;
	map<string,string>::iterator itToExtNameMap;
	while(typesSize--){
		cin >> extension >> name;
		extNameMap[extension] = name;
	}
	while(testCases--){
		cin >> input;
		vector<string> tokens = explode(input);
		if(tokens.size() > 1){
			itToExtNameMap = extNameMap.find(tokens[tokens.size()-1]);
			if(itToExtNameMap != extNameMap.end()){
				cout << itToExtNameMap->second <<  endl;
			}else{
				cout << "unknown" << endl;
			}
		}else{
			cout << "unknown" << endl;
		}
	}
}

#endif /* MIME2_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
