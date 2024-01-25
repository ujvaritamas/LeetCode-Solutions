namespace Palindrome{
    public class Solution {
        public bool IsPalindrome(int x) {
            System.Console.WriteLine("hello");

            String val = x.ToString();
            String tmp = "";

            for(int i= val.Length-1; i>=0; i--){
                tmp += val[i];
            }

            if(val.Equals(tmp)){
                return true;
            }
            else{
                return false;
            }
        }
    }
}