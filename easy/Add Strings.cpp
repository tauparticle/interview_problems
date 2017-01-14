/*415. Add Strings   Add to List QuestionEditorial Solution  My Submissions
 Total Accepted: 18909
 Total Submissions: 45805
 Difficulty: Easy
 Contributors: Admin
 Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
 
 Note:
 
 The length of both num1 and num2 is < 5100.
 Both num1 and num2 contains only digits 0-9.
 Both num1 and num2 does not contain any leading zero.
 You must not use any built-in BigInteger library or convert the inputs to integer directly.
 Hide Company Tags Google Airbnb
 Hide Tags Math
 Hide Similar Problems (M) Add Two Numbers (M) Multiply Strings

 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        ostringstream out;
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        addStringHelper(num1, 0, num2, 0, 0, out);
        string res = out.str();
        reverse(res.begin(), res.end());
        return res;
    }
    
    void addStringHelper(string& n1, int i1, string& n2, int i2, int carry, ostringstream& out)
    {
        if (i1 == n1.size() && i2 == n2.size() && carry == 0)
        {
            return;
        }
        
        int val = carry;
        if (i1 < n1.size())
        {
            
            val += (n1[i1] - '0');
            i1++;
        }
        if (i2 < n2.size())
        {
            
            val += (n2[i2] - '0');
            i2++;
        }
        
        out << val % 10;
        carry = val / 10;
        
        addStringHelper(n1, i1, n2, i2, carry, out);
        
    }
};


class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while(i>=0 || j>=0 || carry){
            long sum = 0;
            if(i >= 0){sum += (num1[i] - '0');i--;}
            if(j >= 0){sum += (num2[j] - '0');j--;}
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            res =  res + to_string(sum);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
