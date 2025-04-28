#define CHECK(a, b, c) CH_10(a)(b, c)
#define CH_10(condition) _CH_ ## condition
#define _CH_1(b, c) b
#define _CH_0(b, c) c