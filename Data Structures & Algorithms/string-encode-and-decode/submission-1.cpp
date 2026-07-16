class Solution {
   public:
    string encode(vector<string>& strs) {
        int xtraSize = 0;
        string xtra = "";

        for (int i = 0; i < strs.size(); i++) {
            xtra += to_string(strs[i].size()) + ",";
        }

        string encoded = to_string(xtra.size()) + "," + xtra;

        for (auto str : strs) {
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        string sos = "";

        int i = 0;
        while( i < s.size() ){
            if ( s[i] == ',' ) break;
            sos += s[i];
            i++;
        }

        int sox = stoi(sos);
        i++; // hit , 
        int index = sox + i;
        int limit = index;

        vector<string>ans;
        while( i < limit ) {
            string tmp;
            // scrape number then start scraping real message
            while( s[i] != ',' ) tmp += s[i++];
            // hit ','
            i++;

            int numsize = stoi(tmp);
            string tmps ;
            for ( int i = 0 ; i < numsize ; i++ ) tmps += s[index++];
        
            ans.push_back(tmps);    
        }

        return ans;
    }
};
