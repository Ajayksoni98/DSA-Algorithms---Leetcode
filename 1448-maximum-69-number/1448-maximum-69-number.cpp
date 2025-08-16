class Solution {
public:
    int reverse(int num)
    {
        int total = 0;
        while(num!=0)
        {
            total = total * 10 + num %10;
            num /=10;

        }
        return total;
    }
    int maximum69Number (int num) {

        int total = 0;

        num = reverse(num);
       // cout<<num;
        bool flag = true;
        while(num!=0)
        {
            if(num % 10 == 6 && flag == true)
            {
                flag = false;
                total = total * 10 + 9;
            }
            else
            total = total*10 + num % 10;

            num /= 10;

        }
      //  cout<<total;

        return (total);
        
    }
};