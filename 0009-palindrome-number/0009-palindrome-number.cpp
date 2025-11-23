class Solution {
public:
    bool isPalindrome(int x) {
        long long int  temp = x;
        long long int  res=0;
        int count=0;
        int digit;
        if (x <0)
            return false;
        while (x>0){
            digit = x%10;
            res= digit+res*10;
            x=x/=10;
            count ++;
        }
        for( int i =0 ; i <count/2; i++){
            if(res%10 != temp%10 )
                return false;
            res= res/10;
            temp= temp/10;
        }
        return true;


    }
};