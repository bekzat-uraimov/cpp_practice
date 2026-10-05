// Pointer tracing practice: StepByStepCode C++ exercises 1-4.
// Answers are written as comments BEFORE each cout. Predict first, then run.
//
// Note: when printing addresses (c, &a, s4, ...) the real program prints
// actual memory addresses, not the made-up ones from the problem
// (0xaa00, 0x555500, ...). Compare the values, and the address you'd expect.

#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------------------------------------
// Problem 1: v1v2p1p2
// ---------------------------------------------------------------------------
void v1v2p1p2() {
    int v1 = 10;
    int v2 = 25;
    int* p1 = &v1;
    int* p2 = &v2;

    *p1 += *p2;          // v1 = 10 + 25 = 35
    p2 = p1;             // p2 now points at v1 too
    *p2 = *p1 + *p2;     // v1 = 35 + 35 = 70

    // ANSWER line 1: 70 25
    cout << v1 << " " << v2 << endl;
    // ANSWER line 2: 70 70
    cout << *p1 << " " << *p2 << endl;
}

// ---------------------------------------------------------------------------
// Problem 2: parameterMystery1
// Addresses: a=0xaa00, b=0xbb00, c=0xcc00, d=0xdd00
// ---------------------------------------------------------------------------
int parameterMystery1(int a, int& b, int* c) {
    b++;
    a += *c;
    // ANSWER call 1: 9 -3 1 0xcc00
    // ANSWER call 2: -7 9 6 0xbb00
    // ANSWER call 3: 5 -7 2 0xdd00
    cout << b << " " << *c << " " << a << " " << c << endl;
    c = &a;
    return a - b;
}

void runParameterMystery1() {
    int a = 4;
    int b = 8;
    int c = -3;
    int d;

    d = parameterMystery1(a, b, &c);   // b -> 9, returns 1 - 9 = -8, d = -8
    parameterMystery1(c, d, &b);       // d -> -7
    parameterMystery1(b, a, &d);       // a -> 5
    // ANSWER line 4: 5 9 -3 -7
    cout << a << " " << b << " " << c << " " << d << endl;
}

// ---------------------------------------------------------------------------
// Problem 3: parameterMystery1X
// Addresses: a=0xaa00, b=0xbb00, c=0xcc00, d=0xdd00, e=0xee00, heap=0x555500
// ---------------------------------------------------------------------------
int parameterMystery1X(int a, int& b, int* c) {
    b++;
    a += *c;
    // ANSWER call 1: 9 -3 1 0xcc00
    // ANSWER call 2: -7 9 6 0x555500
    // ANSWER call 3: 5 -7 2 0xdd00
    cout << b << " " << *c << " " << a << " " << c << endl;
    c = &a;
    return a - b;
}

void runParameterMystery1X() {
    int a = 4;
    int* b = new int(8);   // b holds 0x555500, *b = 8
    int c = -3;
    int d;
    int* e = &a;           // e holds 0xaa00

    d = parameterMystery1X(a, *b, &c);   // *b -> 9, d = 1 - 9 = -8
    parameterMystery1X(c, d, b);         // d -> -7
    parameterMystery1X(*b, *e, &d);      // *e is a, so a -> 5

    // ANSWER line 4: 5 0x555500 9 -3 -7 0xaa00 5
    cout << a << " " << b << " " << *b << " " << c << " " << d << " " << e << " " << *e << endl;
    // ANSWER line 5: 0xaa00 0xbb00 0xcc00 0xdd00 0xee00
    cout << &a << " " << &b << " " << &c << " " << &d << " " << &e << endl;

    delete b;
}

// ---------------------------------------------------------------------------
// Problem 4: parameterMystery2X
// Addresses: s1=0x1100, s2=0x2200, s3=0x3300, s4=0x4400, s5=0x5500, heap=0x777700
// ---------------------------------------------------------------------------
string* parameterMystery2X(string& s1, string s2) {
    s1 += "1";
    s2 += "2";
    // ANSWER call 1: yo2 -- hi1
    // ANSWER call 2: bye2 -- yo1
    // ANSWER call 3: yo1!!!2 -- bye1
    cout << s2 << " -- " << s1 << endl;
    s1 += "!!!";
    return &s1;
}

void runParameterMystery2X() {
    string s1 = "hi";
    string s2 = "bye";
    string s3 = "yo";
    string* s4 = new string(s3);   // heap string "yo" at 0x777700
    string* s5 = nullptr;

    parameterMystery2X(s1, s3);          // s1 -> "hi1!!!", s3 unchanged (copy)
    s5 = parameterMystery2X(*s4, s2);    // heap -> "yo1!!!", s5 = s4 = 0x777700
    parameterMystery2X(s2, *s5);         // s2 -> "bye1!!!"

    // ANSWER line 4: hi1!!! bye1!!! yo
    cout << s1 << " " << s2 << " " << s3 << endl;
    // ANSWER line 5: 0x777700 yo1!!! 0x777700 yo1!!!
    cout << s4 << " " << *s4 << " " << s5 << " " << *s5 << endl;

    delete s4;
}

int main() {
    cout << "--- Problem 1: v1v2p1p2 ---" << endl;
    v1v2p1p2();

    cout << "\n--- Problem 2: parameterMystery1 ---" << endl;
    runParameterMystery1();

    cout << "\n--- Problem 3: parameterMystery1X ---" << endl;
    runParameterMystery1X();

    cout << "\n--- Problem 4: parameterMystery2X ---" << endl;
    runParameterMystery2X();

    return 0;
}
