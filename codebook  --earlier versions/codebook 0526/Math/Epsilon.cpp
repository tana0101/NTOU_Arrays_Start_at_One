/*精準度(Epsilon)*/
void Equal(float a, float b)    //判斷相等
{
    float eps = 1e-8;
    if ((fabs(a - b)) < eps)
        printf("Yes\n");
    else printf("No\n");
}
void NEqual(float a, float b)   //判斷不相等
{
    float eps = 1e-8;
    if ((fabs(a - b)) > eps)
        printf("Yes\n");
    else printf("No\n");
}
void Less(float a, float b) //判斷小於
{
    float eps = 1e-8;
    if ((a - b) < -eps)
        printf("Yes\n");
    else printf("No\n");
}
void Greater(float a, float b)  //判斷大於
{
    float eps = 1e-8;
    if ((a - b) > eps)
        printf("Yes\n");
    else printf("No\n");
}