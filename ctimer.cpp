/*! \file ctimer.cpp */
#include "ctimer.h"


/*! Construtor */
/*!
      \param _enabled :se o timer já inicia habilitado ou não
*/
cTimer::cTimer(bool _enabled)
{
    m_u32timeNow = 0;
    m_u32TimeOut = 0;
    m_u32step = 0;
    mEnabled = _enabled;
}

cTimer::~cTimer(void)
{
}


//! Define o tempo que o timer leva para gerar TimeOut (em ms)
/*!
      \param _u32mSeg :tempo desejado para timeout em ms.
*/
void cTimer::SetTimeOut(uint32_t _u32mSeg)
{
    mEnabled = true;
    m_u32step = _u32mSeg;
    m_u32timeNow = millis();
    m_u32TimeOut = m_u32timeNow + _u32mSeg;
}

//! Determina se o objeto atingiu o tempo limite definido em SetTimeOut
/*!
      \return true se ocorreu
*/
bool cTimer::IsTimeOut(bool _reset)
{
    bool ret;
    if (!mEnabled)
    {
        return false;
    }

    uint32_t m_u32Time = millis();

    if (m_u32TimeOut >= m_u32timeNow)
    {
        //condicao normal
        ret = (m_u32Time >= m_u32TimeOut) || (m_u32Time < m_u32timeNow);
    }
    else
    {
        //condicao roll-over
        ret = (m_u32Time >= m_u32TimeOut) && (m_u32Time < m_u32timeNow);
    }

    if(ret && _reset)
      SetTimeOut(m_u32step);
      
    return ret;
}

//! Determina quanto falta para TimeOut
/*!
      \return tempo restante para timeout em ms.
      \sa SetTimeOut(uint32_t _u32mSeg)
    */
uint32_t cTimer::ReadTimeOut(void)
{
    if (IsTimeOut())
    {
        return 0;
    }

    return m_u32TimeOut - millis();
}

//! Habilita ou desabilita o timer
/*!
      \param _enable :True para habilitar, false para desabilitar
      \warning SetTimeOut(uint32_t _u32mSeg) automaticamente habilita o timer
*/
void cTimer::Enable(bool _enable)
{
    mEnabled = _enable;
}

//! verifica se esta habilitado
/*!
      \return true se estiver habilitado
*/
bool cTimer::IsEnabled(void)
{
    return mEnabled;
}
