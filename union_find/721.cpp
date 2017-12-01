/**
 * Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
 */

class Solution {
    int find(int P[],int p){
        while(p!=P[p]){
            P[p] = P[P[p]];
            p = P[p];
        }
        return p;
    }    
    void Union(int P[],int p, int q){
        p = find(P,p);
        q = find(P,q);
        if(p!=q)
            P[p] = q;
    }    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        int P[n];
        for(int i=0;i<n;i++)
            P[i] = i;        
        unordered_map<string,int> mp;
        for(int i = 0;i<accounts.size();i++){
            auto& v = accounts[i];
            vector<int> merge;
            for(int j=1;j<v.size();j++){
                if(!mp.count(v[j]))
                    mp[v[j]] = i;
                else 
                    merge.push_back(mp[v[j]]);
            }    
            for(auto k:merge)
                    Union(P,i,k);
        }           
        vector<vector<string>> r;
        unordered_map<int,int> name;       
        for(int i = 0;i<accounts.size();i++){
            auto& v = accounts[i];
            if(v.size()==1){
                continue;   
            }
            int p = find(P,i);
            if(!name.count(p)){
                name[p] = r.size();
                r.push_back({v[0]});
            }
            for(int j=1;j<v.size();j++){                
                if(mp[v[j]]==i){
                    r[name[p]].push_back(v[j]);   
                    mp[v[j]] = -1;
                }
            }            
        }         
        for(int i=0;i<r.size();i++)
            sort(r[i].begin()+1,r[i].end());
        return r;
    }
};