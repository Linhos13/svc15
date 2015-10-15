// GPLv2


typedef unsigned int size_t;
typedef unsigned long uintptr_t;
/*copetition*/
typedef unsigned long long loff_t;
typedef unsigned long int pthread_t;
typedef unsigned long sector_t;

void klee_make_symbolic(void *addr, size_t nbytes, const char *name);
void klee_assume(uintptr_t condition);

extern void __VERIFIER_error(void);

extern void __assert_fail (__const char *__assertion, __const char *__file,
			   unsigned int __line, __const char *__function);

void __VERIFIER_error(void)
{
	/* FILE and LINE will be wrong, but that doesn't matter, klee will
	   replace this call by its own handler anyway */
	__assert_fail("verifier assertion failed", __FILE__, __LINE__, __func__);
}

void __VERIFIER_assert(int expr) __attribute__((weak));
void __VERIFIER_assert(int expr)
{
	if (!expr)
		__assert_fail("verifier assertion failed", __FILE__, __LINE__, __func__);
}

void __VERIFIER_assume(int expr)
{
	klee_assume(expr);
}

#define MAKE_NONDET(type)				\
type __VERIFIER_nondet_ ## type(void)			\
{							\
	type x;						\
	klee_make_symbolic(&x, sizeof(x), # type);	\
	return x;					\
}

MAKE_NONDET(char);
MAKE_NONDET(short);
MAKE_NONDET(int);
MAKE_NONDET(long);
MAKE_NONDET(float);
MAKE_NONDET(double);
MAKE_NONDET(_Bool);

_Bool __VERIFIER_nondet_bool(void)
{
	return __VERIFIER_nondet__Bool();
}

#undef MAKE_NONDET

#define MAKE_NONDET(type)				\
type nondet_ ## type(void)				\
{							\
	return __VERIFIER_nondet_ ## type();		\
}

MAKE_NONDET(char);
MAKE_NONDET(short);
MAKE_NONDET(int);
MAKE_NONDET(long);

#undef MAKE_NONDET

#define MAKE_NONDET(type)				\
type __VERIFIER_nondet_u ## type(void)			\
{							\
	return __VERIFIER_nondet_ ## type();		\
}

MAKE_NONDET(char);
MAKE_NONDET(short);
MAKE_NONDET(int);
MAKE_NONDET(long);

#undef MAKE_NONDET

void *__VERIFIER_nondet_pointer()
{
	void *x;						\
	klee_make_symbolic(&x, sizeof(void *), "void*");	\
	return x;					\
}

/* these are crippled */

unsigned int __VERIFIER_nondet_u32()
{
	return __VERIFIER_nondet_uint();
}

unsigned int __VERIFIER_nondet_U32()
{
	return __VERIFIER_nondet_uint();
}

unsigned int __VERIFIER_nondet_u8()
{
	return __VERIFIER_nondet_uchar();
}

/* these type are not sane, but benchmarks use them */
unsigned int __VERIFIER_nondet_U8()
{
	return __VERIFIER_nondet_uchar();
}

unsigned int __VERIFIER_nondet_u16()
{
	return __VERIFIER_nondet_ushort();
}

unsigned int __VERIFIER_nondet_U16()
{
	return __VERIFIER_nondet_ushort();
}

unsigned int __VERIFIER_nondet_unsigned()
{
	return __VERIFIER_nondet_uint();
}

char *__VERIFIER_nondet_pchar()
{
	return __VERIFIER_nondet_pointer();
}

void *kzalloc(int size, int gfp)
{
	extern void *malloc(size_t size);
	return malloc(size);
}

/* competition */

size_t __VERIFIER_nondet_size_t()
{
    return __VERIFIER_nondet_uint();
} 

/* unsigned long long - 64bit */
loff_t  __VERIFIER_nondet_loff_t()
{
    //TODO
}

/* unsigned long */
pthread_t __VERIFIER_nondet_pthread_t()
{
    __VERIFIER_nondet_ulong();
}

/* unsigned long */
sector_t __VERIFIER_nondet_sector_t()
{
    __VERIFIER_nondet_ulong();
}

/* atomic execution */
void __VERIFIER_atomic_begin()
{
    //TODO
}

void __VERIFIER_atomic_end()
{
    //TODO
}


