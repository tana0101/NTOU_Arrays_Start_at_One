/*精準度(Epsilon)*/
float eps = 1e-8;
bool Equal(float a, float b)
    return fabs(a - b) < eps
bool NEqual(float a, float b)
    return fabs(a - b) > eps
bool Less(float a, float b)
    return (a - b) < -eps
bool Greater(float a, float b)
    return (a - b) > eps