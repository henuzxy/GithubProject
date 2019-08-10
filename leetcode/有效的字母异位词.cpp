#define ADD_NUM (128)
class Solution {
public:
    Solution(){
        memset(book,0,sizeof(book));
    }
    bool check(char ch){
        if(0 <= ch && ch <= 127)
            return true;
        else
            return false;
    }
    bool isAnagram(string s, string t) {
        int Size = 0;
        for(int i=0;i<s.length();++i){
            pair<int,int> p(0,0);
            if(check(s[i])){
                p.first = s[i];
            }
            else{
                p = make_pair(s[i],s[i+1]);
                i++;
            }
            book[p.first+ADD_NUM][p.second+ADD_NUM]++;
            Size++;
        }
        for(int i=0;i<t.length();++i){
            pair<int,int> p(0,0);
            if(check(t[i])){
                p.first = t[i];
            }
            else{
                p = make_pair(t[i],t[i+1]);
                i++;
            }
            int x = p.first+ADD_NUM;
            int y = p.second + ADD_NUM;
            book[x][y]--;
            Size--;
            if(book[x][y] < 0)
                return false;
            
        }
        return (Size == 0);
    }
private:
    int book[300][300];
};