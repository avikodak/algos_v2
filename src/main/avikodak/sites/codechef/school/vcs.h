/****************************************************************************************************************************************************
 *  File Name                   : vcs.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/school/vcs.h
 *  Created on                  : 09-Sep-2015 :: 9:47:43 pm
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/VCS
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

#ifndef VCS_H_
#define VCS_H_

//Tested
void getVCSResult(vector<unsigned int> ignoredFiles,vector<unsigned int> trackedFiles,unsigned int size){
	unsigned int trackedCount = 0,untrackedCount = 0;
	map<unsigned int,unsigned int> frequencyMap;
	for(unsigned int counter = 0;counter < ignoredFiles.size();counter++){
		frequencyMap[ignoredFiles[counter]] = 1;
	}
	for(unsigned int counter = 0;counter < trackedFiles.size();counter++){
		if(frequencyMap.find(trackedFiles[counter]) == frequencyMap.end()){
			frequencyMap[trackedFiles[counter]] = 1;
		}else{
			frequencyMap[trackedFiles[counter]]++;
		}
	}
	for(unsigned int counter = 1;counter <= size;counter++){
		if(frequencyMap.find(counter) == frequencyMap.end()){
			untrackedCount++;
		}else if(frequencyMap[counter] == 2){
			trackedCount++;
		}
	}
	cout << trackedCount << " " << untrackedCount << endl;
}

//Tested
void printResults(){
	unsigned int testCases,size,ignoredFileSize,trackedFileSize,input;
	scanf("%u",&testCases);
	vector<unsigned int> ignoredFiles,trackedFiles;
	while(testCases--){
		scanf("%u %u %u",&size,&ignoredFileSize,&trackedFileSize);
		ignoredFiles.clear();
		trackedFiles.clear();
		for(unsigned int counter = 0;counter < ignoredFileSize;counter++){
			scanf("%u",&input);
			ignoredFiles.push_back(input);
		}
		for(unsigned int counter = 0;counter < trackedFileSize;counter++){
			scanf("%u",&input);
			trackedFiles.push_back(input);
		}
		getVCSResult(ignoredFiles,trackedFiles,size);
	}
}

#endif /* VCS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
