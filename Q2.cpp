#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);
/*
 * Complete the 'mostBalancedPartition' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY parent
 *  2. INTEGER_ARRAY files_size
 */


// ex:
 /*
        0(10)
       /    \
    1(5)     2(6)
    / 
  3(4)
 
since node 2 is a leaf node so its subtree is 6 .. subtree[2] = 6
// node 1 -> ( 5+4 ) : subtree[1] = 9
node 0 (root) -> 25       //

 */
    int mostBalancedPartition(vector<int> parent, vector<int> files_size)
    {
    int n = parent.size();  // num of nodes
    
    // Build adjacency list 
    vector<vector<int>> children(n); // (children of each node)
    for (int i = 1; i < n; i++)
    {
        children[parent[i]].push_back(i); // if parent[i] = 0 that means 0 is i's son.
        // push i to the list
    }
    
    vector<long long> subtree(n, 0); // store the sum of each sub stree
    
    for (int i = 0; i < n; i++) subtree[i] = files_size[i]; // value of eachh node
    
    for (int i = n - 1; i >= 1; i--)
    {
        /* we start at the end cuz the parent always larger then the child */
        subtree[parent[i]] += subtree[i];
    }

    long long total = subtree[0];
    long long best = LLONG_MAX; // 9223372036854775807
    
    // Try cutting each edge (i -> parent[i]) for i = 1..n-1
    for (int i = 1; i < n; i++)
    {
        long long diff = abs(total - 2 * subtree[i]);
        best = min(best, diff);
    }
    
    return (int)best;
}


/* - - - - - - - - - - - - - - - - - - - - - - - -  - -*/
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string parent_count_temp;
    getline(cin, parent_count_temp);
    int parent_count = stoi(ltrim(rtrim(parent_count_temp)));
    vector<int> parent(parent_count);
    for (int i = 0; i < parent_count; i++) {
        string parent_item_temp;
        getline(cin, parent_item_temp);
        int parent_item = stoi(ltrim(rtrim(parent_item_temp)));
        parent[i] = parent_item;
    }
    string files_size_count_temp;
    getline(cin, files_size_count_temp);
    int files_size_count = stoi(ltrim(rtrim(files_size_count_temp)));
    vector<int> files_size(files_size_count);
    for (int i = 0; i < files_size_count; i++) {
        string files_size_item_temp;
        getline(cin, files_size_item_temp);
        int files_size_item = stoi(ltrim(rtrim(files_size_item_temp)));
        files_size[i] = files_size_item;
    }
    int result = mostBalancedPartition(parent, files_size);
    fout << result << "\n";
    fout.close();
    return 0;
}
string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}
string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}