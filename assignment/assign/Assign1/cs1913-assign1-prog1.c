/*-----------------------------------
Name: SUBRAT PRASAD PANDA
Roll number: CS1913
Date: 10/08/2019
Program description: ASSIGNMENT 1, QUESTION NUMBER OF 1, Angle of clock hands
Acknowledgements: NIL 
------------------------------------*/

#include <stdio.h>

int main()
{
    int h, m, s; //h:hours m:minute s:second
    float t;
    //printf("Enter [HH:MM:SS T] >> ");
    scanf("%d:%d:%d %f", &h, &m, &s, &t);
    //checks on input
    if (h > 12 || h < 0 || (m > 59 || m < 0) || (s > 59 || s < 0))
    {
        printf("Enter proper value of HH (0-12): MM(0-59): SS(0-59)");
        return 0;
    }
    t = (t < 0) ? (-1 * (57.2958 * t)) : (57.2958 * t); // conversion to tolerance to degrees

    // Calculation of Angle of hands from Reference position
    //Reference position is at 12 o clock
    float ha, ma, sa;
    sa = 6 * (float)s;
    ma = ((float)m * 6) + ((float)s / 10);
    ha = (30 * (float)h) + ((float)m / 2) + ((float)s / 120);

    //
    float sm, sh, mh;
    sm = ((sa - ma) < 0) ? (-1 * (sa - ma)) : (sa - ma);
    mh = ((ma - ha) < 0) ? (-1 * (ma - ha)) : (ma - ha);
    sh = ((sa - ha) < 0) ? (-1 * (sa - ha)) : (sa - ha);
    sm = (sm > 180.0) ? (360.0 - sm) : sm;
    mh = (mh > 180.0) ? (360.0 - mh) : mh;
    sh = (sh > 180.0) ? (360.0 - sh) : sh;
    float diff1, diff2, diff3;
    diff1 = ((sm - sh) < 0) ? (-1 * (sm - sh)) : (sm - sh);
    diff2 = ((sm - mh) < 0) ? (-1 * (sm - mh)) : (sm - mh);
    diff3 = ((sh - mh) < 0) ? (-1 * (sh - mh)) : (sh - mh);

    if (diff1 <= t && diff2 <= t && diff3 <= t)
        printf("EQUIANGULAR");
    else if (diff1 <= t || diff2 <= t || diff3 <= t)
        printf("SEMI-EQUIANGULAR");
    else
        printf("NONE");

    //code ends
}