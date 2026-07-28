class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        if(s.size()<=1) return s.size();
        set<char> m;
        int curr_max=0;
        while(l<=r && r<s.size()){
            cout<<"l "<<l<<" r "<<r<<endl;
            if(l==r){
                m = set<char> {s[l]};
                r++;
            }
            else if(m.find(s[r])!=m.end()){
                m.erase(s[l]);
                l++; 
            }
            else{

                m.insert(s[r]);
                r++;
            }
            curr_max = max(curr_max,static_cast<int>(m.size()));
            for(auto i:m){
                cout<<i<<endl;
            }
            cout<<endl;
        }
        return curr_max;
    }
};
