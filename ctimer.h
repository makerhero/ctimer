/*! \file ctimer.h */
#pragma once
/**
    Esta biblioteca e gratuita.
    Use e distribua, mantendo as informacoes de autoria:
    Luiz Cressoni Filho - 2019
    luiz@cressoni.com.br

    Biblioteca cTimer - Implementa temporizador
*/


#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif


class cTimer
{
private:
    uint32_t    m_u32step;
    uint32_t    m_u32TimeOut;
    uint32_t    m_u32timeNow;
    bool        mEnabled;
public:
    cTimer(bool _enabled = true);
    ~cTimer(void);
    void        SetTimeOut(uint32_t _u32mSeg);
    bool        IsTimeOut(bool _reset = false);
    uint32_t    ReadTimeOut(void);
    void        Enable(bool _enable);
    bool        IsEnabled(void);
};
