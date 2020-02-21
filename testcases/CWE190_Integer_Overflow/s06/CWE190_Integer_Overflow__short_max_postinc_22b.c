/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_max_postinc_22b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for short
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the sink function */
extern int CWE190_Integer_Overflow__short_max_postinc_22_badGlobal;

void CWE190_Integer_Overflow__short_max_postinc_22_badSink(short data)
{
    if(CWE190_Integer_Overflow__short_max_postinc_22_badGlobal)
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            short result = data;
            printIntLine(result);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE190_Integer_Overflow__short_max_postinc_22_goodB2G1Global;
extern int CWE190_Integer_Overflow__short_max_postinc_22_goodB2G2Global;
extern int CWE190_Integer_Overflow__short_max_postinc_22_goodG2BGlobal;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE190_Integer_Overflow__short_max_postinc_22_goodB2G1Sink(short data)
{
    if(CWE190_Integer_Overflow__short_max_postinc_22_goodB2G1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < SHRT_MAX)
        {
            data++;
            short result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE190_Integer_Overflow__short_max_postinc_22_goodB2G2Sink(short data)
{
    if(CWE190_Integer_Overflow__short_max_postinc_22_goodB2G2Global)
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < SHRT_MAX)
        {
            data++;
            short result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodG2B() - use goodsource and badsink */
void CWE190_Integer_Overflow__short_max_postinc_22_goodG2BSink(short data)
{
    if(CWE190_Integer_Overflow__short_max_postinc_22_goodG2BGlobal)
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            short result = data;
            printIntLine(result);
        }
    }
}

#endif /* OMITGOOD */