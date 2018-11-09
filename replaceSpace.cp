class Solution {
public:
    void replaceSpace(char *str,int length) {
        if (str == nullptr && length <= 0)  return;
        int i = 0, cnt = 0;
        for (; str[i] != '\0'; ++i) {
            if (str[i] == ' ') ++cnt;
        }
        // i 旧长度
        int j = i + 2 * cnt; // 新长度
        if (j > length) return;
        while(j >= 0 && i >= 0) {
                str[j--] = str[i];
            }
            else {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
            -- i;
        }
    }
};
