//  ---------------------------------------------------------------------------
//
//  @file       AntPerfTimer.h
//  @brief      A performance (precision) timer for benchs
//  @author     Philippe Decaudin - http://www.antisphere.com
//  @license    This file is part of the AntTweakBar library.
//              For conditions of distribution and use, see License.txt
//
//  notes:      TAB=4
//              No cpp file is needed, everything is defined in this header
//
//  ---------------------------------------------------------------------------

#pragma once

    #include <sys/time.h>
    #include <unistd.h>

    struct PerfTimer
    {
        inline        PerfTimer()   { Reset(); }
        inline void   Reset()       { gettimeofday(&Start, &TZ); }
        inline double GetTime()     { gettimeofday(&End,&TZ); 
                                      double t1 = (double)Start.tv_sec + (double)Start.tv_usec/(1000*1000);
                                      double t2 = (double)End.tv_sec + (double)End.tv_usec/(1000*1000);
                                      return t2-t1; }
    protected:
        struct timeval Start, End;
        struct timezone TZ;
    };
