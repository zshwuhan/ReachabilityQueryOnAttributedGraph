
#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <climits>
#include <time.h>
#include <stdlib.h>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <unistd.h>
#include <unordered_set>
#include <tuple>

#include "query.h"
#include "triple.h"

using namespace std;

class QueryHandler{

	class mycomparison{
	  	bool reverse;
		public:
			mycomparison(const bool& revparam=false)
	 		{reverse=revparam;}
	  	
	  		bool operator() (const triple& lhs, const triple&rhs) const{
			    if (reverse) 
			    	return (lhs.dist>rhs.dist);
		    	else 
		    		return (lhs.dist<rhs.dist);
	  	}
	};

	public:
		void PathRecovery(vector<int>&,unordered_set<int>&,int,int);
		void SuperGraphShortestPath(int,int,vector<vector<pair<int,int> > >&,vector<double>&,vector<double>&,unordered_set<int>&,int);
		bool SimpleBFS(query&,vector<vector<pair<int,int> > >&);
		bool DFS(int,vector<vector<pair<int,int> > >&,query&,vector<bool>&);
		pair<bool,int> CReachabilityQuery(vector<vector<pair<int,int> > >&,vector<unsigned long long>&,vector<unsigned long long>&,query&,const char*,int,int,bool,bool);
		bool BFS_C(int,vector<vector<pair<int,int> > >&,vector<unsigned long long>&,vector<unsigned long long>&,query&,queue<pair<int,int> >&,
					vector<bool>&,unordered_map<unsigned long long,bool>&,unordered_map<unsigned long long,bool>&,const char*,const char*,
					ifstream&,ifstream&,int,int,bool,bool);
		bool DFS_C(int,vector<vector<pair<int,int> > >&,vector<unsigned long long>&,vector<unsigned long long>&,query&,queue<pair<int,int> >&,
					vector<bool>&,unordered_map<unsigned long long,bool>&,unordered_map<unsigned long long,bool>&,const char*,const char*,
					/*ifstream&,ifstream&,*/int,int,bool);
		bool CheckConstraint(int,vector<unsigned long long>&,vector<vector<int> > &,unordered_map<unsigned long long,bool>&,const char*,ifstream&,int,bool);
		void split(const string&,char,vector<int>&,bool);
		void IOAttr(int,const char*,vector<int>&,ifstream&,int);
		bool CheckAttr(vector<int>&,vector<vector<int> >&);
};


