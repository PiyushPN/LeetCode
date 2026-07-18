// Last updated: 18/07/2026, 20:04:09


int maxSubArray(int* nums, int numsSize)
{
    int CurrentMax = INT_MIN, Max = 0;
    for(int i = 0; i < numsSize; i++)
    {
        Max = Max + nums[i];
        if(CurrentMax < Max)
        {
            CurrentMax = Max;
        }
        if(Max < 0)
        {
            Max = 0;
        }
    }
    return CurrentMax;
}