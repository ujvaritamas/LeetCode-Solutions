    #include <iostream>
    #include <vector>
    #include <climits>

    using namespace std;


    class Solution {
    public:
        int reverse(int x) {
            vector<int> digits = getDigits(x);
            printVector(digits);

            long long reversed = convertVectorToLongLong(digits);

            if(reversed > INT_MAX || reversed < INT_MIN){
                return 0;
            }
            return (int)reversed;
        }
    private:
        long long convertVectorToLongLong(vector<int> v1){
            long long ret = 0;
            for(auto i:v1){
                ret = ret*10 + i;
            }
            return ret;
        }

        vector<int> getDigits(int x){
            vector<int> digits;
            while(x!=0){
                digits.push_back(x%10);
                x/=10;
            }
            return digits;
        }

        void printVector(vector<int> v1){
            for(auto i:v1){
                cout <<i<<" ";
            }
            cout << endl;
        }
    };