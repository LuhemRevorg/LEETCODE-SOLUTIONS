class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        while (num >= 1000) {
            ret += 'M';
            num -= 1000;
        }

        if (num >= 100) {
            if (num >= 900) {           // Fixed: Was num % 100 == 9
                ret += "CM";
                num -= 900;
            } else if (num >= 500) {
                ret += 'D';
                num -= 500;
                while(num >= 100) {
                    ret += 'C';
                    num -= 100;
                }
            } else if (num >= 400) {    // Fixed: Was num % 100 == 4
                ret += "CD";            // Fixed: "CD" instead of 'CD'
                num -= 400;
            } else {
                while(num >= 100) {
                    ret += 'C';
                    num -= 100;
                }
            }
        }

        if (num >= 10) {
            if (num >= 90) {            // Fixed: Was num % 10 == 9
                ret += "XC";
                num -= 90;
            } else if (num >= 50) {
                ret += 'L';
                num -= 50;
                while(num >= 10) {
                    ret += 'X';
                    num -= 10;
                }
            } else if (num >= 40) {     // Fixed: Was num % 10 == 4
                ret += "XL";
                num -= 40;
            } else {
                while(num >= 10) {
                    ret += 'X';
                    num -= 10;
                }
            }
        }

        if (num == 9) ret += "IX";
        else if (num >= 5) {
            ret += "V";
            num -= 5;
            while (num > 0) { ret += 'I'; num--; }
        }
        else if (num == 4) ret += "IV";
        else {
            while (num > 0) { ret += 'I'; num--; }
        }

        return ret;
    }
};
