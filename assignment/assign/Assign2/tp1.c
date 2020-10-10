// A Naive Recursive Implementation
#include <stdio.h>
#include <sys/time.h>

#define GAP(start, end) ((end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec) * 1000000)

long int dp[50][50] = {0};

int min(int a, int b)
{
    return (a < b) ? a : b;
}

long int binomialCoeff(int n, int k) // Returns value of Binomial Coefficient C(n, k)
{
    if (dp[n][k])
        return dp[n][k];
    if ((n - k) >= 0 && dp[n][n - k])
        return dp[n][n - k];
    // Base Cases
    if (k == 0 || k == n)
    {
        dp[n][k] = 1;
        return 1;
    }
    dp[n][k] = binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
    // Recur
    return dp[n][k];
}

/* Driver program to test above function*/
int main()
{
    long int k, n, N, m, Ncn;
    float p_value;
    long int sum = 0;
    fscanf(stdin, "%ld%ld%ld%ld", &k, &n, &m, &N);
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    Ncn = binomialCoeff(N, n); //12C7
    if (n - k + 1 < k)
    {
        for (int i = k; i <= n; i++)
        {
            if (i <= m)
                if (n - i <= N - m) //condition to stop the loop
                {
                    if (dp[m][i] && dp[N - m][n - i])
                        sum = sum + dp[m][i] * dp[N - m][n - i];
                    else if (dp[m][i] && !dp[N - m][n - i])
                        sum = sum + dp[m][i] * binomialCoeff(N - m, n - i);
                    else if (!dp[m][i] && dp[N - m][n - i])
                        sum = sum + binomialCoeff(m, i) * dp[N - m][n - i];
                    else
                        sum = sum + binomialCoeff(m, i) * binomialCoeff(N - m, n - i);
                }
                else
                    continue;
            else
            {
                break;
            }
        }
        p_value = (float)sum / Ncn;
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            if (i <= m)
                if (n - i <= N - m)
                {
                    if (dp[m][i] && dp[N - m][n - i])
                        sum = sum + dp[m][i] * dp[N - m][n - i];
                    else if (dp[m][i] && !dp[N - m][n - i])
                        sum = sum + dp[m][i] * binomialCoeff(N - m, n - i);
                    else if (!dp[m][i] && dp[N - m][n - i])
                        sum = sum + binomialCoeff(m, i) * dp[N - m][n - i];
                    else
                        sum = sum + binomialCoeff(m, i) * binomialCoeff(N - m, n - i);
                }
                else
                    continue;
            else
            {
                break;
            }
        }
        p_value = 1.0 - ((float)sum / Ncn);
    }

    gettimeofday(&end_time, NULL);
    printf("p-value = %f (%d microseconds)", p_value, (int)GAP(start_time, end_time));
    return 0;
}
