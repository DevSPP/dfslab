#include <stdio.h>
#include <sys/time.h>

#define GAP(start, end) ((end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec) * 1000000)

int main()
{
    long int dp[20];
    long int n, N, e, E, EcN;
    float p_value;
    float sum = 0;
    fscanf(stdin, "%ld%ld%ld%ld", &n, &N, &e, &E);
    struct timeval start_time, end_time;

    gettimeofday(&start_time, NULL);

    dp[0] = 1;

    for (long int i = 1; i <= E; i++)
    {
        dp[i] = dp[i - 1] * i;
    }
    EcN = dp[E] / (dp[E - N] * dp[N]);

    long int var1 = E - e - N + 1;
    long int var2 = E - e;
    for (int i = n; i <= N; i++)
    {
        if (e >= i && var1 + i >= 0)
            sum = sum + (float)((dp[e] / (dp[e - i] * dp[i])) * (dp[var2] / (dp[N - i] * dp[var1 + i])) / EcN);
    }
    //p_value = sum;
    gettimeofday(&end_time, NULL);
    printf("p-value = %f (%d microseconds)", sum, (int)GAP(start_time, end_time));
}
