#include <stdio.h>
#include <stdlib.h>
int power(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return (10 * power(x-1));
    }
}
int str_to_int(char *str)
{
    if (str[0] == '0')
    {
        return 0;
    }
    if (str[0] == '1')
    {
        return 1;
    }
    if (str[0] == '2')
    {
        return 2;
    }
    if (str[0] == '3')
    {
        return 3;
    }
    if (str[0] == '4')
    {
        return 4;
    }
    if (str[0] == '5')
    {
        return 5;
    }
    if (str[0] == '6')
    {
        return 6;
    }
    if (str[0] == '7')
    {
        return 7;
    }
    if (str[0] == '8')
    {
        return 8;
    }
    if (str[0] == '9')
    {
        return 9;
    }
}
double my_atof(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    int period;
    for (period = 0; period < length; period++)
    {
        if (str[period] == '.')
        {
            break;
        }
    }
    int first_power = length - 1 - period;
    //printf("%d\n", first_power);
    double output = 0;
    for (int i = 0; i < period; i++)
    {
        int x = str_to_int((char *)&str[i]);
        //printf("%d\n", x);
        output = output + x * power(first_power - i);
    }
    
    //now we have output till the decimal point
    for (int j = period+1; j < length; j++)    //-1 cuz of the period?
    {
        // the power is (-j-period)
        int exponent = j-period;
        int y = str_to_int((char *)&str[j]);
        //printf("%d%d\n", y, exponent);
        //printf("%d\n", power(exponent));
        double temp = 1.0/power(exponent);
        //printf("%.6f\n", temp);
        output = output + y * temp;
    }
    
    //first power after decimal place is -1
    //the length will be normal length like in python   (including the period)  (so the length is the max index of the string + 1)
    //period is the index of the period in the string
    //for 523.12 the first power is length-1-period
    return output;
}

int main()
{
    
 
    //for some reason doesn't work when theres more than 3 numbers before the decimal place
    double num = my_atof("31.753571");
    printf("%f", num);
    //printf("%d", power(3));
    
}
