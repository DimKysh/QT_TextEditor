#ifndef _SINGLETON_CONFIG_HPP_
#define _SINGLETON_CONFIG_HPP_

#include <QDebug>

class GlobalConfig
{
public:
    static GlobalConfig & Instance();
    void TouchSingleton() const;
private:
    GlobalConfig();
   ~GlobalConfig();
    GlobalConfig(const GlobalConfig &);
    GlobalConfig& operator = (const GlobalConfig & );
};



#endif // _SINGLETONE_CONFIG_HPP_
