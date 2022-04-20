class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        // domain -> number of visits
        unordered_map<string, int> visits;
        
        for (string &cpdomain : cpdomains) {
            // extract count
            int count = 0;
            
            int i = 0;
            while (cpdomain[i] != ' ') {
                count = count * 10 + (cpdomain[i] - '0');
                i++;
            }
            
            // extract domains
            int n = cpdomain.size();
            for (int j=n-1; j>i; j--) {
                if (cpdomain[j] == '.')
                    visits[cpdomain.substr(j + 1)] += count;
            }
            visits[cpdomain.substr(i + 1)] += count;
        }
        
        vector<string> ans;
        for (auto &[domain, freq] : visits)
            ans.push_back(to_string(freq) + " " + domain);
        
        return ans;
    }
};

/*
we maintain a hashmap which maps each domain to its
number of visits.

for each count-paired domain:
    - extract count
    - extract each domain
    - add count to frequency of domain in hashmap

n = cpdomains.length
L = maximum length of domain

time complexity: O(nL)
space complexity: O(3n) = O(n)

https://leetcode.com/problems/subdomain-visit-count/
*/