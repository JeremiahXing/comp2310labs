int main() {
    // Definitions of some variables for use in our tests
    // NOTE: The important thing is the type, not the
    // value.

    char c = 0;   // signed 1 byte integer
    short s = 0;  // signed 2 bytes integer
    int i = 0;    // signed 4 bytes integer
    long l = 0;   // signed 8 bytes integer

    unsigned char uc = 0;   // unsigned 1 byte integer
    unsigned short us = 0;  // unsigned 2 bytes integer
    unsigned int ui = 0;    // unsigned 4 bytes integer
    unsigned long ul = 0;   // unsigned 8 bytes integer

    float f = 0.0f;  // single precision floating point (~24 bits of significant value)
    double d = 0.0;  // double precision floating point (~53 bits of significant value)


    // Make predictions about the following statements

    char c1 = c + s;
    int c2  = c + s;
    long c3 = c + s;
    unsigned long c4 = c + s;

    int i1 = i + f;
    long l1 = f;

    float f1 = f + i;
    double d1 = f + i;
    double d2 = d + i;

    // Add your own statements here




    return 0;
}
