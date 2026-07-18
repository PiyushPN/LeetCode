// Last updated: 18/07/2026, 19:58:23
class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.length();
        vector<int> pre(n);
        vector<int> suff(n);
        pre[0] = 0;
        int count = 0;
        for(int i = 1; i < n; i++)
        {
            if(boxes[i-1] == '1')
            {
                count++;
                pre[i] = pre[i-1] + count;
            }
            else
            {
                pre[i] = pre[i-1] + count;;
            }
        }
        suff[n-1] = 0;
        count = 0;
        for(int i = n-2; i >= 0; i--)
        {
            if(boxes[i+1] == '1')
            {
                count++;
                suff[i] = suff[i+1] + count;
            }
            else
            {
                suff[i] = suff[i+1] + count;
            }
        }
        for(int i = 0; i < n; i++)
        {
            pre[i] = pre[i] + suff[i];
        }
        return pre;
        
    }
};