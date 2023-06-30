// A C++ program to find maximal
// Bipartite matching.
#include <iostream>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;

// M is number of applicants
// and N is number of jobs
#define M 10001
#define N 10001
int n, m;
// A DFS based recursive function
// that returns true if a matching
// for vertex u is possible
vector<int> adj[N];
bool bpm( int u,
		bool seen[], int matchR[])
{
	// Try every job one by one
	// for (int v = 0; v < N; v++)
    for(int v: adj[u])
	{
		// If applicant u is interested in
		// job v and v is not visited
		if (!seen[v])
		{
			// Mark v as visited
			seen[v] = true;

			// If job 'v' is not assigned to an
			// applicant OR previously assigned
			// applicant for job v (which is matchR[v])
			// has an alternate job available.
			// Since v is marked as visited in
			// the above line, matchR[v] in the following
			// recursive call will not get job 'v' again
			if (matchR[v] < 0 || bpm( matchR[v], 
									seen, matchR))
			{
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

// Returns maximum number
// of matching from M to N
int maxBPM() //bool bpGraph[M][N]
{
	// An array to keep track of the
	// applicants assigned to jobs.
	// The value of matchR[i] is the
	// applicant number assigned to job i,
	// the value -1 indicates nobody is
	// assigned.
	int matchR[n+1];

	// Initially all jobs are available
	memset(matchR, -1, sizeof(matchR));

	// Count of jobs assigned to applicants
	int result = 0;
	for (int u = 1; u <= m; u++)
	{
		// Mark all jobs as not seen
		// for next applicant.
		bool seen[n+1];
		memset(seen, 0, sizeof(seen));

		// Find if the applicant 'u' can get a job
		if (bpm(u, seen, matchR))
			result++;
	}
	return result;
}
void input(){
    cin>>n>>m;
    int k, h;
    for(int i=1; i<=n; i++){
        cin>>k;
        for(int j=1; j<=k; j++){
            cin>>h;
            adj[h].push_back(i);
        }
    }
}
// Driver Code
int main()
{
	// Let us create a bpGraph
	// shown in the above example
	
    input();
	cout << maxBPM();

	return 0;
}
